#ifndef __RSA_H__
#define __RSA_H__

#include "common.h"
//#include "common.cpp"

#include <iostream>
#include <vector>

template <typename R> class RSA : public Common<R>
{
  private:
    std::string message;
    int p1;    
    int p2;
        
  public:
    RSA();
    RSA(std::string m, int p1, int p2);
    
};

#endif

