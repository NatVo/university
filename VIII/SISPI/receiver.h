#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "common.h"

#include <iostream>
#include <vector>

#include <complex>

template <typename R> class Receive
{
  private:
    int N;
    int channels;
    int freq;
    int period;
    float pi = 3.1415926;

    unsigned int sampleRate = 44100;
    Common<float> com_obj;

    std::vector<float> phi(int lambda);

  public:      
    Receive();
    Receive(int N_, int ch, int f, int p);

    ~Receive();
    void decode();
    
};

#endif

