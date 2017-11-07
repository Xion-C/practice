#include "viewer.h"

void write_pixel(int x, int y, color_t c) {
    /* Turn on the pixel found at x,y */
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_POINTS);
    glVertex3i(x, y, 0);
    glEnd();
}

void color_random(color_t& c) {
    int r1, r2, r3;
    r1 = rand();
    r2 = rand();
    r3 = rand();
    c.r = (float)(r1 % 255) / 255.0f;
    c.g = (float)(r2 % 255) / 255.0f;
    c.b = (float)(r3 % 255) / 255.0f;
}
void color_white(color_t& c) {
    c.r = c.g = c.b = 1.0;
}

void obj_loader(const char *path) {
    FILE * objfile = fopen(path, "r");
    if (objfile == NULL) {
        printf(".obj file open failed!\n");
        exit(-1);
    }
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
        }
        int temp;
        if (strcmp(text, "f") == 0) {
            fscanf(objfile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &(vi.vi1), &temp, &temp, &(vi.vi2), &temp, &temp, &(vi.vi3), &temp, &temp);
            vi.sgroup = sgroup_temp;
            objdata.vertex_indices.push_back(vi);
            printf("face: %d %d %d %d\n", vi.vi1, vi.vi2, vi.vi3, vi.sgroup);
        }
    }

    vertices_init();

    // for (unsigned int i = 0; i < (objdata.faces.size()); i++) {
    //     printf("x %f\n", objdata.faces[i].v1.x);
    //     printf("r %f g %f b %f\n", objdata.faces[i].color.r, objdata.faces[i].color.g, objdata.faces[i].color.b);
    // }
}

float line3d_getz(const point_t p1, const point_t p2, float x, float y) {
    float dxy, dpxy;
    dpxy = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    dxy = sqrt((x - p1.x)*(x - p1.x) + (y - p1.y)*(y - p1.y));
    if (dpxy > 0.5)  return p1.z + (p2.z - p1.z)*dxy / dpxy;
    else  return  p2.z<p1.z ? p2.z : p1.z;
}

void draw_zbuffer_pixel(point_t p1, point_t p2, float px, float py, color_t c) {
    float zbuf;
    int xi, yi;
    xi = round(px);
    yi = round(py);
    zbuf = line3d_getz(p1, p2, px, py);
    if (zbuf<render.zbuffer[xi + biasx][yi + biasy]) {
        write_pixel(xi, yi, c);
        render.zbuffer[xi + biasx][yi + biasy] = zbuf;
        //printf("draw x %d y %d c %f\n",xi,yi,c.r);
    }
    //write_pixel(xi, yi, c);
}

void draw_scanline(point_t p1, point_t p2, color_t c) //draw a line using dda algorithm
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
            px = xi;
            py = yi;
            draw_zbuffer_pixel(p1, p2, px, py, c);
        }
    }
    else if (y1 - y0 == 0) { //when line is vertical
        for (xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
            px = xi;
            py = yi;
            draw_zbuffer_pixel(p1, p2, px, py, c);
        }
    }
    else {
        m = float(y1 - y0) / float(x1 - x0);
        b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
        if (m < 1. && m > -1.) { //when |m|<1
            for (xi = (x0 < x1 ? x0 : x1); xi <= (x0 < x1 ? x1 : x0); xi++) {
                px = xi;
                py = m * float(xi) + b;
                draw_zbuffer_pixel(p1, p2, px, py, c);
            }
        }
        else { //when |m|>=1
            for (yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
                py = yi;
                px = 1. / m * float(yi) - b / m;
                draw_zbuffer_pixel(p1, p2, px, py, c);
            }
        }
    }
}

