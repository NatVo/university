#include "common.h"

#include <iostream>
#include <vector>

template <typename Com> void Common <Com>::output_vector(std::vector<Com>& vect)
{
    for (unsigned int i = 0; i < vect.size(); i++)
    {        
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Com> std::vector<Com> Common <Com>::concat_vector(std::vector<Com> v1, std::vector<Com> v2)
{

    v1.insert( v1.end(), v2.begin(), v2.end());    
    return v1;
        
}

