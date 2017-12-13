#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "loader.h"
#include "viewer.h"

void obj_loader(const char *path) {
    FILE * objfile = fopen(path, "r");
    if (objfile == NULL) {
        printf(".obj file open failed!\n");
        exit(-1);
    }
    objdata.nsmooth = 0;
    std::string g_temp;
    char group_temp[20];
    int sgroup_temp = 0;

    while (1) {
        char text[128]; //save current reading text
        if (fscanf(objfile, "%s", text) == EOF)  break;
        if (strcmp(text, "v") == 0) {
            fscanf(objfile, "%f %f %f\n", &(vertex.x), &(vertex.y), &(vertex.z));
            vertex.w = 1.0f;
            objdata.vertices.push_back(vertex);
            //printf("vertex: %f  %f  %f  %f\n", vertex.x, vertex.y, vertex.z, vertex.w);
        }
        if (strcmp(text, "vn") == 0) {
            fscanf(objfile, "%f %f %f\n", &(vnormal.x), &(vnormal.y), &(vnormal.z));
            vnormal.w = 1.0f;
            objdata.vnormals.push_back(vnormal);
            //printf("vnormal: %f  %f  %f  %f\n", vnormal.x, vnormal.y, vnormal.z, vnormal.w);
        }
        if (strcmp(text, "vt") == 0) {
            fscanf(objfile, "%f %f\n", &(vuv.u), &(vuv.v));
            objdata.vuvs.push_back(vuv);
            //printf("vuv: %f  %f \n", vuv.u, vuv.v);
        }
        if (strcmp(text, "s") == 0) {
            fscanf(objfile, "%d\n", &sgroup_temp);
            color_random(color);
            objdata.colors.push_back(color);
            objdata.nsmooth++;
        }
        if (strcmp(text, "g") == 0) {
            fscanf(objfile, "%s\n", group_temp);
        }
        int temp;
        int nget = 0;
        int vit = 0;
        int nt = 0;
        int uvt = 0;
        if (strcmp(text, "f") == 0) {
            nget = fscanf(objfile, "%d/%d/%d",
                &(vi.vi1), &(vi.uv1), &(vi.n1)
            );
            if (nget == 2) {
                nget = fscanf(objfile, "%d/%d %d/%d %d/%d\n",
                    &(vi.vi2), &(vi.uv2),
                    &(vi.vi3), &(vi.uv3),
                    &(vit), &(uvt)
                );
                vi.n1 = vi.n2 = vi.n3 = 0;
                vi.sgroup = sgroup_temp;
                objdata.vertex_indices.push_back(vi);
                //printf("primitive: %d %d %d - %d\n", vi.vi1, vi.vi2, vi.vi3, vi.sgroup);

                vi.vi2 = vi.vi3;
                vi.uv2 = vi.uv3;
                vi.vi3 = vit;
                vi.uv3 = uvt;
                objdata.vertex_indices.push_back(vi);
                //printf("primitive: %d %d %d - %d\n", vi.vi1, vi.vi2, vi.vi3, vi.sgroup);

            }
            else {
                nget = fscanf(objfile, "%d/%d/%d %d/%d/%d\n",
                    &(vi.vi2), &(vi.uv2), &(vi.n2),
                    &(vi.vi3), &(vi.uv3), &(vi.n3)
                );
                vi.sgroup = sgroup_temp;
                objdata.vertex_indices.push_back(vi);
                //printf("primitive: %d %d %d - %d\n", vi.vi1, vi.vi2, vi.vi3, vi.sgroup);
            }
        }
    }
    vertices_init();
}

void textureMap_loader(const char *path) {
    int w, h ,n; //width, height, and n channels
    unsigned char *texture = stbi_load(path, &w, &h, &n, 0);

    if (texture) {
        printf("texture map - width: %d, height: %d, channels: %d\n", w, h, n);
    }
    else {
        printf("cannot find texture map\n", w, h, n);
        return;
    }

    objdata.texh = h;
    objdata.texw = w;

    objdata.texture = new color_t*[h];
    for (int i = 0; i < h; i++) {
        objdata.texture[i] = new color_t[w];
    }
    uchar2color(objdata.texture, texture, w, h);

    //write_frame(objdata.texture, w, h);

    delete[] texture;
}

