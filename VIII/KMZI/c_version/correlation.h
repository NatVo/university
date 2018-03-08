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

    std::string generate_key();
    
    std::vector<int> pakf(std::string l);
    std::vector<int> aakf(std::string l);
    
    int hamming_dist(unsigned long long int number);
    std::string line_slice(std::string l, int start, int stride);
    std::string add_zeroes(std::string l, int stride);
    std::string add_string_part(std::string l, int chkpoint);
        
  public:
    Correlation ();
    Correlation(Cor input);
    void iter_seq(int stride, bool flag);

};

#endif

