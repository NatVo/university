
#include "common.h"
#include "common.cpp"
#include "correlation.h"

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <smmintrin.h>

template <typename Cor> Correlation <Cor>::Correlation(int max_length)
{
    std::cout << "\nСГЕНЕРИРОВАННЫЙ КЛЮЧ: \n" << std::endl;
    line = generate_key(max_length);

    int full_length = ceil_length(line, 64);
    line_full = add_zeroes(line, full_length, 0);

    std::cout << "исходная строка:" << line << std::endl;
    //std::cout << "полная исходная строка:" << line_full << std::endl;

    //std::bitset<64> sub_str = line_slice(line, 0, 64);
    //std::cout << "\n" << sub_str << std::endl;

}

template <typename Cor> Correlation <Cor>::Correlation(std::string input)
{

    line = input;
    //if (line.length() < 1024) { line = add_zeroes(line, 1024); }    

    int full_length = ceil_length(line, 64);
    line_full = add_zeroes(line, full_length, 0);

    std::cout << "исходная строка:" << line << std::endl;
    //std::cout << "полная исходная строка:" << line_full << std::endl;
 
}

template <typename Cor> std::string Correlation <Cor>::generate_key (int max_length)
{
    std::string l = "";
    
    for (int i = 0; i < max_length; i++) { l = l + std::to_string(rand() % 2); }

    return l;
}



template <typename Cor> std::vector<int> Correlation <Cor>::pakf(int stride)
{
    std::vector<int> output_seq;

    Common<int> com_obj;

    std::cout << "ПАКФ" << std::endl; 

    for (int i = line.length(); i > 0; i--)
    {

        std::string new_line = add_string_part(line, i);
        //std::cout << new_line << std::endl;
        long int element = correlation_element(new_line, 64, 0);
        output_seq.push_back(element);
       
    }
    //com_obj.output_vector(output_seq);
    std::string result = com_obj.vector_to_str(output_seq);
    std::cout << result << std::endl;

    std::string file_path = "pakf.txt";
    com_obj.write_file(result, file_path);

    std::cout << "длина последовательности ПАКФ: " << output_seq.size() << std::endl;

    return output_seq;
   
}      

template <typename Cor> std::vector<int> Correlation <Cor>::aakf(int stride)
{
    std::vector<int> output_seq;

    Common<int> com_obj;

    std::cout << "ААКФ" << std::endl; 

    for (int i = 0; i < (int) line.length(); i++)
    {
        std::string new_line = line.substr(0, (line.length() - i));
        new_line = add_zeroes(new_line, line.length(), 1);

        //std::cout << new_line << std::endl;
        
        long int element = correlation_element(new_line, 64, 0);
        output_seq.push_back(element);
       
    }
    //com_obj.output_vector(output_seq);
    std::string result = com_obj.vector_to_str(output_seq);
    std::cout << result << std::endl;

    std::string file_path = "aakf.txt";
    com_obj.write_file(result, file_path);
 
    std::cout << "длина последовательности ААКФ: " << output_seq.size() << std::endl;

    return output_seq;
   
}      


template <typename Cor> long int Correlation <Cor>::correlation_element(std::string l, int stride, bool front)
{
    int start = 0;
    int sum = 0;
    unsigned long long int xor_int;
    int full_length = ceil_length(l, stride);
    
    l = add_zeroes(l, full_length, front);

    //std::cout << "str with 0: \n" << l << "\n" << std::endl;
    //std::cout << l.length() << std::endl;
   
    while ((start + stride) <= (int) l.length())
    {
        std::string sub_str = line_slice(l, start, stride);
        std::string sub_str_main = line_slice(line_full, start, stride);

        //std::cout << "исходная подстрока: \n" << sub_str << "\n" << std::endl;
        //std::cout << "исходная подстрока_: \n" << sub_str_main << "\n" << std::endl;

        std::bitset<64> xor_lines = std::bitset<64>(sub_str) ^ std::bitset<64>(sub_str_main);      

        xor_int =  xor_lines.to_ullong(); 
        int h_dist = hamming_dist(xor_int);

        //std::cout << h_dist << std::endl;

        sum += h_dist;

        start += stride;
    }

    //std::cout << "sum = " << line.length() - sum << std::endl;

    return line.length() - sum;
   
}

template <typename Cor> int Correlation <Cor>::hamming_dist(unsigned long long int number)
{
    //return __buildin_popcount(number);
    return _mm_popcnt_u64(number);
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

template <typename Cor> std::string Correlation <Cor>::add_zeroes(std::string l, int full_length, bool begin)
{
    if ( (int) l.length() < full_length)
    {
        if (begin) { return std::string(full_length - l.length(), '0') + l; }
        else { return l + std::string(full_length - l.length(), '0'); }
    }            

    else { return l; }
}


template <typename Cor> int Correlation <Cor>::ceil_length(std::string l, int stride)
{
    float dev = (float) l.length() / (float) stride;
    return stride * ceil(dev);
   
}

