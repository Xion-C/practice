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
#define HEIGHT 800
#define DEPTH 1600
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
    int nsmooth;
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
void draw_zbuffer_pixel(int xi, int yi, float zbuf, color_t c);
void draw_line(point_t p1, point_t p2, color_t c);
void triface_rasterization(const triface_t& f);

void color_random(color_t& c);
void color_white(color_t& c);

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

void obj_loader(const char *path);
void view_obj();

#endif
