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
    const int test = 3;
    matrix::vector_t<int, 3> mat;
    std::cout << 10 + mat << std::endl;


    return 0;
}