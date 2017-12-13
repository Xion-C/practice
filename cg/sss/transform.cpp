#include "transform.h"
#include "viewer.h"


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

void matrix_set_scale(matrix_t& dst, const float x, const float y, const float z) {
    matrix_init_identity(dst);
    dst[0][0] = x;
    dst[1][1] = y;
    dst[2][2] = z;
}
void matrix_set_perspective(matrix_t& dst, const float d, const point_t& camera_p) {
    //float dz = camera_p.z - d;
    //dz = d < 0 ? -d : d;
    matrix_init_identity(dst);
    dst[3][3] = 0;
    dst[3][2] = 1.0f / d;
}


void center_translation(const float x, const float y, const float z) {
    objdata.center.x += x;
    objdata.center.y += y;
    objdata.center.z += z;
}

void vertices_transform(const matrix_t& m) {
    for (unsigned int i = 0; i < (objdata.vertices.size()); i++) {
        matrix_multi_vector(objdata.vertices[i], m, objdata.vertices[i]);
        // printf("i-%d, x %f, y %f, z %f, w %f\n", i, objdata.vertices[i].x, objdata.vertices[i].y, objdata.vertices[i].z, objdata.vertices[i].w);
    }
    primitives_init();
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
