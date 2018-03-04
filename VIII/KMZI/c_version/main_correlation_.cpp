#include "correlation.h"

#include <iostream>

int main()
{
  setlocale(LC_ALL, "Russian");
  std::cout << "test" << std::endl;
  
  Correlation<int> line(5);

  return 0;
}
