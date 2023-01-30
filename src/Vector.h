#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<typename T, int length>
class vector_t{
private:
    T *__arr;
    int __length;

public:
    vector_t();
    ~vector_t();
    vector_t(const vector_t& v);

    int size();

    T& operator[](const int& idx);
    void operator=(const vector_t& v);

    friend std::ostream& operator << (std::ostream&, const vector_t&);


};

template<typename T, int length>
vector_t<T, length>::vector_t(){
    this->__length = length;
    this->__arr = (T*)malloc(sizeof(T) * length);
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
int vector_t<T, length>::size(){
    return this->__length;
}

template<typename T, int length>
T& vector_t<T, length>::operator[](const int& idx){
    return this->__arr[idx];
}

template<typename T, int length>
void vector_t<T, length>::operator=(const vector_t& v){
    this->__arr = v.__arr;
    this->__length = v.__length;
}

// template<typename T, int length>
// std::ostream& operator << (std::ostream& out, const vector_t<T, length>& v){
//     out << "{";
//     for(int i = 0; i < v.size() - 1; ++i){
//         out << v[i] << ",";
//     }
//     out << v[v.size() - 1] << "}";
//     return out;
// }


#endif