void normalMap_loader(const char *path) {
    int w, h, n; //width, height, and n channels
    unsigned char *normal = stbi_load(path, &w, &h, &n, 0);

    if (normal) {
        printf("normal map - width: %d, height: %d, channels: %d\n", w, h, n);
    }
    else {
        printf("cannot find normal map\n", w, h, n);
        return;
    }

    objdata.texh = h;
    objdata.texw = w;

    objdata.normal = new vector_t*[h];
    for (int i = 0; i < h; i++) {
        objdata.normal[i] = new vector_t[w];
    }
    uchar2vector(objdata.normal, normal, w, h);

    //write_frame(objdata.normal, w, h);

    delete[] normal;
}

void uchar2color(color_t **frame, unsigned char* image, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            frame[i][j].r = (float)image[j * 3 + i * w * 3] / 255;
            frame[i][j].g = (float)image[j * 3 + i * w * 3 + 1] / 255;
            frame[i][j].b = (float)image[j * 3 + i * w * 3 + 2] / 255;
            //printf("rgb %f %f %f\n", frame[i][j].r, frame[i][j].g, frame[i][j].b);
        }
    }
}

void uchar2vector(vector_t **frame, unsigned char* image, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            frame[i][j].x = (float)image[j * 3 + i * w * 3] / 255;
            frame[i][j].y = (float)image[j * 3 + i * w * 3 + 1] / 255;
            frame[i][j].z = (float)image[j * 3 + i * w * 3 + 2] / 255;
            frame[i][j].w = 1.0f;
            vector_normalize(frame[i][j]);
            //printf("rgb %f %f %f\n", frame[i][j].r, frame[i][j].g, frame[i][j].b);
        }
    }

}

void color2uchar(unsigned char* image, color_t **frame, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image[j * 3 + i * w * 3] = (unsigned char)(frame[i][j].r * 255);
            image[j * 3 + i * w * 3 + 1] = (unsigned char)(frame[i][j].g * 255);
            image[j * 3 + i * w * 3 + 2] = (unsigned char)(frame[i][j].b * 255);
        }
    }
}

void write_frame(color_t **frame, int w, int h) {
    static int count = 0;
    char nchar[64];
    char name[128];
    const char* pre = "frame";
    const char* etn = ".jpg";
    itoa(count, nchar, 10);
    sprintf(name, "%s%s%s", pre, nchar, etn);

    unsigned char* image = new unsigned char[w * h * 3];
    color2uchar(image, frame, w, h);

    int re = stbi_write_jpg(name, w, h, 3, image, 100);
    if (re) {
        count++;
        printf("%s saved", name);
    }
    else {
        printf("%s failed tp save", name);
    }

    delete[] image;
}

void write_frame(color_t frame[HEIGHT][WIDTH]) {
    static int count = 0;
    char nchar[64];
    char name[128];
    const char* pre = "frame";
    const char* etn = ".jpg";
    itoa(count, nchar, 10);
    sprintf(name, "%s%s%s", pre, nchar, etn);

    unsigned char* image = new unsigned char[WIDTH * HEIGHT * 3];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[j * 3 + i * WIDTH * 3] = (unsigned char)(frame[HEIGHT - i -1][j].r * 255);
            image[j * 3 + i * WIDTH * 3 + 1] = (unsigned char)(frame[HEIGHT - i - 1][j].g * 255);
            image[j * 3 + i * WIDTH * 3 + 2] = (unsigned char)(frame[HEIGHT - i - 1][j].b * 255);
        }
    }
    int re = stbi_write_jpg(name, WIDTH, HEIGHT, 3, image, 100);
    if (re) {
        count++;
        printf("%s saved\n", name);
    }
    else {
        printf("%s failed tp save\n", name);
    }

    delete[] image;
}

