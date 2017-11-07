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

#define WIDTH 800
#define HEIGHT 600
#define DEPTH 800
#define LIMIT_ZERO 0.00001

typedef unsigned int UINT32;

typedef struct {
    float r, g, b;
}color_t;

typedef struct {
    point_t v1, v2, v3;
    color_t color;
    int sgroup;
    vector_t n;
    // some temp data to accelerate compute
    bool zn;
    float d;
}triface_t;

typedef struct {
    int vi1, vi2, vi3;
    int sgroup;
}vertex_index_t;

typedef struct {
    std::vector<point_t> vertices;
    std::vector<triface_t> faces;
    std::vector<vertex_index_t> vertex_indices;
    std::vector<color_t> colors;
    point_t center;
    float maxsize;
}obj_t;


typedef struct {
    UINT32 frame[WIDTH][HEIGHT];
    float zbuffer[WIDTH][HEIGHT];
}render_t;

extern int biasx, biasy;
extern int showframe;
extern int showperspective;

extern point_t vertex;
extern color_t color;
extern color_t white;
extern triface_t face;
extern vertex_index_t vi;
extern obj_t objdata;
extern render_t render;

void write_pixel(int x, int y, color_t c);
void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y);
void color_random(color_t& c);
void color_white(color_t& c);
void obj_loader(const char *path);
float line3d_getz(const point_t p1, const point_t p2, float x, float y);
void draw_zbuffer_pixel(point_t p1, point_t p2, float px, float py, color_t c);
void draw_line(point_t p1, point_t p2, color_t c);
void draw_triface(const triface_t& f);
void render_init();
void vertices_init();
void vertices_transform(const matrix_t& m);
void vertices_translation(const float& x, const float& y, const float& z);
void vertices_rotation_x(const float& theta);
void vertices_rotation_y(const float& theta);
void vertices_rotation_z(const float& theta);
void vertices_scale(const float& x, const float& y, const float& z);
void faces_init();
void center_translation(const float x, const float y, const float z);
void view_obj();

void triangle_vertex_clockwise(point_t& p1, point_t& p2, point_t& p3);
void triface_rasterization(const triface_t& f);
#endif
