// #include "./src/Matrix.h"
#include <Vector.h>
#include <Matrix.h>

int main(){
    // matrix::matrix2d_t<int, 3, 3> test;
    // for(int i = 0;  i < 3; ++i){
    // for(int j = 0; j < 3; ++j){
    //     test[i][j] = i;
    // }
    // }

    // //    matrix::matrix2d_t<int, 3, 3> test2 = test;

    // std::cout << test << std::endl;
    // //    std::cout << test2 <<std::endl;

    // int a[3] = {1,2,3};
    using matrix::vector_t;
    using matrix::matrix2d_t;

    vector_t<int, 3> v1(9);
    vector_t<int, 3> v2;

    // v1 = v2;

    std::cout << v1 << v2 << std::endl;

    matrix2d_t<int, 3, 3> m1(1);
    matrix2d_t<int, 3,3> m2;

    // m2 = m1;

    std::cout << m1 << m2 << std::endl;

    // matrix2d_t<int, 3, 3> m1(4);
    // matrix2d_t<int,3,3> m2 = m1;

    // std::cout << m2 <<std::endl;

    return 0;
}