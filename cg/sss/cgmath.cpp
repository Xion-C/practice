#include "cgmath.h"
#include "common.h"

/********************** some math functions **********************/
float saturate(const float& x, const float& l, const float& h) {
    float res;
    res = x > h ? h : (x < l ? l : x);
    return res;
}

bool fequ(const float& a, const float& b) {
    if (fabs(a - b) < LIMIT_ZERO) {
        return true;
    }
    else {
        return false;
    }
}

float fmax_2(const float& a, const float& b) {
    return a>b ? a : b;
}
float fmin_2(const float& a, const float& b) {
    return a<b ? a : b;
}
float fmax_3(const float& a, const float& b, const float& c) {
    float m = a>b ? a : b;
    m = c>m ? c : m;
    return m;
}
float fmin_3(const float& a, const float& b, const float& c) {
    float m = a<b ? a : b;
    m = c<m ? c : m;
    return m;
}
float fsaturate(float& a) {
    if (a > 1.0f) {
        a = 1.0f;
    }
    else if (a < 0.0f) {
        a = 0.0f;
    }
    return a;
}
float line3d_getz(const point_t p1, const point_t p2, float x, float y) {
    float dxy, dpxy;
    dpxy = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    dxy = sqrt((x - p1.x)*(x - p1.x) + (y - p1.y)*(y - p1.y));
    if (dpxy > 0.5)  return p1.z + (p2.z - p1.z)*dxy / dpxy;
    else  return  p2.z<p1.z ? p2.z : p1.z;
}
void triangle_vertex_clockwise(point_t& p1, point_t& p2, point_t& p3) {
    float y1 = p1.y;
    float y2 = p2.y;
    float y3 = p3.y;
    float x1 = p1.x;
    float x2 = p2.x;
    float x3 = p3.x;
    float dx12 = x1 - x2;
    float dx23 = x2 - x3;
    float dy12 = y1 - y2;
    float dy23 = y2 - y3;
    point_t temp;
    if (dx12 * dy23 - dy12 * dx23 > 0) {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }
}
void vector_minus(vector_t& dst, const vector_t& v1, const vector_t& v2) {
    float x, y, z;
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
    dst.x = x;
    dst.y = y;
    dst.z = z;
    dst.w = 1.0f;
}
void vector_scalar(vector_t& dst, const float& c, const vector_t& v) {
    float x, y, z;
    x = c * v.x;
    y = c * v.y;
    z = c * v.z;
    dst.x = x;
    dst.y = y;
    dst.z = z;
    dst.w = v.w;
}
void vector_mul(vector_t& dst, const vector_t& v1, const vector_t& v2) {
    vector_t r;
    r.x = v1.x * v2.x;
    r.y = v1.y * v2.y;
    r.z = v1.z * v2.z;
    r.w = 1.0f;
    dst.x = r.x;
    dst.y = r.y;
    dst.z = r.z;
    dst.w = r.w;
}
void vector_crossproduct(vector_t& z, const vector_t& x, const vector_t& y) {
    float m1, m2, m3;
    m1 = x.y * y.z - x.z * y.y;
    m2 = x.z * y.x - x.x * y.z;
    m3 = x.x * y.y - x.y * y.x;
    z.x = m1;
    z.y = m2;
    z.z = m3;
    z.w = 1.0f;
}
void vector_homogenate(vector_t& v) {
    float wp = 1.0f / v.w;
    v.x *= wp;
    v.y *= wp;
    v.z *= wp;
}
void vector_normalize(vector_t& v) {
    double r;
    r = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    v.x = v.x / r;
    v.y = v.y / r;
    v.z = v.z / r;
    v.w = 1.0f;
}
float vector_magnitude(const vector_t& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
float vector_angle(const vector_t& v1, const vector_t& v2) {
    return acos((v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) / (vector_magnitude(v1) * vector_magnitude(v2)));
}
float vector_dotproduct(const vector_t& v1, const vector_t& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
void vector_print(const vector_t& v, const char* vname) {
    //printf("vector %s : x %f, y %f, z %f, w %f\n", vname, v.x, v.y, v.z, v.w);
    printf("vector %s : x %f, y %f, z %f\n", vname, v.x, v.y, v.z);
}

void matrix_init_identity(matrix_t& m) {
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1;
    m[0][1] = m[0][2] = m[0][3] = 0;
    m[1][0] = m[1][2] = m[1][3] = 0;
    m[2][0] = m[2][1] = m[2][3] = 0;
    m[3][0] = m[3][1] = m[3][2] = 0;
}
void matrix_copy(matrix_t& dst, const matrix_t& src) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dst[i][j] = src[i][j];
        }
    }
}
void matrix_mul(matrix_t& dst, const matrix_t& m1, const matrix_t& m2) {
    matrix_t r;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    matrix_copy(dst, r);
}
void matrix_multi_vector(vector_t& dst, const matrix_t& m, const vector_t& v) {
    float vx = v.x, vy = v.y, vz = v.z, vw = v.w;
    dst.x = m[0][0] * vx + m[0][1] * vy + m[0][2] * vz + m[0][3] * vw;
    dst.y = m[1][0] * vx + m[1][1] * vy + m[1][2] * vz + m[1][3] * vw;
    dst.z = m[2][0] * vx + m[2][1] * vy + m[2][2] * vz + m[2][3] * vw;
    dst.w = m[3][0] * vx + m[3][1] * vy + m[3][2] * vz + m[3][3] * vw;
}

