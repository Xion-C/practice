#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

bool file_exists(const char * filename);
void obj_loader(const char *path);
void textureMap_loader(const char *path);
void normalMap_loader(const char *path);
void uchar2color(color_t **frame, unsigned char* image, int w, int h);
void uchar2vector(vector_t **frame, unsigned char* image, int w, int h);
void color2uchar(unsigned char* image, color_t **frame, int w, int h);
void write_frame(color_t **frame, int w, int h);
void write_frame(color_t frame[HEIGHT][WIDTH]);