void draw_triface(const triface_t f) {
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
            draw_scanline(p1, p2, f.color);
        }
    }
    else if (y1 - y0 == 0) { //when line is vertical
        for (xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
            p2.x = xi;
            p2.y = yi;
            draw_scanline(p1, p2, f.color);
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
                draw_scanline(p1, p2, f.color);
            }
        }
        else { //when |m|>=1
            for (yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
                xi = int(round(1. / m * float(yi) - b / m));
                p2.x = xi;
                p2.y = yi;
                draw_scanline(p1, p2, f.color);
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
    objdata.center.x = x / objdata.vertices.size();
    objdata.center.y = y / objdata.vertices.size();
    objdata.center.z = z / objdata.vertices.size();
    vertices_translation(-objdata.center.x, -objdata.center.y, -objdata.center.z);
    vertices_scale(rscale, rscale, rscale);
    vertices_translation(0, 0, DEPTH / 2);
    //printf("center -- %f %f %f\n", objdata.center.x, objdata.center.y, objdata.center.z);
}

void vertices_transform(const matrix_t& m) {
    for (unsigned int i = 0; i < (objdata.vertices.size()); i++) {
        matrix_multi_vector(objdata.vertices[i], m, objdata.vertices[i]);
        //printf("i-%d, x %f, y %f, z %f, w %f\n", i, objdata.vertices[i].x, objdata.vertices[i].y, objdata.vertices[i].z, objdata.vertices[i].w);
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
    matrix_t m, t1, t2 , s;
    matrix_set_translation(t1, -objdata.center.x, -objdata.center.y, -objdata.center.z);
    matrix_set_scale(s, x, y, z);
    matrix_set_translation(t2, objdata.center.x, objdata.center.y, objdata.center.z);
    matrix_mul(m, t1, s);
    matrix_mul(m, m, t2);
    vertices_transform(m);
}
void vertices_perspective(const float& d) {
    matrix_t m;
    matrix_init_identity(m);
    m[3][2] = 1.0f/d;
    m[3][2] = 0.0f;
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
        objdata.faces.push_back(face);
    }
}
void center_translation(const float x, const float y, const float z) {
    objdata.center.x += x;
    objdata.center.y += y;
    objdata.center.z += z;
}

void view_obj() {
    render_init();
    for (unsigned int i = 0; i<objdata.faces.size(); i++) {
        if (showframe == 0) {
            draw_triface(objdata.faces[i]);
        }
        draw_scanline(objdata.faces[i].v1, objdata.faces[i].v2, white);
        draw_scanline(objdata.faces[i].v2, objdata.faces[i].v3, white);
        draw_scanline(objdata.faces[i].v1, objdata.faces[i].v3, white);
    }

    //printf("------- frame updated -------\n");
}


/********************** some math functions **********************/
void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y) {
    float m1, m2, m3;
    m1 = x.y * y.z - x.z * y.y;
    m2 = x.z * y.x - x.x * y.z;
    m3 = x.x * y.y - x.y * y.x;
    z.x = m1;
    z.y = m2;
    z.z = m3;
    z.w = 1.0;
}
void vector_homogenate(vector_t& v) {
    float wp = 1.0f / v.w;
    v.x *= wp;
    v.y *= wp;
    v.z *= wp;
}
void matrix_init_identity(matrix_t& m) {
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1;
    m[0][1] = m[0][2] = m[0][3] = 0;
    m[1][0] = m[1][2] = m[1][3] = 0;
    m[2][0] = m[2][1] = m[2][3] = 0;
    m[3][0] = m[3][1] = m[3][2] = 0;
}
void matrix_copy(matrix_t& dst, const matrix_t& src) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dst[i][j] = src[i][j];
        }
    }
}
void matrix_mul(matrix_t& dst, const matrix_t& m1, const matrix_t& m2) {
    matrix_t r;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    matrix_copy(dst, r);
}
void matrix_multi_vector(vector_t& dst, const matrix_t& m, const vector_t& v) {
    float vx = v.x, vy = v.y, vz = v.z, vw = v.w;
    dst.x = m[0][0] * vx + m[0][1] * vy + m[0][2] * vz + m[0][3] * vw;
    dst.y = m[1][0] * vx + m[1][1] * vy + m[1][2] * vz + m[1][3] * vw;
    dst.z = m[2][0] * vx + m[2][1] * vy + m[2][2] * vz + m[2][3] * vw;
    dst.w = m[3][0] * vx + m[3][1] * vy + m[3][2] * vz + m[3][3] * vw;
}
void matrix_set_translation(matrix_t& dst, const float x, const float y, const float z) {
    matrix_init_identity(dst);
    dst[0][3] = x;
    dst[1][3] = y;
    dst[2][3] = z;
}
void matrix_set_rotation_x(matrix_t& dst, const float theta) {
    float vcos = cos(theta);
    float vsin = sin(theta);
    matrix_init_identity(dst);
    dst[1][1] = vcos;
    dst[1][2] = -vsin;
    dst[2][1] = vsin;
    dst[2][2] = vcos;
}
void matrix_set_rotation_y(matrix_t& dst, const float theta) {
    float vcos = cos(theta);
    float vsin = sin(theta);
    matrix_init_identity(dst);
    dst[0][0] = vcos;
    dst[0][2] = vsin;
    dst[2][0] = -vsin;
    dst[2][2] = vcos;
}
void matrix_set_rotation_z(matrix_t& dst, const float theta) {
    float vcos = cos(theta);
    float vsin = sin(theta);
    matrix_init_identity(dst);
    dst[0][0] = vcos;
    dst[0][1] = -vsin;
    dst[1][0] = vsin;
    dst[1][1] = vcos;
}
void matrix_set_rotation_arbitrry(matrix_t& dst, const vector_t& v, const float theta) {
    /* v is the arbitrary axis vector */

}
void matrix_set_scale(matrix_t& dst, const float x, const float y, const float z) {
    matrix_init_identity(dst);
    dst[0][0] = x;
    dst[1][1] = y;
    dst[2][2] = z;
}
