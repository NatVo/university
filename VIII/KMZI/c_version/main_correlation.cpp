//#include "common.h"
//#include "common.cpp"

#include "correlation.h"
#include "correlation.cpp"

#include <iostream>

//g++ -Wall -m64 -msse4.2 -o correlation main_correlation.cpp correlation.cpp

int main()
{
  setlocale(LC_ALL, "Russian");
  
  Correlation<std::string> line("1010101111001010101111000111001100110101011111010101110111111000110111");
  line.pakf(64);
  std::cout <<"==========================================================================" << std::endl;
  line.aakf(64);

  return 0;
}

