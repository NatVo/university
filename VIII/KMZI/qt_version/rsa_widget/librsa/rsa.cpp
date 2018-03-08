
#include "common.h"
#include "common.cpp"
#include "rsa.h"

#include <iostream>
#include <bitset>
#include <vector>

template <typename R> RSA <R>::RSA()
{
    std::cout << "ОТСУТСТВУЮТ ЗНАЧЕНИЯ ПАРАМЕТРОВ\n" << std::endl;  
}

template <typename R> RSA <R>::RSA(std::string m, int p1, int p2)
{
    message = m;
    p1 = p1;
    p2 = p2;

    std::cout << message << std::endl;
}
        
            


