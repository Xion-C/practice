#include "viewer.h"
#include "cgmath.h"
#include "transform.h"
#include "loader.h"

void write_pixel(int x, int y, color_t c) {
    /* Turn on the pixel found at x,y */
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_POINTS);
    glVertex3i(x, y, 0);
    glEnd();
}

int frame_set(color_t frame[HEIGHT][WIDTH], int x, int y, color_t color) {
    int x_ = x + biasx;
    int y_ = y + biasy;
    if (x_ > WIDTH || y_ > HEIGHT || x_ < 0 || y_ < 0) {
        return 0;
    }
    else {
        frame[y_][x_] = color;
        return 1;
    }
}

int frame_set(color_t frame[HEIGHT][WIDTH], float zbuffer[HEIGHT][WIDTH], int x, int y, color_t color, float zbuf) {
    int x_ = x + biasx;
    int y_ = y + biasy;
    if (x_ > WIDTH || y_ > HEIGHT || x_ < 0 || y_ < 0) {
    }
    else if (zbuffer_set(zbuffer, x, y, zbuf)) {
        frame[y_][x_] = color;
        return 1;
    }
    else {
        return 0;
    }
}

//int zbuffer_set(float zbuffer[HEIGHT][WIDTH], int x, int y, float zbuf) {
//    int x_ = x + biasx;
//    int y_ = y + biasy;
//
//    if (x_ > WIDTH || y_ > HEIGHT || x_ < 0 || y_ < 0) {
//        return 0;
//    }
//    else if (zbuf < zbuffer[y_][x_]) {
//        if (zbuffer[y_][x_] > render.zbuffer_last[y_][x_] && zbuffer[y_][x_] < DEPTH - 1) {
//            render.zbuffer_last[y_][x_] = zbuffer[y_][x_];
//            //printf("zbuf : %f %f\n", zbuffer[y_][x_], render.zbuffer_last[y_][x_]);
//        }
//        //printf("zbuf : %f %f\n", zbuffer[y_][x_], zbuf);
//        zbuffer[y_][x_] = zbuf;
//        return 1;
//    }
//    else if (zbuf > zbuffer[y_][x_]) {
//        if (zbuf > render.zbuffer_last[y_][x_]) {
//            if (fequ(zbuf, DEPTH)) {
//                printf("zbuf : %f %f\n", zbuf, render.zbuffer_last[y_][x_]);
//            }
//            //printf("zbuf : %f %f\n", zbuf, render.zbuffer_last[y_][x_]);
//            render.zbuffer_last[y_][x_] = zbuf;
//        }
//        return 0;
//    }
//}

int zbuffer_set(float zbuffer[HEIGHT][WIDTH], int x, int y, float zbuf) {
    int x_ = x + biasx;
    int y_ = y + biasy;

    if (x_ > WIDTH || y_ > HEIGHT || x_ < 0 || y_ < 0) {
        return 0;
    }
    else if (zbuf > zbuffer[y_][x_]) {
        if (zbuffer[y_][x_] < render.zbuffer_last[y_][x_] && zbuffer[y_][x_] > DEPTH + 1) {
            render.zbuffer_last[y_][x_] = zbuffer[y_][x_];
            //printf("zbuf : %f %f\n", zbuffer[y_][x_], render.zbuffer_last[y_][x_]);
        }
        //printf("zbuf : %f %f\n", zbuffer[y_][x_], zbuf);
        zbuffer[y_][x_] = zbuf;
        return 1;
    }
    else if (zbuf < zbuffer[y_][x_]) {
        if (zbuf < render.zbuffer_last[y_][x_]) {
            if (fequ(zbuf, DEPTH)) {
                //printf("zbuf : %f %f\n", zbuf, render.zbuffer_last[y_][x_]);
            }
            //printf("zbuf : %f %f\n", zbuf, render.zbuffer_last[y_][x_]);
            render.zbuffer_last[y_][x_] = zbuf;
        }
        return 0;
    }
}


void draw_line(point_t p1, point_t p2, color_t c) //draw a line using dda algorithm
{
    float m, b;
    float px, py;
    int x0, x1, y0, y1;
    int xi, yi;
    x0 = round(p1.x);
    x1 = round(p2.x);
    y0 = round(p1.y);
    y1 = round(p2.y);
    if (x1 - x0 == 0) { //when line is horizontal
        for (xi = x0, yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
            //write_pixel(xi, yi, c);
            frame_set(render.frame, xi, yi, c);
        }
    }
    else if (y1 - y0 == 0) { //when line is vertical
        for (xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
            //write_pixel(xi, yi, c);
            frame_set(render.frame, xi, yi, c);
        }
    }
    else {
        m = float(y1 - y0) / float(x1 - x0);
        b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
        if (m < 1. && m > -1.) { //when |m|<1
            for (xi = (x0 < x1 ? x0 : x1); xi <= (x0 < x1 ? x1 : x0); xi++) {
                py = m * float(xi) + b;
                yi = round(py);
                //write_pixel(xi, yi, c);
                frame_set(render.frame, xi, yi, c);
            }
        }
        else { //when |m|>=1
            for (yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
                px = 1. / m * float(yi) - b / m;
                xi = round(px);
                //write_pixel(xi, yi, c);
                frame_set(render.frame, xi, yi, c);
            }
        }
    }
}

