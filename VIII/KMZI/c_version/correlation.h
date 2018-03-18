#ifndef __CORRELATION_H__
#define __CORRELATION_H__

#include "common.h"
//#include "common.cpp"

#include <iostream>
#include <vector>

template <typename Cor> class Correlation : public Common<Cor>
{
  private: 
    std::string line;
    std::string line_full;
    int full_length;
    std::string generate_key(int max_length);
    
    long int correlation_element(std::string l, int stride, bool front);
    
    int hamming_dist(unsigned long long int number);
    std::string line_slice(std::string l, int start, int stride);
    std::string add_zeroes(std::string l, int full_length, bool begin);
    std::string add_string_part(std::string l, int chkpoint);
    int ceil_length(std::string l, int stride);
        
  public:
    Correlation (int max_length);
    Correlation(std::string input);

    std::vector<int> pakf(int stride);
    std::vector<int> aakf(int stride);


};

#endif

