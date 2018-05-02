
#include "common.h"
#include "common.cpp"

#include "transmitter.h"

#include <iostream>
#include <bitset>

#include <set>
#include <vector>
#include <tuple>

#include <cmath>
#include <complex>

#include <iomanip>


/////////////////
#include <typeinfo>

template <typename T> Transmit <T>::Transmit()
{
    std::cout << "ОТСУТСТВУЮТ ЗНАЧЕНИЯ ПАРАМЕТРОВ\n" << std::endl;  
}

template <typename T> Transmit <T>::Transmit(std::string m1, 
                                             std::string m2, 
                                             int N_,
                                             int ch,
                                             int f,
                                             int p)
{

    message_1 = m1;
    message_2 = m2;

    N = N_;
    channels = ch;
    freq = f;
    period = p;

    if ((int) message_1.length() > (int) message_2.length())
    {
        message_2 = com_obj.add_zeroes(message_2, (int) message_1.length(), true);
    }
    else
    {
        message_1 = com_obj.add_zeroes(message_1, (int) message_2.length(), true);

    }

    std::cout << "message 1: " << message_1 << std::endl;
    std::cout << "message 2: " << message_2 << std::endl;
    std::cout << "N = " << N << std::endl;
   
}


template <typename T> Transmit <T>::~Transmit()
{
    //delete p1;
    //delete p2;
    //delete message;
}    

template <typename T> void Transmit <T>::code()
{
    std::vector<float> phi_1;
    std::vector<float> phi_2;
    std::vector<float> phi_3;

    std::vector<float> module;
    std::vector<float> argument;
    
    unsigned int num_samples = (1.0 / (float)freq) * period * (sampleRate * 2);
    short *data = new short[(int)message_1.length() * num_samples * N];
    
    std::tuple< std::vector<float>, std::vector<float> > result;

    std::cout << "amount = " << (int)message_1.length() * num_samples * N <<std::endl;

    unsigned int counter = 0;

    //bool FLAG = true;

    for (int i = 0; i < (int) message_1.length(); i++)
    {
        
        if (message_1[i] == '0') { phi_1 = phi(1); } else { phi_1 = phi(2); }
        if (message_2[i] == '0') { phi_2 = phi(3); } else { phi_2 = phi(4); }
        phi_3 = phi(5);
       
        //com_obj.output_vector(phi_1);
        //com_obj.output_vector(phi_2);
        

        result = gamma(phi_1, phi_2, phi_3);

        module = std::get<0>(result);
        argument = std::get<1>(result);

        //com_obj.output_vector(module);
        //com_obj.output_vector(argument);
        
        for (int i = 0; i < N; i ++)
        {
            for (int t = 0; t < num_samples; t++)
            {
                data[counter] = (short) (1000 * (float) module[i] * sin( (4 * pi * freq * t) / sampleRate + (float) argument[i]));
                counter += 1;
                //std::cout << data[t] << " ";
        
            }
        }
       
    } 
    //std::cout << "counter = " << counter << std::endl;   
    com_obj.write_wav(counter, data, sampleRate); 

}

template <typename T> std::vector<float> Transmit <T>::phi(int lambda)
{

    std::vector<float> phi;
    float element;

    for (int i = 0; i < N; i++)
    {
        element = (2 * pi * lambda * pow(i, 2)) / (float) N;
        //std::cout << std::setprecision(3) << element << std::endl;
        phi.push_back(element);
    }

    return phi;
}

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

/*
template <typename T> void Transmit <T>::output(std::vector<float> module, std::vector<float> argument, bool FLAG)
{
           
    //float element;
    unsigned int num_samples = (1.0 / (float)freq) * period * (sampleRate * 2);

    std::cout << "num_samples = " << num_samples << std::endl;
    std::cout << "gamma: " << std::endl;
    for (int i = 0; i < N; i ++)
    {
        float t = 0.0;
        short *data = new short[num_samples];
        //std::cout << module[i] << std::endl;
        for (int t = 0; t < num_samples; t++)
        {
            data[t] = (short) (1000 * (float) module[i] * sin( (4 * pi * freq * t) / sampleRate + (float) argument[i]));
            //element = 1000 * module[i] * sin(2 * pi * freq * t + argument[i]);
            //std::cout << "t = " << t << " ";
            //std::cout << element << " ";
            std::cout << data[t] << " ";
        
            //counter += 1;
            //t +=  1.0 / (float) sampleRate; 
        }
        std::cout << "\n\n\n\n" << std::endl;
        com_obj.write_wav(num_samples, data, sampleRate, FLAG); 
        //std::cout << "counter = " << counter << std::endl;

        FLAG = false;

        delete [] data;
        //counter = 0;
    
        //std::cout << "* ";
    }
 
}
*/
