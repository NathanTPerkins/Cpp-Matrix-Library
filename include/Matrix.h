#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace matrix{

    template <typename T, int w, int h>
    class matrix2d_t {
    private:
        T** __arr;
        int size;
        int width;
        int height;

    public:
        matrix2d_t();
        matrix2d_t(const matrix2d_t&);
        ~matrix2d_t();

        matrix2d_t& operator = (const matrix2d_t&);

        matrix2d_t& operator+(const matrix2d_t&);
        matrix2d_t& operator+(const T&);

        matrix2d_t& operator-(const matrix2d_t&);
        matrix2d_t& operator-(const T&);

        matrix2d_t<T,w,1>& operator[](const int&);
        T& operator[](const int&) const;

        int getWidth();
        int getHeight();

    
        friend matrix2d_t& operator+(T&, matrix2d_t&);
        friend matrix2d_t& operator-(T&, matrix2d_t&);

    };


};

template<typename T, int w, int h>
std::ostream& operator << (std::ostream& out, matrix::matrix2d_t<T,w,h>& m);





#endif