void color_random(color_t& c) {
    int r1, r2, r3;
    r1 = rand();
    r2 = rand();
    r3 = rand();
    c.r = (float)(r1 % 100) / 100.0f;
    c.g = (float)(r2 % 100) / 100.0f;
    c.b = (float)(r3 % 100) / 100.0f;
}
void color_white(color_t& c) {
    c.r = c.g = c.b = 1.0;
}

color_t shader_simplelight(const primitive_t& f, const vector_t& light, const vector_t& view) {
    point_t p1 = f.v1, p2 = f.v2, p3 = f.v3;

    color_t rgb;
    color_t material = { 0.99f, 0.55f, 0.25f };

    //vn,vi,vv,vr
    vector_t vn = f.n;
    vector_t vi = light;
    vector_t vv = view;
    vector_t vr;
    vector_t vtemp;
    vector_scalar(vtemp, 2 * vector_dotproduct(vi, vn), vn);
    vector_minus(vr, vi, vtemp);
    vector_normalize(vr);

    float gray, cr, cg, cb;
    float kd = 0.6;
    float ks = 0.4;
    float selfilluminous = 0.20;

    gray = kd * vector_dotproduct(vi, vn) + ks * -powf(vector_dotproduct(vv, vr), 1.0f);
    //printf("vv vr %f  %f   %f  %f\n", vv.x, vr.x, vector_dotproduct(vv, vr), powf(vector_dotproduct(vv, vr), 1.2f));
    if (sssflag) {
        gray += selfilluminous;
    }
    cr = gray / 2 + material.r;
    fsaturate(cr);
    cg = gray / 2 + material.g;
    fsaturate(cg);
    cb = gray / 2 + material.b;
    fsaturate(cb);
    //if (gray < 0.0f || gray > 1) printf("gray: %f\n", gray);

    rgb = { cr, cg, cb };
    return rgb;
}

void texture_uv2xy(int& x, int& y, const float& alpha, const float& beta, const primitive_t& f) {
    point_t tp1, tp2, tp3;
    vector_t tv12, tv13, tv1p;
    tp1.x = f.vt1.u * objdata.texw;
    tp1.y = f.vt1.v * objdata.texh;
    tp2.x = f.vt2.u * objdata.texw;
    tp2.y = f.vt2.v * objdata.texh;
    tp3.x = f.vt3.u * objdata.texw;
    tp3.y = f.vt3.v * objdata.texh;
    tp1.z = tp2.z = tp3.z = 0;
    tp1.w = tp2.w = tp3.w = 1.0f;
    vector_minus(tv12, tp2, tp1);
    vector_minus(tv13, tp3, tp1);
    x = int(tp1.x + alpha * tv12.x + beta * tv13.x);
    y = int(objdata.texh - (tp1.y + alpha * tv12.y + beta * tv13.y));
    x = saturate(x, 0, objdata.texw - 1);
    y = saturate(y, 0, objdata.texh - 1);
}

void normal_uv2xy(int& x, int& y, const float& alpha, const float& beta, const primitive_t& f) {
    point_t np1, np2, np3;
    vector_t nv12, nv13, nv1p;
    np1.x = f.vt1.u * objdata.norw;
    np1.y = f.vt1.v * objdata.norh;
    np2.x = f.vt2.u * objdata.norw;
    np2.y = f.vt2.v * objdata.norh;
    np3.x = f.vt3.u * objdata.norw;
    np3.y = f.vt3.v * objdata.norh;
    np1.z = np2.z = np3.z = 0;
    np1.w = np2.w = np3.w = 1.0f;
    vector_minus(nv12, np2, np1);
    vector_minus(nv13, np3, np1);
    x = int(np1.x + alpha * nv12.x + beta * nv13.x);
    y = int(objdata.norh - (np1.y + alpha * nv12.y + beta * nv13.y));
    x = saturate(x, 0, objdata.norw - 1);
    y = saturate(y, 0, objdata.norh - 1);
}


