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

    matrix2d_t<int, 2, 2> v1(1);
    v1[0][0] = 11;
    v1[0][1] = 3;
    v1[1][0] = 7;
    v1[1][1] = 11;

    matrix2d_t<int, 2, 3> v2(1);
    v2[0][0] = 8;
    v2[0][1] = 0;
    v2[0][2] = 1;
    v2[1][0] = 0;
    v2[1][1] = 3;
    v2[1][2] = 5;


    // v2 = v1;

    std::cout << v1 * v2 << std::endl;

    // matrix2d_t<int, 3, 3> m1(1);
    // matrix2d_t<int, 3,3> m2(2);

    // std::cout << m1 * m2<< std::endl;

    // matrix2d_t<int, 3, 3> m1(4);
    // matrix2d_t<int,3,3> m2 = m1;

    // std::cout << m2 <<std::endl;

    return 0;
}