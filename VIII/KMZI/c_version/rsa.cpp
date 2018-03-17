
#include "common.h"
#include "common.cpp"
#include "rsa.h"

#include <iostream>
#include <bitset>

#include <set>
#include <vector>
#include <tuple>

template <typename R> RSA <R>::RSA()
{
    std::cout << "ОТСУТСТВУЮТ ЗНАЧЕНИЯ ПАРАМЕТРОВ\n" << std::endl;  
}

template <typename R> RSA <R>::RSA(std::string m, int prime1, int prime2)
{
    message = m;
    p1 = prime1;
    p2 = prime2;

    //std::cout << message << std::endl;
}

template <typename R> RSA <R>::RSA(int prime1, int prime2)
{
    message = common_rsa.read_file("message.txt");
    p1 = prime1;
    p2 = prime2;

//    std::cout << "message: \n" << message << std::endl;
}

template <typename R> RSA <R>::~RSA()
{
    //delete p1;
    //delete p2;
    //delete message;
}    

template <typename R> bool RSA <R>::check_input()
{
    std::tuple<bool, int> check_p1 = common_rsa.prime_check_simple(p1);
    std::tuple<bool, int> check_p2 = common_rsa.prime_check_simple(p2);

    //std::cout << std::get<0>(check_p1) << std::endl;

    if (std::get<0>(check_p1) == 1 && 
        std::get<0>(check_p2) == 1 && 
        message.empty() != 1) 
    { return 1; }
    else { return 0; }
       
}        
            

template <typename R> void RSA <R>::set_parameters()
{
    unsigned _N = p1 * p2;
    unsigned N = (p1 - 1) * (p2 - 1);
    
     
    std::cout << "_N = " << _N << " N = " << N << std::endl;    
		
    std::tuple<unsigned int, std::set<unsigned int>> euler;
    euler = common_rsa.euler_function(_N);
		unsigned int e_func = std::get<0>(euler);
    
    std::cout << "функция Эйлера для числа _N " << _N  << " : "<< e_func << std::endl;
    unsigned int e = common_rsa.atkin(N);
    std::cout << "число e: " << e << std::endl;
    unsigned int d = common_rsa.euklid_ext(N, e);
    std::cout << "число d: " << d << std::endl;

    common_rsa.write_file(333);

    //std::vector<unsigned> m_prime = common_rsa.mutually_prime_simple(N);
    //common_rsa.output_vector(m_prime);
}
