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
    long long int p1;    
    long long int p2;
    
    Common<unsigned> common_rsa;

  public:
    RSA();
    RSA(std::string m, int prime1, int prime2);
    RSA(int prime1, int prime2);

    ~RSA();

    bool check_input();

    void set_parameters();
    
};

#endif

