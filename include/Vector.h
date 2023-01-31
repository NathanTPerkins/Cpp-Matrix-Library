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

        int size()const;
        double mag() const;
        T& dot(const vector_t&) const;
        // vector_t<T, length>& cross(const vector_t&) const; TODO



        T& operator[](int& idx)const;
        T& operator[](int&& idx)const;
        void operator=(const vector_t& v);
        vector_t<T, length>& operator +(const vector_t&);
        vector_t<T, length>& operator -(const vector_t&);
        // vector_t<T, length>& operator /(const vector_t&); TODO
        T& operator *(const vector_t&)const;


    };

    template<typename T, int length>
    vector_t<T, length>::vector_t(){
        std::cout << "THis is vector" << std::endl;
        this->__length = length;
        this->__arr = (T*)malloc(sizeof(T) * length);
    }

    template<typename T, int length>
    vector_t<T, length>::vector_t(T* v){
        this->__length = length;
        this->__arr = (T*)malloc(sizeof(*v) * length);
        for(int i = 0; i < length; i++){
            this->__arr[i] = v[i];
        }
    }

    template<typename T, int length>
    vector_t<T, length>::~vector_t(){
        free(this->__arr);
    }

    template<typename T, int length>
    vector_t<T, length>::vector_t(const vector_t& v){
        this->__arr = v.__arr;
        this->__length = v.__length;
    }

    template<typename T, int length>
    int vector_t<T, length>::size()const{
        return this->__length;
    }

    template<typename T, int length>
    double vector_t<T, length>::mag() const {
        double ins = 0;
        for(int i = 0; i < this->__length; ++i){
            ins += pow(this->__arr[i], 2);
        }
        return sqrt(ins);
    }

    template<typename T, int length>
    T& vector_t<T, length>::dot(const vector_t& v)const{
        return (*this) * v;
    }

    template<typename T, int length>
    T& vector_t<T, length>::operator[](int& idx)const{
        return this->__arr[idx];
    }

    template<typename T, int length>
    T& vector_t<T, length>::operator[](int&& idx)const{
        return this->__arr[idx];
    }

    template<typename T, int length>
    void vector_t<T, length>::operator=(const vector_t& v){
        this->__arr = v.__arr;
        this->__length = v.__length;
    }

    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator+(const vector_t& v){
        vector_t<T, length>* temp = new vector_t<T, length>();
        if(this->__length == v.size()){
            for(int i = 0; i < length; ++i){
                (*temp)[i] = this->__arr[i] + v[i];
            }
        }
        return *temp;
    }

    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator-(const vector_t& v){
        vector_t<T, length>* temp = new vector_t<T, length>();
        if(this->__length == v.size()){
            for(int i = 0; i < length; ++i){
                (*temp)[i] = this->__arr[i] - v[i];
            }
        }
        return *temp;
    }

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
};

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