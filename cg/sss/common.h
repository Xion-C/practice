#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <string>

//#include "cgmath.h"

#define WIDTH 800
#define HEIGHT 800
#define DEPTH -1600

#define W_SIZE 5

typedef unsigned int UINT32;

typedef struct {
    float x, y, z, w;
}point_t;

typedef point_t vector_t;

typedef float matrix_t[4][4];

typedef struct {
    float r, g, b;
}color_t;

typedef struct {
    point_t pos;
    vector_t diffuse;
    vector_t specular;
}light_t;

typedef struct {
    float u, v;
}uv_t;

typedef struct {
    point_t v1, v2, v3;
    vector_t vn1, vn2, vn3;
    uv_t vt1, vt2, vt3;
    color_t color;

    int sgroup;
    std::string group;
    vector_t n;
    // some temp data to accelerate compute
    bool zn;
    float d;
    int nr;
}primitive_t;

typedef struct {
    int vi1, vi2, vi3;
    int n1, n2, n3;
    int uv1, uv2, uv3;
    int sgroup;
    std::string group;
}vertex_index_t;

typedef struct {
    std::vector<point_t> vertices;
    std::vector<vector_t> vnormals;
    std::vector<uv_t> vuvs;

    std::vector<primitive_t> faces;
    std::vector<vertex_index_t> vertex_indices;
    std::vector<color_t> colors;
    point_t center;
    float maxsize;
    int nsmooth;

    color_t **texture;
    int texw, texh;
    vector_t **normal;
    int norw, norh;

    float shininess;
    vector_t mdiffuse;
    vector_t mspecular;

}obj_t;

typedef struct {
    light_t light;
    point_t camera;
    color_t frame[HEIGHT][WIDTH];
    float zbuffer[HEIGHT][WIDTH];
    float zbuffer_last[HEIGHT][WIDTH];
    float depth[HEIGHT][WIDTH];
}render_t;

typedef struct {
    //color_t frame[WIDTH][HEIGHT];
    //float zbuffer[WIDTH][HEIGHT];
    float window[W_SIZE][W_SIZE];
    color_t f1[HEIGHT][WIDTH];
    color_t f2[HEIGHT][WIDTH];
    color_t f3[HEIGHT][WIDTH];
    color_t f4[HEIGHT][WIDTH];
    color_t f5[HEIGHT][WIDTH];
    color_t f6[HEIGHT][WIDTH];
    color_t f7[HEIGHT][WIDTH];
    //float zbuffer[HEIGHT][WIDTH];
}frame_t;

/* global varibles */

extern int x_last;
extern int y_last;
extern int biasx, biasy;
extern int showframe;
extern int showperspective;
extern int sssflag;
extern int saveflag;
extern int sssflag2;
extern int lightflag;
extern int addflag;
extern int reduceflag;
extern int clickflag;

extern vector_t light_parrallel;
extern point_t vertex;
extern vector_t vnormal;
extern uv_t vuv;
extern color_t color;
extern color_t white;
extern primitive_t face;
extern vertex_index_t vi;
extern obj_t objdata;
extern render_t render;

extern frame_t fbuffer;