color_t fragment_shader(const light_t& light, const point_t& camera, const primitive_t& f, point_t p) {
    color_t res;
    vector_t L, V, N, R; //light vector, view vector, normal vector, reflect vector
    vector_minus(L, light.pos, p);
    vector_normalize(L);
    vector_minus(V, camera, p);
    vector_normalize(V);
    //get normal
    //rgb = shader_simplelight(f, light, view);

    float alpha, beta;
    alpha = beta = 0;
    triangle_getBarycentric(alpha, beta, f.v1, f.v2, f.v3, p.x, p.y); //get Barycentric coordinates alpha and beta
    alpha = alpha >= 2 ? 2 : (alpha < -1 ? -1 : alpha);
    beta = beta >= 2 ? 2 : (beta < -1 ? -1 : beta);

    color_t diffuse;
    int xtex, ytex;
    texture_uv2xy(xtex, ytex, alpha, beta, f);
    diffuse = objdata.texture[ytex][xtex];

    int xnor, ynor;
    normal_uv2xy(xnor, ynor, alpha, beta, f);
    N = objdata.normal[ytex][xtex];

    vector_t vtemp;
    vector_scalar(vtemp, 2 * vector_dotproduct(L, N), N);
    vector_minus(R, L, vtemp);
    vector_normalize(R);

    float kd, ks;

    /** phong model **/
    /* diffuse component */
    kd = vector_dotproduct(L, N);
    kd = saturate(kd, 0, 1);
    vector_t vdiffuse = color2vector(diffuse);
    //vector_t vdiffuse = color2vector(white);
    vector_mul(vdiffuse, vdiffuse, objdata.mspecular);
    vector_mul(vdiffuse, vdiffuse, render.light.diffuse);
    vector_scalar(vdiffuse, kd, vdiffuse);

    /* specular */
    vector_t vspecular;
    ks = vector_dotproduct(V, R);
    ks = saturate(ks, 0, 1);
    ks = pow(ks, objdata.shininess);
    vector_mul(vspecular, objdata.mspecular, render.light.specular);
    vector_scalar(vspecular, ks, vspecular);

    res.r = saturate(vdiffuse.x + vspecular.x, 0, 1);
    res.g = saturate(vdiffuse.y + vspecular.y, 0, 1);
    res.b = saturate(vdiffuse.z + vspecular.z, 0, 1);
    //res.r = vspecular.x;
    //res.g = vspecular.y;
    //res.b = vspecular.z;
    //res.r = vdiffuse.x;
    //res.g = vdiffuse.y;
    //res.b = vdiffuse.z;


    return res;
}

int primitive_printInfo(const primitive_t& f) {
    printf("face #%d info\n", f.nr);
    printf("-- v1: %f, %f, %f\n", f.v1.x, f.v1.y, f.v1.z);
    printf("-- v2: %f, %f, %f\n", f.v2.x, f.v2.y, f.v2.z);
    printf("-- v3: %f, %f, %f\n", f.v3.x, f.v3.y, f.v3.z);
    printf("-- n: %f, %f, %f\n", f.n.x, f.n.y, f.n.z);
    return f.nr;
}

void primitive_perspective(primitive_t& f) {
    if (showperspective == 1) {
        matrix_t p;
        matrix_set_perspective(p, objdata.center.z, render.camera);
        matrix_multi_vector(f.v1, p, f.v1);
        matrix_multi_vector(f.v2, p, f.v2);
        matrix_multi_vector(f.v3, p, f.v3);
        vector_homogenate(f.v1);
        vector_homogenate(f.v2);
        vector_homogenate(f.v3);
    }
}

void primitive_set_plane_paras(primitive_t& f_t) {
    float x1 = f_t.v1.x;
    float x2 = f_t.v2.x;
    float x3 = f_t.v3.x;
    float y1 = f_t.v1.y;
    float y2 = f_t.v2.y;
    float y3 = f_t.v3.y;
    float z1 = f_t.v1.z;
    float z2 = f_t.v2.z;
    float z3 = f_t.v3.z;
    float dx12 = x1 - x2;
    float dy12 = y1 - y2;
    float dz12 = z1 - z2;
    float dx23 = x2 - x3;
    float dy23 = y2 - y3;
    float dz23 = z2 - z3;

    vector_t d12 = { dx12, dy12, dz12, 1.0f };
    vector_t d23 = { dx23, dy23, dz23, 1.0f };
    vector_crossproduct(f_t.n, d12, d23);
    vector_normalize(f_t.n);
    // printf("%d - normal %f %f %f\n", i,f_t.n.x,f_t.n.y,f_t.n.z);
    if (fabs(f_t.n.z) < LIMIT_ZERO) {
        f_t.zn = false;
    }
    else {
        f_t.zn = true;
    }
    f_t.d = -(f_t.n.x * f_t.v1.x + f_t.n.y * f_t.v1.y + f_t.n.z * f_t.v1.z);
    //(-f_t.d - f_t.n.x * x - f_t.n.y * y) / f_t.n.z;
}

