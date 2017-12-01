#ifndef CGMATH_H
#define CGMATH_H

#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct {
    float x, y, z, w;
}point_t;

typedef point_t vector_t;

typedef float matrix_t[4][4];


float fmax_2(const float& a, const float& b);
float fmin_2(const float& a, const float& b);
float fmax_3(const float& a, const float& b, const float& c);
float fmin_3(const float& a, const float& b, const float& c);
float line3d_getz(const point_t p1, const point_t p2, float x, float y);
void triangle_vertex_clockwise(point_t& p1, point_t& p2, point_t& p3);
void vector_minus(vector_t& dst, const vector_t& v1, const vector_t& v2);
void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y);
void vector_homogenate(vector_t& v);
void vector_normalize(vector_t& v);
float vector_magnitude(const vector_t& v);
float vector_angle(const vector_t& v1, const vector_t& v2);
void matrix_init_identity(matrix_t& m);
void matrix_copy(matrix_t& dst, const matrix_t& src);
void matrix_mul(matrix_t& dst, const matrix_t& m1, const matrix_t& m2);
void matrix_multi_vector(vector_t& dst, const matrix_t& m, const vector_t& v);
void matrix_set_translation(matrix_t& dst, const float x, const float y, const float z);
void matrix_set_rotation_x(matrix_t& dst, const float theta);
void matrix_set_rotation_y(matrix_t& dst, const float theta);
void matrix_set_rotation_z(matrix_t& dst, const float theta);
void matrix_set_rotation_arbitrry(matrix_t& dst, const vector_t& v, const float theta);
void matrix_set_scale(matrix_t& dst, const float x, const float y, const float z);
void matrix_set_perspective(matrix_t& dst, const float d);

#endif