void triangle_getBarycentric(float& u, float& v, const point_t& v1, const point_t& v2, const point_t& v3, const float& x, const float& y) {
    float vx12 = v2.x - v1.x;
    float vx13 = v3.x - v1.x;
    float vy12 = v2.y - v1.y;
    float vy13 = v3.y - v1.y;
    float v1x = x - v1.x;
    float v1y = y - v1.y;

    vector_t v12 = { vx12, vy12, 0.0f, 1.0f };
    vector_t v13 = { vx13, vy13, 0.0f, 1.0f };
    vector_t v1p = { v1x, v1y, 0.0f, 1.0f };

    //float xmax = fmax_3(vx12, vx13, v1x);
    //float ymax = fmax_3(vy12, vy13, v1y);
    //float amax = xmax > ymax ? xmax : ymax;
    //if (amax < 100) {
    //    float scale = 100 / amax;
    //    v12.x *= scale;
    //    v12.y *= scale;
    //    v13.x *= scale;
    //    v13.y *= scale;
    //    v1p.x *= scale;
    //    v1p.y *= scale;
    //}

    float m = vector_dotproduct(v12, v12) * vector_dotproduct(v13, v13) - vector_dotproduct(v12, v13) * vector_dotproduct(v12, v13);

    u = (vector_dotproduct(v12, v12) * vector_dotproduct(v1p, v13) - vector_dotproduct(v12, v13) * vector_dotproduct(v1p, v12)) / m;
    v = (vector_dotproduct(v13, v13) *  vector_dotproduct(v1p, v12) - vector_dotproduct(v12, v13) * vector_dotproduct(v1p, v13)) / m;

    if (fequ(m, 0.0f)) {
    //if (0) {
        //u = v = 0;
        float slope12 = v12.y / v12.x;
        float slope13 = v13.y / v13.x;
        float slopeaver = (slope12 + slope13) / 2;
        float slope1p = v1p.y / v1p.x;
        float ratio = slope1p / slopeaver;
        if (ratio > 0.8 && ratio < 1.2) {
            u = v = ratio;
        }
        else {
            //printf("m is %f, not a triangle, u %f, v %f\n", m, u, v);
            //vector_print(v1, "v1");
            //vector_print(v2, "v2");
            //vector_print(v3, "v3");
            //vector_print(v12, "v12");
            //vector_print(v13, "v13");
            //vector_print(v1p, "v1p");
            u = v = 0;
        }
    }
    //else {
    //    u = (vector_dotproduct(v12, v12) * vector_dotproduct(v1p, v13) - vector_dotproduct(v12, v13) * vector_dotproduct(v1p, v12)) / m;
    //    v = (vector_dotproduct(v13, v13) *  vector_dotproduct(v1p, v12) - vector_dotproduct(v12, v13) * vector_dotproduct(v1p, v13)) / m;
    //}
}

color_t vector2color(const vector_t& v) {
    color_t c;
    c.r = v.x;
    c.g = v.y;
    c.b = v.z;
    return c;
}

vector_t color2vector(const color_t& c) {
    vector_t v;
    v.x = c.r;
    v.y = c.g;
    v.z = c.b;
    v.w = 1.0f;
    return v;
}