bool pixel_in_triangle(const primitive_t& f, int x, int y) {
    float u = 0;
    float v = 0;
    float xt, yt;
    int sum = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            xt = float(i) - 0.5;
            yt = float(j) - 0.5;
            triangle_getBarycentric(u, v, f.v1, f.v2, f.v3, xt, yt);
            if (u >= 0 &&  v >= 0 && (u + v) <= 1) {
                sum += 1;
            }
        }
    }
    if (sum >= 1) return true;
    else return false;
}

void primitive_rasterization(const primitive_t& f) {

    primitive_t f_t = f;
    primitive_perspective(f_t);
    f_t.v1.z = f.v1.z;
    f_t.v2.z = f.v2.z;
    f_t.v3.z = f.v3.z;

    point_t p1 = f_t.v1, p2 = f_t.v2, p3 = f_t.v3;
    //triangle_vertex_clockwise(p1, p2, p3);
    float y1 = p1.y;
    float y2 = p2.y;
    float y3 = p3.y;
    float x1 = p1.x;
    float x2 = p2.x;
    float x3 = p3.x;
    float dx12 = x1 - x2;
    float dx23 = x2 - x3;
    float dy12 = y1 - y2;
    float dy23 = y2 - y3;
    float dx31 = x3 - x1;
    float dy31 = y3 - y1;
    // Bounding rectangle
    int minx = floor(fmin_3(x1, x2, x3));
    int maxx = ceil(fmax_3(x1, x2, x3));
    int miny = floor(fmin_3(y1, y2, y3));
    int maxy = ceil(fmax_3(y1, y2, y3));
    float accuracy12 = fmax_2(fabs(dx12), fabs(dy12)) / 2 + 0.05;
    float accuracy23 = fmax_2(fabs(dx23), fabs(dy23)) / 2 + 0.05;
    float accuracy31 = fmax_2(fabs(dx31), fabs(dy31)) / 2 + 0.05;

    // constant part of half-edge functions
    float c1 = dy12 * x1 - dx12 * y1;
    float c2 = dy23 * x2 - dx23 * y2;
    float c3 = dy31 * x3 - dx31 * y3;
    float cy1 = c1 + dx12 * miny - dy12 * minx;
    float cy2 = c2 + dx23 * miny - dy23 * minx;
    float cy3 = c3 + dx31 * miny - dy31 * minx;

    float z = 0;
    primitive_set_plane_paras(f_t);

    color_t result;

    // Scan through bounding rectangle
    for (int y = miny; y < maxy; y++) {
        // Start value for horizontal scan
        float cx1 = cy1;
        float cx2 = cy2;
        float cx3 = cy3;
        for (int x = minx; x < maxx; x++) {

            /*if (cx1 > -accuracy12 && cx2 > -accuracy23 && cx3 > -accuracy31) {*/
            //if (cx1 >0 && cx2 > 0 && cx3 > 0) {
            //dv12 = dx12 * (y - y1) - dy12 * (x - x1);
            //dv23 = dx23 * (y - y2) - dy23 * (x - x2);
            //dv31 = dx31 * (y - y3) - dy31 * (x - x3);
            //if ( dv12> -accuracy12 && dv23 > -accuracy23 && dv31 > -accuracy31) {
            //if(pixel_in_triangle(f_t, x, y)) {
            if ((cx1 > -accuracy12 && cx2 > -accuracy23 && cx3 > -accuracy31) ||
                (cx1 < accuracy12 && cx2 < accuracy23 && cx3 < accuracy31)) {

                if (!f_t.zn) { //when f.n.zn is false, means it's a line
                    //z = fmin_3(f_t.v1.z, f_t.v2.z, f_t.v3.z);
                    float dx1p = x1 - (float)x;
                    float dy1p = y1 - (float)y;
                    float ratio = ((dx1p / dx12) + (dy1p / dy12)) / 2;
                    z = f_t.v1.z - ratio * (f_t.v1.z - f_t.v2.z);
                }
                else {
                    //plane
                    z = (-f_t.d - f_t.n.x * x - f_t.n.y * y) / f_t.n.z;
                }

                if (zbuffer_set(render.zbuffer,x,y,z)) {
                    float unpers = z / objdata.center.z; //undo perspective

                    //point_t p = {x * unpers, y * unpers, z, 1.0f};
                    //result = fragment_shader(render.light, render.camera, f, p);

                    point_t p = { x, y, z, 1.0f };
                    result = fragment_shader(render.light, render.camera, f_t, p);

                    //vector_minus(light, lightsource_p, { float(x), float(y), float(z), 1.0f });
                    //vector_normalize(light);
                    //vector_minus(view, camera_p, { float(x), float(y), float(z), 1.0f });
                    //vector_normalize(view);
                    //rgb = shader_simplelight(f, light, view);
                    frame_set(render.frame, x, y, result);
                    //frame_set(render.frame, x, y, f.color);
                }
            }
            cx1 -= dy12;
            cx2 -= dy23;
            cx3 -= dy31;
        }
        cy1 += dx12;
        cy2 += dx23;
        cy3 += dx31;
    }
}


