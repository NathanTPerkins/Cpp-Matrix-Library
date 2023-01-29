#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
namespace matrix{
    template<typename T, int length>
    class vector_t{

    private:
        T *__arr;
        int __length;

    public:
        vector_t();
        ~vector_t();
        vector_t(const vector_t&);

        int size();

        T& operator[](const int&);
        vector_t<T, length> &operator=(const vector_t&);

        friend std::ostream& operator << (std::ostream&, const vector_t&);


    };


};

#endif