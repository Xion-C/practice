#include "viewer.h"
#include "cgmath.h"

void write_pixel(int x, int y, color_t c) {
    /* Turn on the pixel found at x,y */
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_POINTS);
    glVertex3i(x, y, 0);
    glEnd();
}

void draw_zbuffer_pixel(int xi, int yi, float zbuf, color_t c) {
    int x_ = xi + biasx;
    int y_ = yi + biasy;
    if (xi + biasx > WIDTH || yi + biasy > HEIGHT || xi + biasx < 0 || yi + biasy < 0) {
        //printf("--- out of edge ---\n");
    }
    //else if ((camera_p.z - zbuf) < (camera_p.z - render.zbuffer[y_][x_])) {
    else if (zbuf < render.zbuffer[y_][x_]) {
        //write_pixel(xi, yi, c);
        render.frame[y_][x_] = c;
        render.zbuffer[y_][x_] = zbuf;
        //if(zbuf > 0) printf("draw x %d y %d z %f\n",xi,yi,zbuf);
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
            write_pixel(xi, yi, c);
        }
    }
    else if (y1 - y0 == 0) { //when line is vertical
        for (xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
            write_pixel(xi, yi, c);
        }
    }
    else {
        m = float(y1 - y0) / float(x1 - x0);
        b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
        if (m < 1. && m > -1.) { //when |m|<1
            for (xi = (x0 < x1 ? x0 : x1); xi <= (x0 < x1 ? x1 : x0); xi++) {
                py = m * float(xi) + b;
                yi = round(py);
                write_pixel(xi, yi, c);
            }
        }
        else { //when |m|>=1
            for (yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
                px = 1. / m * float(yi) - b / m;
                xi = round(px);
                write_pixel(xi, yi, c);
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

color_t triface_simplelight(const triface_t& f, const vector_t& light, const vector_t& view) {
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
    float kd = 0.4;
    float ks = 0.6;
    float selfilluminous = 0.15;

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

void triface_equation(triface_t& f_t) {
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

void triface_rasterization(const triface_t& f) {

    triface_t f_t = f;
    matrix_t p;
    matrix_set_perspective(p, objdata.center.z, camera_p);
    if (showperspective == 1) {
        matrix_multi_vector(f_t.v1, p, f.v1);
        matrix_multi_vector(f_t.v2, p, f.v2);
        matrix_multi_vector(f_t.v3, p, f.v3);
        vector_homogenate(f_t.v1);
        vector_homogenate(f_t.v2);
        vector_homogenate(f_t.v3);
    }

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
    int minx = round(fmin_3(x1, x2, x3));
    int maxx = round(fmax_3(x1, x2, x3));
    int miny = round(fmin_3(y1, y2, y3));
    int maxy = round(fmax_3(y1, y2, y3));
    float accuracy12 = fmax_2(fabs(dx12), fabs(dy12)) / 2 + 0.1;
    float accuracy23 = fmax_2(fabs(dx23), fabs(dy23)) / 2 + 0.1;
    float accuracy31 = fmax_2(fabs(dx31), fabs(dy31)) / 2 + 0.1;

    // constant part of half-edge functions
    float c1 = dy12 * x1 - dx12 * y1;
    float c2 = dy23 * x2 - dx23 * y2;
    float c3 = dy31 * x3 - dx31 * y3;
    float cy1 = c1 + dx12 * miny - dy12 * minx;
    float cy2 = c2 + dx23 * miny - dy23 * minx;
    float cy3 = c3 + dx31 * miny - dy31 * minx;

    float z = 0;
    triface_equation(f_t);

    color_t rgb;
    //rgb = triface_simplelight(f, light_parrallel);
    vector_t light;
    vector_t view;
    
    // Scan through bounding rectangle
    for (int y = miny; y < maxy; y++) {
        // Start value for horizontal scan
        float cx1 = cy1;
        float cx2 = cy2;
        float cx3 = cy3;
        for (int x = minx; x < maxx; x++) {
            if (cx1 > -accuracy12 && cx2 > -accuracy23 && cx3 > -accuracy31) {
                if ((int)round(!f.zn)) { //when f.n.zn is false
                                         //line
                    z = DEPTH;
                }
                else {
                    //plane
                    z = (-f_t.d - f_t.n.x * x - f_t.n.y * y) / f_t.n.z;
                }

                //if (z > 0) {
                //    printf("z %f, v1z %f, v2z %f, v3z %f\n", z, p1.z, p2.z, p3.z);
                //    system("pause");
                //}

                //write_pixel(x, y, f.color);
                //draw_zbuffer_pixel(x, y, z, f.color);

                //rgb = triface_simplelight(f, { (float)x, (float)y, (float)z/2, 1.0f });
                //vector_minus(lp, { float(x), float(y), float(z), 1.0f }, lightsource_p);
                vector_minus(light, lightsource_p, { float(x), float(y), float(z), 1.0f });
                vector_normalize(light);
                vector_minus(view, camera_p, { float(x), float(y), float(z), 1.0f });
                vector_normalize(view);
                rgb = triface_simplelight(f, light, view);
                draw_zbuffer_pixel(x, y, z, rgb);
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
            render.frame[i][j] = { 0.0f,0.0f,0.0f };
        }
    }
}

void vertices_init() {
    float x, y, z;
    float minx, miny, minz, maxx, maxy, maxz;
    float rscale;
    vector_t v;
    minx = miny = minz = maxx = maxy = maxz = 0;
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
    rscale = 0.5 * WIDTH / (maxx - minx);
    v.x = maxx - minx;
    v.y = maxy - miny;
    v.z = maxz - minz;
    //get average
    objdata.center.x = x / objdata.vertices.size();
    objdata.center.y = y / objdata.vertices.size();
    objdata.center.z = z / objdata.vertices.size();
    vertices_translation(-objdata.center.x, -objdata.center.y, -objdata.center.z);
    vertices_scale(rscale, rscale, rscale);
    objdata.maxsize = vector_magnitude(v) * rscale;
    vertices_translation(0, 0, DEPTH / 2);
    //printf("center -- %f %f %f\n", objdata.center.x, objdata.center.y, objdata.center.z);

    lightsource_p.z = objdata.center.z;
}

void vertices_transform(const matrix_t& m) {
    for (unsigned int i = 0; i < (objdata.vertices.size()); i++) {
        matrix_multi_vector(objdata.vertices[i], m, objdata.vertices[i]);
        // printf("i-%d, x %f, y %f, z %f, w %f\n", i, objdata.vertices[i].x, objdata.vertices[i].y, objdata.vertices[i].z, objdata.vertices[i].w);
    }
    faces_init();
}
void vertices_translation(const float& x, const float& y, const float& z) {
    matrix_t t;
    matrix_set_translation(t, x, y, z);
    vertices_transform(t);
    center_translation(x, y, z);
}
void vertices_rotation_x(const float& theta) {
    matrix_t m, t1, t2, r;
    matrix_set_translation(t1, -objdata.center.x, -objdata.center.y, -objdata.center.z);
    matrix_set_rotation_x(r, theta);
    matrix_set_translation(t2, objdata.center.x, objdata.center.y, objdata.center.z);
    matrix_mul(m, t2, r);
    matrix_mul(m, m, t1);
    vertices_transform(m);
}
void vertices_rotation_y(const float& theta) {
    matrix_t m, t1, t2, r;
    matrix_set_translation(t1, -objdata.center.x, -objdata.center.y, -objdata.center.z);
    matrix_set_rotation_y(r, theta);
    matrix_set_translation(t2, objdata.center.x, objdata.center.y, objdata.center.z);
    matrix_mul(m, t2, r);
    matrix_mul(m, m, t1);
    vertices_transform(m);
}
void vertices_rotation_z(const float& theta) {
    matrix_t m, t1, t2, r;
    matrix_set_translation(t1, -objdata.center.x, -objdata.center.y, -objdata.center.z);
    matrix_set_rotation_z(r, theta);
    matrix_set_translation(t2, objdata.center.x, objdata.center.y, objdata.center.z);
    matrix_mul(m, t2, r);
    matrix_mul(m, m, t1);
    vertices_transform(m);
}
void vertices_scale(const float& x, const float& y, const float& z) {
    matrix_t m, t1, t2, s;
    matrix_set_translation(t1, -objdata.center.x, -objdata.center.y, -objdata.center.z);
    matrix_set_scale(s, x, y, z);
    matrix_set_translation(t2, objdata.center.x, objdata.center.y, objdata.center.z);
    matrix_mul(m, t2, s);
    matrix_mul(m, m, t1);
    vertices_transform(m);
}
void faces_init() {
    if (!objdata.faces.empty())  objdata.faces.clear();
    for (unsigned int i = 0; i < (objdata.vertex_indices.size()); i++) {
        face.v1 = objdata.vertices[objdata.vertex_indices[i].vi1 - 1];
        face.v2 = objdata.vertices[objdata.vertex_indices[i].vi2 - 1];
        face.v3 = objdata.vertices[objdata.vertex_indices[i].vi3 - 1];
        face.sgroup = objdata.vertex_indices[i].sgroup;
        face.color = objdata.colors[face.sgroup - 1];
        //printf("face %d color %f %f %f\n", i, face.color.r, face.color.g, face.color.b);

        //compute normal vector_t
        float x1 = face.v1.x;
        float x2 = face.v2.x;
        float x3 = face.v3.x;
        float y1 = face.v1.y;
        float y2 = face.v2.y;
        float y3 = face.v3.y;
        float z1 = face.v1.z;
        float z2 = face.v2.z;
        float z3 = face.v3.z;
        float dx12 = x1 - x2;
        float dy12 = y1 - y2;
        float dz12 = z1 - z2;
        float dx23 = x2 - x3;
        float dy23 = y2 - y3;
        float dz23 = z2 - z3;

        vector_t d12 = { dx12, dy12, dz12, 1.0f };
        vector_t d23 = { dx23, dy23, dz23, 1.0f };
        vector_crossproduct(face.n, d12, d23);

        //face.n.x = dy12 * dz23 - dz12 * dy23;
        //face.n.y = dz12 * dx23 - dx12 * dz23;
        //face.n.z = dx12 * dy23 - dy12 * dx23;
        //face.n.w = 1.0f;


        vector_normalize(face.n);
        // printf("%d - normal %f %f %f\n", i,face.n.x,face.n.y,face.n.z);
        if (fabs(face.n.z) < LIMIT_ZERO) {
            face.zn = false;
        }
        else {
            face.zn = true;
        }
        face.d = -(face.n.x * face.v1.x + face.n.y * face.v1.y + face.n.z * face.v1.z);

        objdata.faces.push_back(face);
    }
}
void center_translation(const float x, const float y, const float z) {
    objdata.center.x += x;
    objdata.center.y += y;
    objdata.center.z += z;
}

void obj_loader(const char *path) {
    FILE * objfile = fopen(path, "r");
    if (objfile == NULL) {
        printf(".obj file open failed!\n");
        exit(-1);
    }
    objdata.nsmooth = 0;
    while (1) {
        char text[64]; //save current reading text
        if (fscanf(objfile, "%s", text) == EOF)  break;
        if (strcmp(text, "v") == 0) {
            fscanf(objfile, "%f %f %f\n", &(vertex.x), &(vertex.y), &(vertex.z));
            vertex.w = 1.0f;
            objdata.vertices.push_back(vertex);
            printf("vertex: %f  %f  %f  %f\n", vertex.x, vertex.y, vertex.z, vertex.w);
        }
        int sgroup_temp;
        if (strcmp(text, "s") == 0) {
            fscanf(objfile, "%d\n", &sgroup_temp);
            color_random(color);
            objdata.colors.push_back(color);
            objdata.nsmooth++;
        }
        int temp;
        if (strcmp(text, "f") == 0) {
            fscanf(objfile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &(vi.vi1), &temp, &temp, &(vi.vi2), &temp, &temp, &(vi.vi3), &temp, &temp);
            vi.sgroup = sgroup_temp;
            objdata.vertex_indices.push_back(vi);
            printf("face: %d %d %d - %d\n", vi.vi1, vi.vi2, vi.vi3, vi.sgroup);
        }
    }

    vertices_init();
}
void view_obj() {
    render_init();

    triface_t f;
    point_t v1, v2, v3;
    matrix_t p;
    //matrix_set_perspective(p, objdata.center.z, camera_p);
    for (unsigned int i = 0; i<objdata.faces.size(); i++) {
        f = objdata.faces[i];
        if (showperspective == 1) {
            matrix_multi_vector(f.v1, p, f.v1);
            matrix_multi_vector(f.v2, p, f.v2);
            matrix_multi_vector(f.v3, p, f.v3);
            vector_homogenate(f.v1);
            vector_homogenate(f.v2);
            vector_homogenate(f.v3);
        }
        v1 = f.v1;
        v2 = f.v2;
        v3 = f.v3;
        if (showframe == 0) {
            //triface_rasterization(f);
            triface_rasterization(objdata.faces[i]);
            //draw_triface(objdata.faces[i]);
        }
        else {
            draw_line(f.v1, f.v2, white);
            draw_line(f.v2, f.v3, white);
            draw_line(f.v1, f.v3, white);
        }
    }

    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            //write_pixel(lx+j, ly+i, white);
            render.frame[(int)lightsource_p.y + i + biasy][(int)lightsource_p.x + j + biasx] = white;
        }
    }


    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            write_pixel(j - biasx, i - biasy, render.frame[i][j]);
        }
    }


    //printf("------- frame updated -------\n");
}