void render_init() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            render.zbuffer[i][j] = DEPTH;
            render.zbuffer_last[i][j] = -DEPTH;
            render.frame[i][j] = { 0.0f,0.0f,0.0f };
        }
    }
}

void vertices_init() {
    float x, y, z;
    float minx, miny, minz, maxx, maxy, maxz;
    float rscale;
    vector_t v;
    minx = maxx = objdata.vertices[0].x;
    miny = maxy = objdata.vertices[0].y;
    minz = maxz = objdata.vertices[0].z;
    //minx = miny = minz = maxx = maxy = maxz = 0;
    x = y = z = 0;
    for (unsigned int i = 0; i < (objdata.vertices.size()); i++) {
        x += objdata.vertices[i].x;
        y += objdata.vertices[i].y;
        z += objdata.vertices[i].z;
        minx = objdata.vertices[i].x<minx ? objdata.vertices[i].x : minx;
        miny = objdata.vertices[i].y<miny ? objdata.vertices[i].y : miny;
        minz = objdata.vertices[i].z<minz ? objdata.vertices[i].z : minz;
        maxx = objdata.vertices[i].x>maxx ? objdata.vertices[i].x : maxx;
        maxy = objdata.vertices[i].y>maxy ? objdata.vertices[i].y : maxy;
        maxz = objdata.vertices[i].z>maxz ? objdata.vertices[i].z : maxz;
    }
    rscale = 1.2 * WIDTH / (maxx - minx);
    v.x = maxx - minx;
    v.y = maxy - miny;
    v.z = maxz - minz;
    //get the coordinates of center (compute average)
    objdata.center.x = x / objdata.vertices.size();
    objdata.center.y = y / objdata.vertices.size();
    objdata.center.z = z / objdata.vertices.size();

    //tanslate the object to the origin
    vertices_translation(-objdata.center.x, -objdata.center.y, -objdata.center.z);

    //scale the object to fit the screen space
    vertices_scale(rscale, rscale, rscale);

    //max size of the object
    objdata.maxsize = vector_magnitude(v) * rscale;

    //tranlate object along z axis
    vertices_translation(0, 0, DEPTH / 2);

    printf("bounding box -- %f %f %f\n", v.x, v.y, v.z);
    printf("init scale -- %f - %f %f %f\n", rscale, v.x * rscale, v.y * rscale, v.z * rscale);
    printf("center -- %f %f %f\n", objdata.center.x, objdata.center.y, objdata.center.z);
    printf("first vertex -- %f %f %f\n", objdata.vertices[0].x, objdata.vertices[0].y, objdata.vertices[0].z);

}

void primitives_init() {
    if (!objdata.faces.empty())  objdata.faces.clear();
    for (unsigned int i = 0; i < (objdata.vertex_indices.size()); i++) {
        face.v1 = objdata.vertices[objdata.vertex_indices[i].vi1 - 1];
        face.v2 = objdata.vertices[objdata.vertex_indices[i].vi2 - 1];
        face.v3 = objdata.vertices[objdata.vertex_indices[i].vi3 - 1];
        face.vt1 = objdata.vuvs[objdata.vertex_indices[i].uv1 - 1];
        face.vt2 = objdata.vuvs[objdata.vertex_indices[i].uv2 - 1];
        face.vt3 = objdata.vuvs[objdata.vertex_indices[i].uv3 - 1];
        face.sgroup = objdata.vertex_indices[i].sgroup;
        if(face.sgroup > 0)
            face.color = objdata.colors[face.sgroup - 1];
        face.nr = i + 1;
        //printf("face %d color %f %f %f\n", i, face.color.r, face.color.g, face.color.b);

        //calculate some parameters of 3D triangle
        primitive_set_plane_paras(face);

        objdata.faces.push_back(face);
    }
}

