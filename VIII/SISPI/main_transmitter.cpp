
#include "transmitter.h"
#include "transmitter.cpp"

#include <iostream>

//g++ -o transmitter main_transmitter.cpp transmitter.cpp 

int main()
{
    setlocale(LC_ALL, "Russian");
  
    Transmit<float> t("1010011", "100110101", 257, 2, 1040, 6);
    t.code();
  
  return 0;
}

