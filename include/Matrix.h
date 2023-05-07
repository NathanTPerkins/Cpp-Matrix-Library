#ifndef MATRIX_HPP
#define MATRIX_HPP

#ifdef COUT_OVERLOAD
#include <iostream>
#endif
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
        matrix2d_t(const matrix2d_t&);
        virtual ~matrix2d_t();
        matrix2d_t(const T&);

        int size()const;
        int width()const;
        int height()const;
        int elements()const;
        void fill(const T&);

        matrix2d_t& operator = (const matrix2d_t&);

        matrix2d_t& operator+(const matrix2d_t&);
        matrix2d_t& operator+(const T&);

        matrix2d_t& operator-(const matrix2d_t&);
        matrix2d_t& operator-(const T&);

        matrix2d_t& operator*(const T&);

        vector_t<T, w>& operator[](const int&)const;

    };

    //DEFAULT CONSTRUCTOR
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::matrix2d_t(){
        this->__width = w;
        this->__height = h;
        this->__size = w * h;
        this->__arr = new vector_t<T, w>[h];
    }

    //COPY CONSTRUCTOR
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::matrix2d_t(const matrix2d_t& m){
        if(m.size() == this->__height){
            if(m[0].size() == this->__width){
                this->__width = w;
                this->__height = h;
                this->__size = w * h;
                this->__arr = new vector_t<T, w>[h];
                for(int i = 0; i < h; ++i){
                    this->__arr[i] = m[i];
                }
            }
        }
    }

    //DESTRUCTOR
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::~matrix2d_t(){
        delete[] this->__arr;
        this->__arr = nullptr;
    }

    //FILL CONSTRUCTOR
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>::matrix2d_t(const T& num){
        this->__width = w;
        this->__height = h;
        this->__size = w * h;
        this->__arr = new vector_t<T, w>[h];
        for(int i = 0; i < h; ++i){
            this->__arr[i].fill(num);
        }
    }

    //SIZE METHOD
    template<typename T, int h, int w>
    int matrix2d_t<T, h, w>::size()const{
        return this->__height;
    }

    //WIDTH GETTER
    template<typename T, int h, int w>
    int matrix2d_t<T, h, w>::width()const{
        return this->__width;
    }

    //HEIGHT GETTER
    template<typename T, int h, int w>
    int matrix2d_t<T, h, w>::height()const{
        return this->__height;
    }

    //ELEMENTS GETTER
    template<typename T, int h, int w>
    int matrix2d_t<T, h, w>::elements()const{
        return this->__width * this->height;
    }

    //FILL METHOD
    template<typename T, int h, int w>
    void matrix2d_t<T, h, w>::fill(const T& num){
        for(int i = 0; i < h; ++i){
            this->__arr[i].fill(num);
        }
    }

    //MATRIX INDEXING OPERATOR
    template<typename T, int h, int w>
    vector_t<T, w>& matrix2d_t<T, h, w>::operator[](const int & idx) const {
        return this->__arr[idx];
    }

    //ASSIGNMENT OPERATOR
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator=(const matrix2d_t& m){
        this->__size = m.__size;
        this->__width = m.__width;
        this->__height = m.__height;
        this->__arr = new vector_t<T, m.__width>[m.__height];
        for(int i = 0; i < h; ++i){
            this->__arr[i] = m[i];
        }
        return *this;
    }

    //MATRIX ADDITION
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator+(const matrix2d_t<T, h, w>& m){
        matrix2d_t<T, h, w>* temp = new matrix2d_t();
        for(int i = 0; i < h; ++i){
            (*temp)[i] = this->__arr[i] + m[i];
        }
        return *temp;
    }

    //MATRIX ADDITION
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator+(const T& num){
        matrix2d_t<T, h, w>* temp = new matrix2d_t();
        for(int i = 0; i < h; ++i){
            (*temp)[i] = this->__arr[i] + num;
        }
        return *temp;
    }

    //MATRIX SUBTRACTION
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator-(const matrix2d_t<T, h, w>& m){
        matrix2d_t<T, h, w>* temp = new matrix2d_t();
        for(int i = 0; i < h; ++i){
            (*temp)[i] = this->__arr[i] - m[i];
        }
        return *temp;
    }

    //MATRIX SUBTRACTION
    template<typename T, int h, int w>
    matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator-(const T& num){
        matrix2d_t<T, h, w>* temp = new matrix2d_t();
        for(int i = 0; i < h; ++i){
            (*temp)[i] = this->__arr[i] - num;
        }
        return *temp;
    }

    //MATRIX MULTIPLICATION
    // template<typename T, int h, int w>
    // matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator*(const T& num){
    //     matrix2d_t<T, h, w> *temp = new matrix2d_t<T, h, w>();
    //     for(int i = 0; i < h; ++i){
    //         (*temp)[i] = this->__arr[i] * num;
    //     }
    //     return *temp;
    // }


};


//MATRIX MULTIPLICATION
// using matrix::matrix2d_t;
// template<typename T, int h, int w>
// matrix2d_t<T, h, w>& matrix2d_t<T, h, w>::operator*(const T& num, const matrix2d_t<T, h, w>& m){
//     matrix2d_t<T, h, w>* temp = new matrix2d_t<T, h, w>();
//     return *temp;
// }

#ifdef COUT_OVERLOAD
//COUT OPERATOR OVERLOAD
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





#endif