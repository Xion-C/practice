#pragma once

#include <stdlib.h>
#include <math.h>
#include "cgmath.h"
#include "common.h"

void matrix_set_translation(matrix_t& dst, const float x, const float y, const float z);
void matrix_set_rotation_x(matrix_t& dst, const float theta);
void matrix_set_rotation_y(matrix_t& dst, const float theta);
void matrix_set_rotation_z(matrix_t& dst, const float theta);
void matrix_set_scale(matrix_t& dst, const float x, const float y, const float z);
void matrix_set_perspective(matrix_t& dst, const float d, const point_t& camera_p);

void center_translation(const float x, const float y, const float z);

void vertices_transform(const matrix_t& m);
void vertices_translation(const float& x, const float& y, const float& z);
void vertices_rotation_x(const float& theta);
void vertices_rotation_y(const float& theta);
void vertices_rotation_z(const float& theta);
void vertices_scale(const float& x, const float& y, const float& z);

