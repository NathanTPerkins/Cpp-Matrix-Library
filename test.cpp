// #include "./src/Matrix.h"
#include <Vector.h>

int main(){
    matrix::vector_t<int,12> test;
    for(int i = 0; i < test.size(); ++i){
        test[i] = i;
    }

    for(int i = 0; i < test.size(); ++i){
        std::cout << i;
    }

    return 0;
}