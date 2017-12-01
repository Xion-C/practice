#include "cgmath.h"

/********************** some math functions **********************/
float fmax_2(const float& a, const float& b) {
    return a>b ? a : b;
}
float fmin_2(const float& a, const float& b) {
    return a<b ? a : b;
}
float fmax_3(const float& a, const float& b, const float& c) {
    float m = a>b ? a : b;
    m = c>m ? c : m;
    return m;
}
float fmin_3(const float& a, const float& b, const float& c) {
    float m = a<b ? a : b;
    m = c<m ? c : m;
    return m;
}
float line3d_getz(const point_t p1, const point_t p2, float x, float y) {
    float dxy, dpxy;
    dpxy = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    dxy = sqrt((x - p1.x)*(x - p1.x) + (y - p1.y)*(y - p1.y));
    if (dpxy > 0.5)  return p1.z + (p2.z - p1.z)*dxy / dpxy;
    else  return  p2.z<p1.z ? p2.z : p1.z;
}
void triangle_vertex_clockwise(point_t& p1, point_t& p2, point_t& p3) {
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
    point_t temp;
    if (dx12 * dy23 - dy12 * dx23 > 0) {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }
}
void vector_minus(vector_t& dst, const vector_t& v1, const vector_t& v2) {
    float x, y, z;
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
    dst.x = x;
    dst.y = y;
    dst.z = z;
    dst.w = 1.0f;
}

void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y) {
    float m1, m2, m3;
    m1 = x.y * y.z - x.z * y.y;
    m2 = x.z * y.x - x.x * y.z;
    m3 = x.x * y.y - x.y * y.x;
    z.x = m1;
    z.y = m2;
    z.z = m3;
    z.w = 1.0f;
}
void vector_homogenate(vector_t& v) {
    float wp = 1.0f / v.w;
    v.x *= wp;
    v.y *= wp;
    v.z *= wp;
}
void vector_normalize(vector_t& v) {
    double r;
    r = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    v.x = v.x / r;
    v.y = v.y / r;
    v.z = v.z / r;
    v.w = 1.0f;
}
float vector_magnitude(const vector_t& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
float vector_angle(const vector_t& v1, const vector_t& v2) {
    return acos((v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) / (vector_magnitude(v1) * vector_magnitude(v2)));
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

void matrix_set_scale(matrix_t& dst, const float x, const float y, const float z) {
    matrix_init_identity(dst);
    dst[0][0] = x;
    dst[1][1] = y;
    dst[2][2] = z;
}
void matrix_set_perspective(matrix_t& dst, const float d) {
    matrix_init_identity(dst);
    dst[3][3] = 0;
    dst[3][2] = 1.0f / d;
}
