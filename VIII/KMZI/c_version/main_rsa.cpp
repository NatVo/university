
#include "rsa.h"
#include "rsa.cpp"

#include <iostream>

//g++ -o rsa 

int main()
{
    setlocale(LC_ALL, "Russian");
  
    RSA<std::string> rsa(48353, 49333);
    bool check_inp = rsa.check_input();
 
    if ( check_inp )
    {    
        rsa.set_parameters();
    }
    else { std::cout << "некорректный ввод!" << std:: endl; }


   

  return 0;
}

