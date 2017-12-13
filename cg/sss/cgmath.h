#ifndef CGMATH_H
#define CGMATH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

#include "common.h"

#define M_PI 3.14159265358979323846
#define LIMIT_ZERO 0.000001


float saturate(const float& x, const float& l, const float& h);
bool fequ(const float& a, const float& b);
float fmax_2(const float& a, const float& b);
float fmin_2(const float& a, const float& b);
float fmax_3(const float& a, const float& b, const float& c);
float fmin_3(const float& a, const float& b, const float& c);
float fsaturate(float& a);
float line3d_getz(const point_t p1, const point_t p2, float x, float y);
void triangle_vertex_clockwise(point_t& p1, point_t& p2, point_t& p3);
void vector_minus(vector_t& dst, const vector_t& v1, const vector_t& v2);
void vector_scalar(vector_t& dst, const float& c, const vector_t& v);
void vector_mul(vector_t& dst, const vector_t& v1, const vector_t& v2);
void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y);
void vector_homogenate(vector_t& v);
void vector_normalize(vector_t& v);
float vector_magnitude(const vector_t& v);
float vector_angle(const vector_t& v1, const vector_t& v2);
float vector_dotproduct(const vector_t& v1, const vector_t& v2);
void vector_print(const vector_t& v, const char* vname);
void matrix_init_identity(matrix_t& m);
void matrix_copy(matrix_t& dst, const matrix_t& src);
void matrix_mul(matrix_t& dst, const matrix_t& m1, const matrix_t& m2);
void matrix_multi_vector(vector_t& dst, const matrix_t& m, const vector_t& v);
void triangle_getBarycentric(float& u, float& v, const point_t& v1, const point_t& v2, const point_t& v3, const float& x, const float& y);
color_t vector2color(const vector_t& v);
vector_t color2vector(const color_t& c);

#endif
