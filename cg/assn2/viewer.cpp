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
    if (xi + biasx > WIDTH || yi + biasy > HEIGHT || xi + biasx < 0 || yi + biasy < 0) {
        printf("--- zbuffer error---\n");
    }
    if (fabs(render.zbuffer[xi + biasx][yi + biasy] - DEPTH) < 0.01) {
        write_pixel(xi, yi, c);
        printf("write x %d y %d z %f\n",xi,yi,zbuf);
    }
    else if (zbuf >= render.zbuffer[xi + biasx][yi + biasy]) {
        write_pixel(xi, yi, c);
        render.zbuffer[xi + biasx][yi + biasy] = zbuf;
        printf("draw x %d y %d z %f\n",xi,yi,zbuf);
    }
    //write_pixel(xi, yi, c);
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

void triface_rasterization(const triface_t& f) {
    point_t p1 = f.v1, p2 = f.v2, p3 = f.v3;
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
    float accuracy12 = fmax_2(fabs(dx12), fabs(dy12));
    float accuracy23 = fmax_2(fabs(dx23), fabs(dy23));
    float accuracy31 = fmax_2(fabs(dx31), fabs(dy31));

    // constant part of half-edge functions
    float c1 = dy12 * x1 - dx12 * y1;
    float c2 = dy23 * x2 - dx23 * y2;
    float c3 = dy31 * x3 - dx31 * y3;
    float cy1 = c1 + dx12 * miny - dy12 * minx;
    float cy2 = c2 + dx23 * miny - dy23 * minx;
    float cy3 = c3 + dx31 * miny - dy31 * minx;

    float z = 0;
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
                    z = (-f.d - f.n.x * x - f.n.y * y) / f.n.z;
                }
                //write_pixel(x, y, f.color);
                draw_zbuffer_pixel(x, y, z, f.color);
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

void draw_triface(const triface_t& f) {
    int x0, y0, x1, y1, vx, vy;
    float m, b;
    int xi, yi;
    point_t p1, p2;
    x0 = round(f.v1.x);
    y0 = round(f.v1.y);
    x1 = round(f.v2.x);
    y1 = round(f.v2.y);
    vx = round(f.v3.x);
    vy = round(f.v3.y);
    p1.x = vx;
    p1.y = vy;

    if (x1 - x0 == 0) { //when line is horizontal
        for (xi = x0, yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
            p2.x = xi;
            p2.y = yi;
            draw_line(p1, p2, f.color);
        }
    }
    else if (y1 - y0 == 0) { //when line is vertical
        for (xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
            p2.x = xi;
            p2.y = yi;
            draw_line(p1, p2, f.color);
        }
    }
    else {
        m = float(y1 - y0) / float(x1 - x0);
        b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
        if (m < 1. && m > -1.) { //when |m|<1
            for (xi = (x0 < x1 ? x0 : x1); xi <= (x0 < x1 ? x1 : x0); xi++) {
                yi = int(round(m * float(xi) + b));
                p2.x = xi;
                p2.y = yi;
                draw_line(p1, p2, f.color);
            }
        }
        else { //when |m|>=1
            for (yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
                xi = int(round(1. / m * float(yi) - b / m));
                p2.x = xi;
                p2.y = yi;
                draw_line(p1, p2, f.color);
            }
        }
    }
}

void render_init() {
    for (int i = 0; i<HEIGHT; i++) {
        for (int j = 0; j<WIDTH; j++) {
            render.zbuffer[i][j] = DEPTH;
            render.frame[i][j] = 0;
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
        face.n.x = dy12 * dz23 - dz12 * dy23;
        face.n.y = dz12 * dx23 - dx12 * dz23;
        face.n.z = dx12 * dy23 - dy12 * dx23;
        face.n.w = 1.0f;
        if (fabs(face.n.z) < LIMIT_ZERO) {
            face.zn = false;
        }
        else {
            face.zn = true;
        }
        face.d = -(face.n.x * face.v1.x + face.n.y * face.v1.y * face.n.z * face.v1.z);

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
    matrix_set_perspective(p, objdata.center.z);
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
            triface_rasterization(f);
            //draw_triface(objdata.faces[i]);
        }
        else {
            draw_line(f.v1, f.v2, white);
            draw_line(f.v2, f.v3, white);
            draw_line(f.v1, f.v3, white);
        }
    }
    //getchar();

    //printf("------- frame updated -------\n");
}
