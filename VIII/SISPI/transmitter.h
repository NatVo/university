#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__

#include "common.h"

#include <iostream>
#include <vector>

#include <complex>

template <typename T> class Transmit
{
  private:
    std::string message_1;
    std::string message_2;

    int N;
    int channels;
    int freq;
    int period;
    float pi = 3.1415926;

    unsigned int sampleRate = 44100;

    Common<float> com_obj;
    std::vector<float> phi(int lambda);
    std::tuple< std::vector<float>,
                std::vector<float> > gamma(
                                      std::vector<float> phi_1, 
                                      std::vector<float> phi_2,
                                      std::vector<float> phi_3);

    //void output(std::vector<float> module, std::vector<float> argument, bool FLAG);

  public:      
    Transmit();
    Transmit(std::string m1, 
             std::string m2, 
             int N_, 
             int ch, 
             int f, 
             int p);

    ~Transmit();
    void code();
    
};

#endif

