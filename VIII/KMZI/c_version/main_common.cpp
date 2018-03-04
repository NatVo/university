#include "common.h"
#include "common.cpp"

#include <iostream>
#include <vector>

//g++ -o common main_common.cpp common.cpp

int main()
{
  setlocale(LC_ALL, "Russian");
  
  Common<int> obj;
  
  std::vector<int> test;
  test.push_back(333);

  obj.output_vector(test);
  return 0;
}

