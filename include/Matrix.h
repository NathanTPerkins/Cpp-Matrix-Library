#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <Vector.h>

namespace matrix{

    template <typename T, int h, int w>
    class matrix2d_t {
    private:
        vector_t<T, w>* __arr;
        int __size;
        int __width;
        int __height;

    public:
        matrix2d_t();
        matrix2d_t(matrix2d_t&);
        ~matrix2d_t();

        int size()const;

        matrix2d_t& operator = (const matrix2d_t&);

        matrix2d_t& operator+(const matrix2d_t&);
        matrix2d_t& operator+(const T&);

        matrix2d_t& operator-(const matrix2d_t&);
        matrix2d_t& operator-(const T&);

        vector_t<T, w>& operator[](const int&)const;
    
        // friend matrix2d_t& operator+(T&, matrix2d_t&);
        // friend matrix2d_t& operator-(T&, matrix2d_t&);

    };

    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::matrix2d_t(){
        this->__width = w;
        this->__height = h;
        this->__size = w * h;
        this->__arr = new vector_t<T, w>[h];
        
    }

    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::matrix2d_t(matrix2d_t& m){
        if(m.size() == this->__height){
            if(m[0].size() == this->__width){
                this->__width = w;
                this->__height = h;
                this->__size = w * h;
                this->__arr = new vector_t<T, w>[h];
            }
        }
    }

    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::~matrix2d_t(){
        delete[] this->__arr;
    }

    template<typename T, int h, int w>
    int matrix2d_t<T, h, w>::size()const{
        return this->__height;
    }

    template<typename T, int h, int w>
    vector_t<T, w>& matrix2d_t<T, h, w>::operator[](const int & idx) const {
        return this->__arr[idx];
    }


};

template<typename T, int h, int w>
std::ostream& operator << (std::ostream& out, matrix::matrix2d_t<T,w,h>& m){
    out << "{";
    for(int i = 0; i < m.size() - 1; ++i){
        out << m[i];
        out << ",";
    }
    out << m[m.size() - 1];
    out << "}";
    return out;

}





#endif