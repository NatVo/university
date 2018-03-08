#ifndef __COMMON_H__
#define __COMMON_H__
#include <iostream>
#include <vector>

template <typename Com> class Common
{
  private: 
    //int common;          
        
  public:
    
    void output_vector(std::vector<Com> vect);          
    std::vector<Com> concat_vector(std::vector<Com> v1, std::vector<Com> v2);
    
    std::string read_file(std::string file_path); 

    std::tuple<Com, Com> prime_check_simple(unsigned int number);
    std::vector<Com> mutually_prime_simple(unsigned int number);
    unsigned int gcd_simple(unsigned int number1, unsigned int number2);

    int euklid_ext(int a, int b);
    
    unsigned int euler_count_help(std::vector<unsigned int> vect, int ch);
    unsigned int euler_function(unsigned int number);
};

#endif

