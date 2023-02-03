#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

namespace matrix{
    template<typename T, int length>
    class vector_t{
    private:
        T *__arr;
        int __length;

    public:
        vector_t();
        vector_t(T*);
        ~vector_t();
        vector_t(const vector_t&);
        vector_t(const T&);

        int size()const;
        double mag() const;
        void fill(const T&);
        void fill(const T&&);
        T& dot(const vector_t&) const;
        // vector_t<T, length>& cross(const vector_t&) const; TODO



        T& operator[](int& idx)const;
        T& operator[](int&& idx)const;
        void operator=(const vector_t& v);
        vector_t<T, length>& operator +(const vector_t&)const;
        vector_t<T, length>& operator -(const vector_t&)const;
        vector_t<T, length>& operator +(const T&)const;
        vector_t<T, length>& operator -(const T&)const;
        // vector_t<T, length>& operator /(const vector_t&); TODO
        T& operator *(const vector_t&)const;
        vector_t<T, length>& operator *(const T&)const;

    };


    //DEFAULT CONSTRUCTOR
    template<typename T, int length>
    vector_t<T, length>::vector_t(){
        this->__length = length;
        this->__arr = new T[length];
    }

    //ARRAY CONSTRUCTOR
    template<typename T, int length>
    vector_t<T, length>::vector_t(T* v){
        this->__length = length;
        this->__arr = new T[length];
        for(int i = 0; i < length; i++){
            this->__arr[i] = v[i];
        }
    }

    //DESTRUCTOR
    template<typename T, int length>
    vector_t<T, length>::~vector_t(){
        delete[] this->__arr;
        this->__arr = nullptr;
    }

    //COPY CONSTRUCTOR
    template<typename T, int length>
    vector_t<T, length>::vector_t(const vector_t& v){
        this->__length = length;
        this->__arr = new T[length];
        for(int i = 0; i < length; ++i){
            this->__arr[i] = v[i];
        }
    }

    //FILL CONSTRUCTOR
    template<typename T, int length>
    vector_t<T, length>::vector_t(const T& num){
        this->__length = length;
        this->__arr = new T[length];
        for(int i = 0; i < length; ++i){
            this->__arr[i] = num;
        }
    }

    //SIZE METHOD
    template<typename T, int length>
    int vector_t<T, length>::size()const{
        return this->__length;
    }

    //MAGNITUDE METHOD
    template<typename T, int length>
    double vector_t<T, length>::mag() const {
        double ins = 0;
        for(int i = 0; i < this->__length; ++i){
            ins += pow(this->__arr[i], 2);
        }
        return sqrt(ins);
    }

    //FILL METHOD
    template<typename T, int length>
    void vector_t<T, length>::fill(const T& num){
        for(int i = 0; i < length; ++i){
            this->__arr[i] = num;
        }
    }

    //FILL METHOD
    template<typename T, int length>
    void vector_t<T, length>::fill(const T&& num){
        for(int i = 0; i < length; ++i){
            this->__arr[i] = num;
        }
    }

    //DOT PRODUCT FUNCTION
    template<typename T, int length>
    T& vector_t<T, length>::dot(const vector_t& v)const{
        return (*this) * v;
    }

    //LVALUE ARRAY INDEX OPERATOR
    template<typename T, int length>
    T& vector_t<T, length>::operator[](int& idx)const{
        return this->__arr[idx];
    }

    //RVALUE ARRAY INDEX OPERATOR
    template<typename T, int length>
    T& vector_t<T, length>::operator[](int&& idx)const{
        return this->__arr[idx];
    }

    //ASSIGNMENT OPERATOR
    template<typename T, int length>
    void vector_t<T, length>::operator=(const vector_t& v){
        this->__arr = new T[length];
        for(int i = 0; i < length; ++i){
            this->__arr[i] = v[i];
        }
        this->__length = v.__length;
    }

    //VECTOR ADDITION
    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator+(const vector_t& v)const{
        vector_t<T, length>* temp = new vector_t<T, length>();
        if(this->__length == v.size()){
            for(int i = 0; i < length; ++i){
                (*temp)[i] = this->__arr[i] + v[i];
            }
        }
        return *temp;
    }

    //VECTOR SUBTRACTION
    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator-(const vector_t& v)const{
        vector_t<T, length>* temp = new vector_t<T, length>();
        if(this->__length == v.size()){
            for(int i = 0; i < length; ++i){
                (*temp)[i] = this->__arr[i] - v[i];
            }
        }
        return *temp;
    }

    //VECTOR ADDITION
    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator+(const T& num)const{
        vector_t<T, length>* temp = new vector_t<T, length>();
        for(int i = 0; i < length; ++i){
            (*temp)[i] = this->__arr[i] + num;
        }
        return *temp;
    }

    //VECTOR SUBTRACTION
    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator-(const T& num)const{
        vector_t<T, length>* temp = new vector_t<T, length>();
        for(int i = 0; i < length; ++i){
            (*temp)[i] = this->__arr[i] - num;
        }
        return *temp;
    }

    //DOT PRODUCT OPERATOR
    template<typename T, int length>
    T& vector_t<T, length>::operator*(const vector_t& v)const{
        T *temp = new T;
        if(this->__length == v.size()){
            for(int i = 0; i < length; ++i){
                *temp += this->__arr[i] * v[i];
            }
        }
        return *temp;
    }


    //VECTOR MULTIPLICATION WITH SCALAR
    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator *(const T& num)const{
        vector_t<T, length> *temp = new vector_t<T, length>();
        for(int i = 0; i < length; ++i){
            (*temp)[i] = this->__arr[i] * num;
        }
        return *temp;
    }
};

//VECTOR ADDITION
template<typename T, int length>
matrix::vector_t<T, length>& operator +(const T& num, const matrix::vector_t<T, length>& vector){
    matrix::vector_t<T, length>* temp = new matrix::vector_t<T, length>();
    for(int i = 0; i < length; ++i){
        (*temp)[i] = num + vector[i];
    }
    return *temp;
}

//VECTOR SUBTRACTION
template<typename T, int length>
matrix::vector_t<T, length>& operator -(const T& num, const matrix::vector_t<T, length>& vector){
    matrix::vector_t<T, length>* temp = new matrix::vector_t<T, length>();
    for(int i = 0; i < length; ++i){
        (*temp)[i] = num - vector[i];
    }
    return *temp;
}

//VECTOR MULTIPLICATION WITH SCALAR
template<typename T, int length>
matrix::vector_t<T, length>& operator *(const T& num, const matrix::vector_t<T, length>& vector){
    matrix::vector_t<T, length> *temp = new matrix::vector_t<T, length>();
    for(int i = 0; i < length; ++i){
        (*temp)[i] = vector[i] * num;
    }
    return *temp;
}

//COUT OVERLOAD
template<typename T, int length>
std::ostream& operator << (std::ostream& out, const matrix::vector_t<T, length>& vector){
    out << "{";
    for(int i = 0; i < vector.size() - 1; ++i){
        out << vector[i] << ",";
    }
    out << vector[vector.size() - 1] << "}";
    return out;
}

#endif