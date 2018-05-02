
#include "common.h"
#include "common.cpp"

#include "receiver.h"

#include <iostream>
#include <bitset>

#include <set>
#include <vector>
#include <tuple>

#include <cmath>
#include <complex>

#include <iomanip>


template <typename R> Receive <R>::Receive()
{
    std::cout << "ОТСУТСТВУЮТ ЗНАЧЕНИЯ ПАРАМЕТРОВ\n" << std::endl;  
}

template <typename R> Receive <R>::Receive(int N_, int ch, int f, int p)
{


    N = N_;
    channels = ch;
    freq = f;
    period = p;

    std::cout << "N = " << N << std::endl;
   
}


template <typename R> Receive <R>::~Receive()
{
    //delete p1;
    //delete p2;
    //delete message;
}    

template <typename R> void Receive <R>::decode()
{
    com_obj.wav_reader();     
    //com_obj.WavReader();
}

template <typename R> std::vector<float> Receive <R>::phi(int lambda)
{

    std::vector<float> phi;
    float element;

    for (int i = 0; i < N; i++)
    {
        element = (2 * pi * lambda * pow(i, 2)) / (float) N;
        phi.push_back(element);
    }

    return phi;
}

/*
template <typename T> std::tuple< std::vector<float>, 
                                  std::vector<float> > Transmit <T>::gamma(
                                                           std::vector<float> phi_1, 
                                                           std::vector<float> phi_2,
                                                           std::vector<float> phi_3)
{
    //std::tuple< std::vector<float>, std::vector<float> >;
    
    std::complex<float> i(0, 1);    
    std::complex<float> el_1;
    std::complex<float> el_2;
    std::complex<float> el_3;

    std::complex<float> element;

    std::vector<float> res_1;
    std::vector<float> res_2;

    for (int counter = 0; counter < N; counter++)
    {
        el_1 = std::exp(i * phi_1[counter]);
        el_2 = std::exp(i * phi_2[counter]);
        el_3 = std::exp(i * phi_3[counter]);

        element = el_1 + el_2 + el_3;

        //std::cout << element << " ";

        res_1.push_back(std::abs(element));
        res_2.push_back(std::arg(element));
    }
    //std::cout << std::endl;
          
    return {res_1, res_2};
}
*/
