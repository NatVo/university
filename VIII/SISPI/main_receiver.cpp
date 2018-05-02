
#include "receiver.h"
#include "receiver.cpp"

#include <iostream>

//g++ -o receiver  main_receiver.cpp receiver.cpp 

int main()
{
    setlocale(LC_ALL, "Russian");
  
    Receive<float> r(257, 2, 1040, 6);
    r.decode();
  
  return 0;
}

