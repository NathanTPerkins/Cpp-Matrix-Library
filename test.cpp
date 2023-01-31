// #include "./src/Matrix.h"
#include <Vector.h>

int main(){
    matrix::vector_t<int,12> test;
    for(int i = 0; i < test.size(); ++i){
        test[i] = i;
    }

    std::cout << test << std::endl;

    std::cout << test.mag() << std::endl;

    matrix::vector_t<int,12> test2;
    for(int i = 0; i < test2.size(); ++i){
        test2[i] = i;
    }

    std::cout << test2 << std::endl;

    std::cout << test2.mag() <<std::endl;

    std::cout << test + test2 <<std::endl;

    std::cout << test - test2 << std::endl;

    std::cout << test * test2 << std::endl;

    std::cout << test.dot(test2) << std::endl;

    return 0;
}