#include "viewer.h"

void write_pixel(int x, int y, color_t c) {
    /* Turn on the pixel found at x,y */
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_POINTS);
    glVertex3i(x, y, 0);
    glEnd();
}

void color_random(color_t& c) {
    c.r = float(rand()) / float(RAND_MAX);
    c.g = float(rand()) / float(RAND_MAX);
    c.b = float(rand()) / float(RAND_MAX);
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
            objdata.vertices.push_back(vertex);
            printf("vertex: %f  %f  %f\n", vertex.x, vertex.y, vertex.z);
        }
        int sgroup_temp;
        if (strcmp(text, "s") == 0) {
            fscanf(objfile, "%d\n", &sgroup_temp);
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
    faces_init();

    for (unsigned int i = 0; i < (objdata.faces.size()); i++) {
        printf("x %f\n", objdata.faces[i].v1.x);
        printf("r %f g %f b %f\n", objdata.faces[i].color.r, objdata.faces[i].color.g, objdata.faces[i].color.b);
    }
}

float line3d_getz(const point_t p1, const point_t p2, float x, float y) {
    float dxy, dpxy;
    dpxy = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    dxy = sqrt((x - p1.x)*(x - p1.x) + (y - p1.y)*(y - p1.y));
    if (dpxy > 0.5)  return p1.z + (p2.z - p1.z)*dxy / dpxy;
    else  return  p2.z<p1.z ? p2.z : p1.z;
}

void draw_zbuffer_pixel(point_t p1, point_t p2, int xi, int yi, color_t c) {
    float zbuf;
    zbuf = line3d_getz(p1, p2, xi, yi);
    if (zbuf<render.zbuffer[xi][yi]) {
        write_pixel(xi, yi, c);
        render.zbuffer[xi][yi] = zbuf;
        //printf("draw x %d y %d c %f\n",xi,yi,c.r);
    }
}

void draw_scanline(point_t p1, point_t p2, color_t c) //draw a line using dda algorithm
{
    float m, b;
    int x0, x1, y0, y1;
    int xi, yi;
    x0 = round(p1.x);
    x1 = round(p2.x);
    y0 = round(p1.y);
    y1 = round(p2.y);
    if (x1 - x0 == 0) { //when line is horizontal
        for (xi = x0, yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
            draw_zbuffer_pixel(p1, p2, xi, yi, c);
        }
    }
    else if (y1 - y0 == 0) { //when line is vertical
        for (xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
            draw_zbuffer_pixel(p1, p2, xi, yi, c);
        }
    }
    else {
        m = float(y1 - y0) / float(x1 - x0);
        b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
        if (m < 1. && m > -1.) { //when |m|<1
            for (xi = (x0 < x1 ? x0 : x1); xi <= (x0 < x1 ? x1 : x0); xi++) {
                yi = int(round(m * float(xi) + b));
                draw_zbuffer_pixel(p1, p2, xi, yi, c);
            }
        }
        else { //when |m|>=1
            for (yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
                xi = int(round(1. / m * float(yi) - b / m));
                draw_zbuffer_pixel(p1, p2, xi, yi, c);
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
    point_t obj_center;
    float x, y, z;
    x = y = z = 0;
    for (unsigned int i = 0; i < (objdata.vertices.size()); i++) {
        x += objdata.vertices[i].x;
        y += objdata.vertices[i].y;
        z += objdata.vertices[i].z;
    }
    obj_center.x = x / objdata.vertices.size();
    obj_center.y = y / objdata.vertices.size();
    obj_center.z = z / objdata.vertices.size();

}

void faces_init() {
    for (unsigned int i = 0; i < (objdata.vertex_indices.size()); i++) {
        face.v1 = objdata.vertices[objdata.vertex_indices[i].vi1 - 1];
        face.v2 = objdata.vertices[objdata.vertex_indices[i].vi2 - 1];
        face.v3 = objdata.vertices[objdata.vertex_indices[i].vi3 - 1];
        face.sgroup = objdata.vertex_indices[i].sgroup;
        if (i == 0 || (i > 0 && face.sgroup != objdata.vertex_indices[i - 1].sgroup)) {
            color_random(face.color);
        }
        objdata.faces.push_back(face);
    }
}

void view_obj() {
    render_init();
    for (unsigned int i = 0; i<objdata.faces.size(); i++) {
        draw_triface(objdata.faces[i]);
    }
    printf("how many------\n");
}


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

void matrix_init_identity(matrix_t& m) {
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1;
    m[0][1] = m[0][2] = m[0][3] = 0;
    m[1][0] = m[1][2] = m[1][3] = 0;
    m[2][0] = m[2][1] = m[2][3] = 0;
}
void matrix_multi_vector(vector_t& result, const matrix_t m, const vector_t v) {
    float vx = v.x, vy = v.y, vz = v.z, vw = v.w;
    result.x = m[0][0] * vx + m[0][1] * vy + m[0][2] * vz + m[0][3] * vw;
    result.y = m[1][0] * vx + m[1][1] * vy + m[1][2] * vz + m[1][3] * vw;
    result.z = m[2][0] * vx + m[2][1] * vy + m[2][2] * vz + m[2][3] * vw;
    result.w = m[3][0] * vx + m[3][1] * vy + m[3][2] * vz + m[3][3] * vw;
}
void
