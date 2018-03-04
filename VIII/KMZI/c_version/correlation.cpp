
#include "common.h"
#include "common.cpp"
#include "correlation.h"

#include <iostream>
#include <bitset>
#include <vector>
#include <smmintrin.h>

template <typename Cor> Correlation <Cor>::Correlation()
{
    std::cout << "\nСГЕНЕРИРОВАННЫЙ КЛЮЧ: \n" << std::endl;
    line = generate_key();
    std::cout << line << std::endl;
    
    //std::bitset<64> sub_str = line_slice(line, 0, 64);
    //std::cout << "\n" << sub_str << std::endl;

}

template <typename Cor> Correlation <Cor>::Correlation(Cor input)
{
    line = input;
    if (line.length() < 1024) { line = add_zeroes(line, 1024); }
    
    std::cout << line << std::endl;
}

template <typename Cor> void Correlation <Cor>::iter_seq(int stride)
{
    int start = 0;

    std::vector<int> tmp_seq;
    std::vector<int> output_seq;

    Common<int> com_obj;

    while ((start + stride) <= (int) line.length())
    {
        std::string sub_str = line_slice(line, start, stride);
        std::cout << "исходная подстрока: \n" << sub_str << "\n" << std::endl;
       
        tmp_seq = pakf(sub_str);
        com_obj.output_vector(tmp_seq);
        
        output_seq = com_obj.concat_vector(output_seq, tmp_seq);

        start += stride;

        std::cout << std::endl;
    }

    com_obj.output_vector(output_seq);

    /*
    std::string last_line = line_slice(line, start, (line.length() - start));
    last_line = add_zeroes(last_line, stride);
    std::cout << last_line << std::endl;    
    */
}        

template <typename Cor> std::vector<int> Correlation <Cor>::pakf(std::string l)
{
    std::vector<int> pakf_seq;
    unsigned long long int xor_int;

    std::bitset<64> xor_l = std::bitset<64>(l) ^ std::bitset<64>(l);      
    xor_int =  xor_l.to_ullong(); 
    int h_dist = hamming_dist(xor_int);

    pakf_seq.push_back(64 - h_dist);
    

    for (int i = l.length() - 1; i > 0; i--)
    {
        std::string new_l = add_string_part(l, i);
        //std::cout << new_l << std::endl;
        std::bitset<64> xor_l = std::bitset<64>(l) ^ std::bitset<64>(new_l);      
        xor_int =  xor_l.to_ullong(); 
        int h_dist = hamming_dist(xor_int);

        pakf_seq.push_back(h_dist);
        /*        
        std::cout <<  xor_l << std::endl;
        std::cout << xor_int << std::endl;
        std::cout << h_dist << std::endl;
        std::cout << "\n------------------" << std::endl;
        */

        

    }
    
    return pakf_seq;
}

template <typename Cor> int Correlation <Cor>::hamming_dist(unsigned long long int number)
{
    //return __buildin_popcount(number);
    return _mm_popcnt_u64(number);
}
            
     

template <typename Cor> std::string Correlation <Cor>::generate_key ()
{
    std::string l = "";
    
    for (int i = 0; i < 1024; i++) { l = l + std::to_string(rand() % 2); }

    return l;
}

template <typename Cor> std::string Correlation <Cor>::line_slice (std::string l, int start, int stride)
{
    std::string slice = l.substr(start, stride);
    //std::bitset<64> b_slice(slice);

    //std::cout << b_slice << std::endl;
    return slice;
}

template <typename Cor> std::string Correlation <Cor>::add_string_part(std::string l, int chkpoint)
{
    std::string part_1 = l.substr(chkpoint, (l.length() - chkpoint));
    std::string part_2 = l.substr(0, chkpoint);
    
    return part_1 + part_2;
}

template <typename Cor> std::string Correlation <Cor>::add_zeroes(std::string l, int stride)
{
    if (l.length() < stride)
    {
        return std::string(stride - l.length(), '0') + l;
    }            

    else { return l; }
}

