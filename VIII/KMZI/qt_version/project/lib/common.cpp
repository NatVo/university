#include "common.h"

#include <iostream>
#include <vector>
#include <algorithm>

//template <typename Com> void Common <Com>::output_vector(std::vector<Com>& vect)
template <typename Com> void Common <Com>::output_vector(std::vector<Com> vect)
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

template <typename Com> std::tuple<Com> Common <Com>::prime_check_simple(int number)
{
    std::tuple<bool, int> result;
    /*
    if (number < 1):
        std::cout << "ЧИСЛО < 1!" << std::endl;
        return 0;
    */     
}      



template <typename Com> std::vector<Com> Common <Com>::mutually_prime_simple(int number)
{
    std::vector<Com> mpr_list;

    for (int i = 1; i < number; i++)
    {
       if (std::__gcd(i, number) == 1) { mpr_list.push_back(i); }
    }

    output_vector(mpr_list);
   
    return mpr_list;    
}

template <typename Com> int Common <Com>::euklid_ext(int a, int b)
{
    int t1 = 0;
    int t2 = 1;
    int r = 1;

    while (r != 0)
    {
        r = a % b;
        int c = a / b;
        
        int t3 = t1 - t2 * c;
        a = b;
        b = r;
        t1 = t2;
        t2 = t3;
    }

    if (t1 < 0) { return (t2 + t1); }
    else { return t1; }
}
