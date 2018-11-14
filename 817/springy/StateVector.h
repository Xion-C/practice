#ifndef __STATEVECTOR_H__
#define __STATEVECTOR_H__

#include <cstring>
#include <iostream>
#include "Utility.h"

template<class T>
class StateVector
{
public:
    int N; // particle numbers
    T* data;

    StateVector(int n);
    StateVector(const StateVector&);

    ~StateVector();

    StateVector<T>& operator=(const StateVector<T> &s);

    template<class Y>
    friend std::ostream& operator<<(std::ostream& os, const StateVector<Y>& s);

    StateVector<T> operator+(const StateVector<T>& s) const;
    StateVector<T> operator-(const StateVector<T>& s) const;
    StateVector<T> operator*(float k) const;
    template<class Y>
    friend StateVector<Y> operator*(float k, const StateVector<Y>& s);

};


template<class T>
StateVector<T>::StateVector(int n) :
    N(n)
{
    if(n > 0)
    {
        data = new T[2 * N];
        memset(data, 0, N * 2 * sizeof(T));
    }
    else
    {
        error("not valid size");
        n = 0;
        data = nullptr;
    }
}

template<class T>
StateVector<T>::StateVector(const StateVector& s) :
    N(s.N)
{
    data = new T[s.N * 2];
    memcpy(data, s.data, N * 2 * sizeof(T));
}

template<class T>
StateVector<T>::~StateVector()
{
    delete[] data;
}


template<class T>
StateVector<T>& StateVector<T>::operator=(const StateVector<T> &s)
{
    if(&s == this) return *this;
    if(N != s.N)
    {
        N = s.N;
        delete[] data;
        data = new T[N * 2];
    }
    memcpy(data, s.data, N * 2 * sizeof(T));

    return *this;
}

template<class T>
StateVector<T> StateVector<T>::operator+(const StateVector<T>& s) const
{
    if(N != s.N)
    {
        error("not same size ");
        return StateVector<T>(0);
    }
    StateVector<T> res(N);
    for(int i = 0; i < 2 * N; i++)
    {
        res.data[i] = data[i] + s.data[i];
    }

    return res;
}
template<class T>
StateVector<T> StateVector<T>::operator-(const StateVector<T>& s) const
{
    if(N != s.N)
    {
        error("not same size ");
        return StateVector<T>(0);
    }
    StateVector<T> res(N);
    for(int i = 0; i < 2 * N; i++)
    {
        res.data[i] = data[i] - s.data[i];
    }
    return res;

}
template<class T>
StateVector<T> StateVector<T>::operator*(float k) const
{
    StateVector<T> res(N);
    for(int i = 0; i < 2 * N; i++)
    {
        res.data[i] = data[i] * k;
    }
    return res;
}


template<class Y>
std::ostream& operator<<(std::ostream& os, const StateVector<Y>& s)
{
    if(s.N == 0) return os << "empty" << std::endl;
    else
    {
        os << "[ " << s.data[0] << "," << std::endl;
        for(int i = 1; i < 2 * s.N; i++)
        {
            os << "  " << s.data[i];
            if(i != 2 * s.N - 1) os << "," << std::endl;
        }
        os << " ]" << std::endl;
    }
    return os;
}

template<class Y>
StateVector<Y> operator*(float k, const StateVector<Y>& s)
{
    return s * k;
}


#endif
