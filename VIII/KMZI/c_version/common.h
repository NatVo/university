#ifndef __COMMON_H__
#define __COMMON_H__
#include <iostream>
#include <vector>

template <typename Com> class Common
{
  private: 
    //int common;          
        
  public:
    void output_vector(std::vector<Com>& vect);          
    std::vector<Com> concat_vector(std::vector<Com> v1, std::vector<Com> v2);

};

#endif

