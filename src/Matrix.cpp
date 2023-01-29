#include "Matrix.h"

namespace matrix{

template<typename T, int w, int h>
matrix2d_t<T, w, h>::matrix2d_t(){
    this->width;
    this->height;
    this->__arr = new T[h][w];
    this->size = w*h;
}

template<typename T, int w, int h>
matrix2d_t<T, w, h>::matrix2d_t(const matrix2d_t& mat){
    if(mat.getHeight() == h && mat.getWidth() == w){
        for(int i = 0; i < h;++i){
            for(int j = 0; j < w; ++j){
                this->arr[i][j] = mat[i][j];
            }
        }
    }
}

template<typename T, int w, int h>
T& matrix2d_t<T,w,h>::operator[](const int& idx) const {
    return this->__arr[idx];
}

template<typename T,int w,int h>
matrix2d_t<T,w,1>& matrix2d_t<T,w,h>::operator[](const int& idx){
    return this->__arr[idx];
}

template<typename T, int w, int h>
int matrix2d_t<T,w,h>::getWidth(){
    return this->width;
}

template<typename T, int w, int h>
int matrix2d_t<T,w,h>::getHeight(){
    return this->height;

}

template<typename T, int w, int h>
matrix2d_t<T,w,h>::~matrix2d_t(){
    
}

};

template<typename T, int w, int h>
std::ostream& operator<<(std::ostream& out, matrix::matrix2d_t<T, w, h>& m){
    out << "Cool";
    return out;
}