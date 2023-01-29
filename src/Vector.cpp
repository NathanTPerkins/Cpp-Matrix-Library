#include "Vector.h"


namespace matrix{

    template<typename T, int length>
    vector_t<T, length>::vector_t(){
        this->length = length;
        this->__arr = new T[length];
    }

    template<typename T, int length>
    vector_t<T, length>::~vector_t(){
        delete[] this->__arr;
    }

    template<typename T, int length>
    int vector_t<T, length>::size(){
        return this->__length;
    }

    template<typename T, int length>
    T& vector_t<T, length>::operator[](const int& idx){
        return this->__arr[idx];
    }

    template<typename T, int length>
    vector_t<T, length>& vector_t<T, length>::operator=(const vector_t& v){
        this->__arr = v.__arr;
        this->__length = v.__length;
    }


};

template<typename T, int length>
std::ostream& operator << (std::ostream& out, const matrix::vector_t<T, length>& v){
    out << "{";
    for(int i = 0; i < v.size() - 1; ++i){
        out << v[i] << ",";
    }
    out << v[v.size() - 1] << "}";
    return out;
}