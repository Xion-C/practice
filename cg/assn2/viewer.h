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

#define WIDTH 800
#define HEIGHT 600
#define DEPTH 800

typedef unsigned int UINT32;

typedef struct {
  float x, y, z, w;
}point_t;

typedef point_t vector_t;

typedef struct {
  float r, g, b;
}color_t;

typedef struct {
  point_t v1, v2, v3;
  color_t color;
  int sgroup;
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
}obj_t;

typedef float matrix_t[4][4];

typedef struct {
  UINT32 frame[WIDTH][HEIGHT];
  float zbuffer[WIDTH][HEIGHT];
}render_t;

extern int biasx, biasy;
extern point_t vertex;
extern color_t color;
extern color_t white;
extern triface_t face;
extern vertex_index_t vi;
extern obj_t objdata;
extern render_t render;

void write_pixel(int x, int y, color_t c);
//void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y);
void color_random(color_t& c);
void color_white(color_t& c);
void obj_loader(const char *path);
float line3d_getz(const point_t p1, const point_t p2, float x, float y);
void draw_zbuffer_pixel(point_t p1,point_t p2,int xi,int yi,color_t c);
void draw_scanline(point_t p1, point_t p2, color_t c);
void draw_triface(const triface_t f);
void render_init();
void vertices_init();
void vertices_transform(const matrix_t& m);
void faces_init();
void view_obj();

void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y);
void matrix_init_identity(matrix_t& m);
void matrix_multi_vector(vector_t& dst, const matrix_t& m, const vector_t& v);
void matrix_set_translation(matrix_t& dst,float x,float y,float z);

#endif