void view_obj() {
    render_init();
    primitive_t f;
    //matrix_t p;
    //matrix_set_perspective(p, objdata.center.z, camera_p);
    for (unsigned int i = 0; i<objdata.faces.size(); i++) {
        if (showframe == 0) {
            //primitive_printInfo(objdata.faces[i]);

            primitive_rasterization(objdata.faces[i]);
        }
        else {
            primitive_t f = objdata.faces[i];
            primitive_perspective(f);
            draw_line(f.v1, f.v2, white);
            draw_line(f.v2, f.v3, white);
            draw_line(f.v1, f.v3, white);
        }
    }

    if (lightflag) {
        //light position
        for (int i = -3; i <= 3; i++) {
            for (int j = -3; j <= 3; j++) {
                //write_pixel(lx+j, ly+i, white);
                render.frame[(int)render.light.pos.y + i + biasy][(int)render.light.pos.x + j + biasx] = white;
            }
        }
    }

    if (sssflag) {
        //color_t frame_temp[HEIGHT][WIDTH];
        generateGaussianTemplate(W_SIZE, 1.92);
        //printf("gaussian %f %f %f\n", w[0][0], w[0][1], w[0][2]);
        gaussian_filter(W_SIZE);
    }

    if (sssflag2) {
        gaussian6pass(11);
    }

    float dmax = 0;
    float dmin = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((!fequ(render.zbuffer_last[i][j], -DEPTH)) && (!fequ(render.zbuffer[i][j], DEPTH))) {
                render.depth[i][j] = render.zbuffer[i][j] - render.zbuffer_last[i][j];
                dmax = render.depth[i][j] > dmax ? render.depth[i][j] : dmax;
                dmin = render.depth[i][j] < dmin ? render.depth[i][j] : dmin;
            }
            else {
                render.depth[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (fequ(render.depth[i][j], 0)) {
                render.depth[i][j] = 1.0f;
            }
            else {
                render.depth[i][j] = sqrt(saturate((render.depth[i][j] - dmin) / (dmax - dmin)*1.2, 0, 1));
            }
            //render.frame[i][j] = { render.depth[i][j],render.depth[i][j],render.depth[i][j] };
            if (addflag && render.depth[i][j] < 0.8) {
                render.frame[i][j].r = saturate(render.frame[i][j].r + pow((1 - render.depth[i][j]),15)*0.25, 0, 1);
                render.frame[i][j].g = saturate(render.frame[i][j].g + pow((1 - render.depth[i][j]),10)*0.08, 0, 1);
                render.frame[i][j].b = saturate(render.frame[i][j].b + pow((1 - render.depth[i][j]),10)*0.05, 0, 1);

            }
        }
    }


    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            write_pixel(j - biasx, i - biasy, render.frame[i][j]);
            //write_pixel(j - biasx, i - biasy, fbuffer.f1[i][j]);
        }
    }


    if (clickflag) {
        printf("zbuf: %f, zbuf_last: %f\n", render.zbuffer[y_last + biasy][x_last + biasx], render.zbuffer_last[y_last + biasy][x_last + biasx]);
        clickflag = 0;
    }

    if (saveflag) {
        write_frame(render.frame);
        saveflag = 0;
    }

    //printf("------- frame updated -------\n");
}

void generateGaussianTemplate(int ksize, double sigma)
{
    static const double pi = 3.1415926;
    int center = ksize / 2; // center of the filter
    double x2, y2;
    double sum = 0;
    for (int i = 0; i < ksize; i++)
    {
        x2 = pow(i - center, 2);
        for (int j = 0; j < ksize; j++)
        {
            y2 = pow(j - center, 2);
            double g = exp(-(x2 + y2) / (2 * sigma * sigma));
            g /= 2 * pi * sigma;
            sum += g;
            fbuffer.window[i][j] = g;
        }
    }
    //double k = 1 / window[0][0]; // make the edge equal to 1
    for (int i = 0; i < ksize; i++)
    {
        for (int j = 0; j < ksize; j++)
        {
            fbuffer.window[i][j] /= sum;
        }
    }
}

void generateGaussianTemplate(float** filter, int ksize, double sigma) {
    static const double pi = 3.1415926;
    int center = ksize / 2; // center of the filter
    double x2, y2;
    double sum = 0;
    for (int i = 0; i < ksize; i++)
    {
        x2 = pow(i - center, 2);
        for (int j = 0; j < ksize; j++)
        {
            y2 = pow(j - center, 2);
            double g = exp(-(x2 + y2) / (2 * sigma * sigma));
            g /= 2 * pi * sigma;
            sum += g;
            filter[i][j] = g;
        }
    }
    //double k = 1 / window[0][0]; // make the edge equal to 1
    for (int i = 0; i < ksize; i++)
    {
        for (int j = 0; j < ksize; j++)
        {
            filter[i][j] /= sum;
        }
    }
}

