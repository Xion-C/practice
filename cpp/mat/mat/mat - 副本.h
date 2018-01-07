#pragma once
#include <iostream>

template<class T>
class Mat {
public:
    Mat() : _row(0), _col(0) { mat = nullptr; }
    Mat(const int& height, const int& width);
    Mat(T m[], const int& height, const int& width);
    Mat(T ** m, const int& height, const int& width);
    Mat(const Mat<T>& m);
    ~Mat();
    void init(const T& v);
    void print();
    T& at(int r, int h) { return mat[r][h]; }
    Mat<T> transpose();

    //read only member functions
    const T& at(int r, int h) const { return mat[r][h]; }
    const int row() const { return _row; }
    const int col() const { return _col; }

    //operator overload
    Mat<T>& operator=(const Mat<T>& m);
    Mat<T> operator+(const Mat<T>& m);
    Mat<T> operator-(const Mat<T>& m);
    Mat<T> operator*(const Mat<T>& m);
    template<class T1>
    friend Mat<T> operator*(const Mat<T>& m, const T1& k);
    template<class T1>
    friend Mat<T> operator*(const T1& k, const Mat<T>& m);
    template<class T>
    friend std::ostream& operator<<(std::ostream& os, const Mat<T>& m);
    
private:
    T** mat;
    int _row;
    int _col;
};

template<class T>
Mat<T>::Mat(const int& height, const int& width) : _row(height), _col(width) {
    if (height == 0 || width == 0) { mat = nullptr; }
    else {
        mat = new T*[height];
        for (int i = 0; i < height; i++) {
            mat[i] = new T[width];
        }
    }
}

template<class T>
Mat<T>::Mat(T m[], const int& height, const int& width) : _row(height), _col(width) {
    if (height == 0 || width == 0 || m == nullptr) { mat = nullptr; }
    else {
        mat = new T*[height];
        for (int i = 0; i < height; i++) {
            mat[i] = new T[width];
            for (int j = 0; j < width; j++) {
                mat[i][j] = m[i * width + j];
            }
        }
    }
}

template<class T>
Mat<T>::Mat(T ** m, const int& height, const int& width) : _row(height), _col(width) {
    if (height == 0 || width == 0 || m == nullptr) { mat = nullptr; }
    else {
        mat = new T*[height];
        for (int i = 0; i < height; i++) {
            mat[i] = new T[width];
            for (int j = 0; j < width; j++) {
                mat[i][j] = m[i][j];
            }
        }
    }
}

template<class T>
Mat<T>::Mat(const Mat<T>& m) : _row(m.row()), _col(m.col()) {
    std::cout << "copy" << std::endl;
    mat = new T*[_row];
    for (int i = 0; i < _row; i++) {
        mat[i] = new T[_col];
        for (int j = 0; j < _col; j++) {
            mat[i][j] = m.at(i, j);
        }
    }
}

template<class T>
Mat<T>::~Mat() {
    std::cout << "des start" << std::endl;
    if (_row == 0 && _col == 0) {}
    else { delete[] mat; }
    std::cout << "des end" << std::endl;
}

/******************************************************************/

template<class T>
void Mat<T>::init(const T& v) {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            mat[i][j] = v;
        }
    }
}

template<class T>
void Mat<T>::print() {
    std::cout << (*this);
}

template<class T>
Mat<T> Mat<T>::transpose() {
    int drow = _col;
    int dcol = _row;
    Mat<T> dst(drow, dcol);
    for (int i = 0; i < drow; i++) {
        for (int j = 0; j < dcol; j++) {
            dst.at(i, j) = mat[j][i];
        }
    }
    return dst;
}

/******************************************************************/

template<class T>
Mat<T>& Mat<T>::operator=(const Mat<T>& m) {
    if (this == &m) return *this;
    if (mat != nullptr) delete[] mat;
    mat = new T*[m.row()];
    for (int i = 0; i < m.row(); i++) {
        mat[i] = new T[m.col()];
        for (int j = 0; j < m.col(); j++) {
            mat[i][j] = m.at(i, j);
        }
    }
    return *this;
}

template<class T>
Mat<T> Mat<T>::operator+(const Mat<T>& m) {
    try {
        if ((_row != m.row()) || (_col != m.col())) {
            throw "size doesn't match for matrices additon";
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    int drow = _row;
    int dcol = _col;
    Mat<T> dst(drow, dcol);
    for (int i = 0; i < drow; i++) {
        for (int j = 0; j < dcol; j++) {
            dst.at(i, j) = mat[i][j] + m.at(i, j);
        }
    }
    return dst;
}

template<class T>
Mat<T> Mat<T>::operator-(const Mat<T>& m) {
    try {
        if ((_row != m.row()) || (_col != m.col())) {
            throw "size doesn't match for matrices subtraction";
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    int drow = _row;
    int dcol = _col;
    Mat<T> dst(drow, dcol);
    for (int i = 0; i < drow; i++) {
        for (int j = 0; j < dcol; j++) {
            dst.at(i, j) = mat[i][j] - m.at(i, j);
        }
    }
    return dst;
}

template<class T>
Mat<T> Mat<T>::operator*(const Mat<T>& m) {
    try {
        if (_col != m.row()) {
            throw "size doesn't match for multiplying matrices";
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    int drow = _row;
    int dcol = m.col();
    Mat<T> dst(drow, dcol);
    for (int i = 0; i < drow; i++) {
        for (int j = 0; j < dcol; j++) {
            T sum = 0;
            for (int k = 0; k < _col; k++) {
                sum += mat[i][k] * m.at(k, j);
                //sum = 0;
            }
            dst.at(i, j) = sum;
        }
    }
    return dst;
}

template<class T, class T1>
Mat<T> operator*(const Mat<T>& m, const T1& k) {
    Mat<T> dst(m.row(), m.col());
    for (int i = 0; i < m.row(); i++) {
        for (int j = 0; j < m.col(); j++) {
            dst.at(i, j) = m.at(i, j) * k;
        }
    }
    return dst;
}

template<class T, class T1>
Mat<T> operator*(const T1& k, const Mat<T>& m) {
    Mat<T> dst(m.row(), m.col());
    for (int i = 0; i < m.row(); i++) {
        for (int j = 0; j < m.col(); j++) {
            dst.at(i, j) = m.at(i, j) * k;
        }
    }
    return dst;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Mat<T>& m) {
    for (int i = 0; i < m.row(); i++) {
        std::cout << "row" << i << ": ";
        for (int j = 0; j < m.col(); j++) {
            os << m.at(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

/******************************************************************************/