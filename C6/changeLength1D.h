// change the length of an array

#ifndef changeLength1D_
#define changeLength1D_

#include "myExceptions.h"
#include <algorithm>//std::min, std::copy
#include <iostream>
using namespace std;

template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
   //if (newLength < 0)
   //   throw illegalParameterValue("new length must be >= 0");
   T* temp = new T[newLength];              // new array
   int number = std::min(oldLength, newLength);  // number to copy
   copy(a, a + number, temp);
   delete [] a;                             // deallocate old memory
   a = temp;
}
#endif
