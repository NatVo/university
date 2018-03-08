//#include "common.h"
//#include "common.cpp"

#include "correlation.h"
#include "correlation.cpp"

#include <iostream>

//g++ -Wall -m64 -msse4.2 -o correlation main_correlation.cpp correlation.cpp

int main()
{
  setlocale(LC_ALL, "Russian");
  std::cout << "test" << std::endl;
  
  Correlation<std::string> line;
  line.iter_seq(64, 0);

  return 0;
}