void gaussian_filter(int ksize) 
{
    //filter size
    int b = ksize / 2;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fbuffer.f1[i][j] = { 0.0f,0.0f,0.0f };
        }
    }
    //render.frame;
    for (int i = b; i < HEIGHT - b; i++) {
        for (int j = b; j < WIDTH - b; j++) {
            //start calculateing
            if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f|| render.frame[i][j].b > 0.00001f) {
                for (int m = -b; m <= b; m++) {
                    for (int n = -b; n <= b; n++) {
                        fbuffer.f1[i][j].r += render.frame[i + m][j + n].r * fbuffer.window[m+b][n+b];
                        fbuffer.f1[i][j].g += render.frame[i + m][j + n].g * fbuffer.window[m+b][n+b];
                        fbuffer.f1[i][j].b += render.frame[i + m][j + n].b * fbuffer.window[m+b][n+b];
                        //fbuffer.f1[i][j].r += render.frame[i + m][j + n].r * 1.0f / 25.0f;
                        //fbuffer.f1[i][j].g += render.frame[i + m][j + n].g * 1.0f / 25.0f;
                        //fbuffer.f1[i][j].b += render.frame[i + m][j + n].b * 1.0f / 25.0f;
                        fbuffer.f1[i][j].r = saturate(1.001 * fbuffer.f1[i][j].r,0, 1);
                        fbuffer.f1[i][j].g = saturate(1.0 * fbuffer.f1[i][j].g, 0, 1);
                        fbuffer.f1[i][j].b = saturate(0.999 * fbuffer.f1[i][j].b, 0, 1);
                        //fbuffer.f1[i][j].r = 1.01 * fbuffer.f1[i][j].r;
                        //fbuffer.f1[i][j].g = 1.0 * fbuffer.f1[i][j].g;
                        //fbuffer.f1[i][j].b = 1.0 * fbuffer.f1[i][j].b;
                    }
                }
            }
        }
    }

    float c1 = 0.6;
    float c2 = 0.4;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (fequ(fbuffer.f1[i][j].r, 0) && fequ(fbuffer.f1[i][j].g, 0) && fequ(fbuffer.f1[i][j].b, 0)) {
                fbuffer.f1[i][j] = render.frame[i][j];
            }
            render.frame[i][j] = fbuffer.f1[i][j];
        }
    }
}

