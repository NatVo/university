#include "common.h"

#include <iostream>
#include <cmath>

#include <set>
#include <vector>
#include <tuple>
#include <iterator>

#include <fstream>
#include <sstream>

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

template <typename Com> std::string Common<Com>::read_file(std::string file_path)
{
    
    std::ifstream f(file_path);
    std::stringstream message;
    message << f.rdbuf();
    
    return message.str();
}    

template <typename Com> std::tuple<Com, Com> Common <Com>::prime_check_simple(unsigned int number)
{		
		std::tuple<bool, int> result;

    if (number < 1) { return {0, 0}; }
    else
    {
        int i = 2;
        while (i < round(sqrt(number) + 1) )
        {
            if ((number % i) == 0) 
						{ 
								return {0, i}; 
								break; 
						}
            i++;
        }

        return {1, 0};
    }

}      

template <typename Com> unsigned int Common <Com>::gcd_simple(unsigned int number1, unsigned int number2)
{
   while ( number2 != 0)
   {
        unsigned result = number1 % number2;
        number1 = number2;
        number2 = result;
   }
   return number1;

}

template <typename Com> std::vector<Com> Common <Com>::mutually_prime_simple(unsigned int number)
{
    std::vector<Com> mpr_list;

    for (int i = 1; i < number; i++)
    {
       //if (std::__gcd(i, number) == 1) { mpr_list.push_back(i); }
       if (gcd_simple(number, i) == 1) { mpr_list.push_back(i); }

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

////////////////////////////////
// 					EULER  					 //
///////////////////////////////

template <typename Com> unsigned int Common<Com>::euler_count_help(std::vector<unsigned int> vect, int ch)
{
		unsigned int P = 1;

		std::set<unsigned int> unique_v(vect.begin(), vect.end());
		std::set<unsigned int>::iterator i = unique_v.begin();
		
		while (i != unique_v.end())
		{
				P *= ((*i) - ch);
				i++;
		}
		return P;
}

template <typename Com> unsigned int Common <Com>::euler_function(unsigned int number)
{
		std::vector<unsigned int> fact;

		std::tuple<bool, int> p_test = prime_check_simple(number);
		bool prime = std::get<0>(p_test);
		int div = std::get<1>(p_test);

		if ( !prime )
		{
				fact.push_back(div);

				while ( !prime )
				{
						number = number / div;
						
						std::tuple<bool, int> p_test = prime_check_simple(number);
						prime = std::get<0>(p_test);
						div = std::get<1>(p_test);

						//std::cout << div << " ";

						if (div != 0) { fact.push_back(div); }

				}
				//std::cout << std::endl;
				fact.push_back(number);
				//output_vector(fact);

				unsigned int P1 = euler_count_help(fact, 0);
				unsigned int P2 = euler_count_help(fact, 1);

				//std::cout << "P1 = " << P1 << std::endl;
				//std::cout << "P2 = " << P2 << std::endl;
				return P1 * P2;
		}

}


