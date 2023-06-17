#include "cstdlib"
#include "cmath"
 bool IsSimple(unsigned int a)
 {
     int count = 0;
     for (int i = 2;i < a;++i)
         if (a%i == 0) 
             count += 1;
     if (count == 0)
         return true;
     if (count != 0)
         return false;
 }    