void gaussian6pass(int ksize) {
    float **g1;
    float **g2;
    float **g3;
    float **g4;
    float **g5;
    float **g6;
    float **gr;
    float **gg;
    float **gb;
    g1 = new float*[ksize];
    g2 = new float*[ksize];
    g3 = new float*[ksize];
    g4 = new float*[ksize];
    g5 = new float*[ksize];
    g6 = new float*[ksize];
    gr = new float*[ksize];
    gg = new float*[ksize];
    gb = new float*[ksize];
    for (int i = 0; i < ksize; i++) {
        g1[i] = new float[ksize];
        g2[i] = new float[ksize];
        g3[i] = new float[ksize];
        g4[i] = new float[ksize];
        g5[i] = new float[ksize];
        g6[i] = new float[ksize];
        gr[i] = new float[ksize];
        gg[i] = new float[ksize];
        gb[i] = new float[ksize];
    }
    generateGaussianTemplate(g1, ksize, 0.0064);
    generateGaussianTemplate(g2, ksize, 0.0484);
    generateGaussianTemplate(g3, ksize, 0.187);
    generateGaussianTemplate(g4, ksize, 0.567);
    generateGaussianTemplate(g5, ksize, 1.99);
    generateGaussianTemplate(g6, ksize, 7.41);

    for (int i = 0; i < ksize; i++) {
        for (int j = 0; j < ksize; j++) {
            gr[i][j] = 0.233*g1[i][j] + 0.100*g2[i][j] + 0.118*g3[i][j] + 0.113*g4[i][j] + 0.358*g5[i][j] + 0.078*g6[i][j];
            gg[i][j] = 0.455*g1[i][j] + 0.336*g2[i][j] + 0.198*g3[i][j] + 0.007*g4[i][j] + 0.004*g5[i][j];
            gb[i][j] = 0.649*g1[i][j] + 0.344*g2[i][j] + 0.007*g4[i][j];
        }
    }

    int b = ksize / 2;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fbuffer.f2[i][j] = { 0.0f,0.0f,0.0f };
            fbuffer.f3[i][j] = { 0.0f,0.0f,0.0f };
            fbuffer.f4[i][j] = { 0.0f,0.0f,0.0f };
            fbuffer.f5[i][j] = { 0.0f,0.0f,0.0f };
            fbuffer.f6[i][j] = { 0.0f,0.0f,0.0f };
            fbuffer.f7[i][j] = { 0.0f,0.0f,0.0f };
        }
    }
    //render.frame;
    for (int i = b; i < HEIGHT - b; i++) {
        for (int j = b; j < WIDTH - b; j++) {
            //start calculateing
            if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
                for (int m = -b; m <= b; m++) {
                    for (int n = -b; n <= b; n++) {
                        fbuffer.f2[i][j].r += render.frame[i + m][j + n].r * gr[m + b][n + b];
                        fbuffer.f2[i][j].g += render.frame[i + m][j + n].g * gg[m + b][n + b];
                        fbuffer.f2[i][j].b += render.frame[i + m][j + n].b * gb[m + b][n + b];
                    }
                }
            }
        }
    }

    //for (int i = b; i < HEIGHT - b; i++) {
    //    for (int j = b; j < WIDTH - b; j++) {
    //        //start calculateing
    //        if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
    //            for (int m = -b; m <= b; m++) {
    //                for (int n = -b; n <= b; n++) {
    //                    fbuffer.f2[i][j].r += render.frame[i + m][j + n].r * g1[m + b][n + b] * 0.233;
    //                    fbuffer.f2[i][j].g += render.frame[i + m][j + n].g * g1[m + b][n + b] * 0.455;
    //                    fbuffer.f2[i][j].b += render.frame[i + m][j + n].b * g1[m + b][n + b] * 0.649;
    //                }
    //            }
    //        }
    //    }
    //}
    //for (int i = b; i < HEIGHT - b; i++) {
    //    for (int j = b; j < WIDTH - b; j++) {
    //        //start calculateing
    //        if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
    //            for (int m = -b; m <= b; m++) {
    //                for (int n = -b; n <= b; n++) {
    //                    fbuffer.f3[i][j].r += fbuffer.f2[i + m][j + n].r * g2[m + b][n + b] * 0.100;
    //                    fbuffer.f3[i][j].g += fbuffer.f2[i + m][j + n].g * g2[m + b][n + b] * 0.336;
    //                    fbuffer.f3[i][j].b += fbuffer.f2[i + m][j + n].b * g2[m + b][n + b] * 0.344;
    //                }
    //            }
    //        }
    //    }
    //}
    //for (int i = b; i < HEIGHT - b; i++) {
    //    for (int j = b; j < WIDTH - b; j++) {
    //        //start calculateing
    //        if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
    //            for (int m = -b; m <= b; m++) {
    //                for (int n = -b; n <= b; n++) {
    //                    fbuffer.f4[i][j].r += fbuffer.f3[i + m][j + n].r * g3[m + b][n + b] * 0.118;
    //                    fbuffer.f4[i][j].g += fbuffer.f3[i + m][j + n].g * g3[m + b][n + b] * 0.198;
    //                    fbuffer.f4[i][j].b += fbuffer.f3[i + m][j + n].b * g3[m + b][n + b] * 0.0;
    //                }
    //            }
    //        }
    //    }
    //}

    //for (int i = b; i < HEIGHT - b; i++) {
    //    for (int j = b; j < WIDTH - b; j++) {
    //        //start calculateing
    //        if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
    //            for (int m = -b; m <= b; m++) {
    //                for (int n = -b; n <= b; n++) {
    //                    fbuffer.f5[i][j].r += fbuffer.f4[i + m][j + n].r * g4[m + b][n + b] * 0.113;
    //                    fbuffer.f5[i][j].g += fbuffer.f4[i + m][j + n].g * g4[m + b][n + b] * 0.007;
    //                    fbuffer.f5[i][j].b += fbuffer.f4[i + m][j + n].b * g4[m + b][n + b] * 0.007;
    //                }
    //            }
    //        }
    //    }
    //}
    //for (int i = b; i < HEIGHT - b; i++) {
    //    for (int j = b; j < WIDTH - b; j++) {
    //        //start calculateing
    //        if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
    //            for (int m = -b; m <= b; m++) {
    //                for (int n = -b; n <= b; n++) {
    //                    fbuffer.f6[i][j].r += fbuffer.f5[i + m][j + n].r * g5[m + b][n + b] * 0.358;
    //                    fbuffer.f6[i][j].g += fbuffer.f5[i + m][j + n].g * g5[m + b][n + b] * 0.004;
    //                    fbuffer.f6[i][j].b += fbuffer.f5[i + m][j + n].b * g5[m + b][n + b] * 0.0;
    //                }
    //            }
    //        }
    //    }
    //}
    //for (int i = b; i < HEIGHT - b; i++) {
    //    for (int j = b; j < WIDTH - b; j++) {
    //        //start calculateing
    //        if (render.frame[i][j].r > 0.00001f || render.frame[i][j].g > 0.00001f || render.frame[i][j].b > 0.00001f) {
    //            for (int m = -b; m <= b; m++) {
    //                for (int n = -b; n <= b; n++) {
    //                    fbuffer.f7[i][j].r += fbuffer.f6[i + m][j + n].r * g6[m + b][n + b] * 0.078;
    //                    fbuffer.f7[i][j].g += fbuffer.f6[i + m][j + n].g * g6[m + b][n + b] * 0.0;
    //                    fbuffer.f7[i][j].b += fbuffer.f6[i + m][j + n].b * g6[m + b][n + b] * 0.0;
    //                }
    //            }
    //        }
    //    }
    //}


    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            render.frame[i][j] = fbuffer.f2[i][j];
            //render.frame[i][j] = fbuffer.f7[i][j];
        }
    }
    printf("gaussian 6 passes done\n");

}