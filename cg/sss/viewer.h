#ifndef VIEWER_H
#define VIEWER_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <vector>

#include "cgmath.h"
#include "common.h"

/* functions */

void write_pixel(int x, int y, color_t c);
int frame_set(color_t frame[HEIGHT][WIDTH], int x, int y, color_t color);
int frame_set(color_t frame[HEIGHT][WIDTH], float zbuffer[HEIGHT][WIDTH], int x, int y, color_t color, float zbuf);
int zbuffer_set(float zbuffer[HEIGHT][WIDTH], int x, int y, float zbuf);

void draw_line(point_t p1, point_t p2, color_t c);

color_t shader_simplelight(const primitive_t& f, const vector_t& light, const vector_t& view);
void texture_uv2xy(int& x, int& y, const float& alpha, const float& beta, const primitive_t& f);
void normal_uv2xy(int& x, int& y, const float& alpha, const float& beta, const primitive_t& f);
color_t fragment_shader(const light_t& light, const point_t& camera, const primitive_t& f, point_t p);
int primitive_printInfo(const primitive_t& f);
void primitive_perspective(primitive_t& f);
void primitive_set_plane_paras(primitive_t& f_t);
void primitive_rasterization(const primitive_t& f);

void color_random(color_t& c);
void color_white(color_t& c);

void render_init();
void vertices_init();
void primitives_init();

void view_obj();


void generateGaussianTemplate(int ksize, double sigma);
void generateGaussianTemplate(float** filter, int ksize, double sigma);
void gaussian_filter(int ksize);
void gaussian6pass(int ksize);

#endif
