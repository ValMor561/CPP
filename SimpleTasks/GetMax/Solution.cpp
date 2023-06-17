#include <iostream>
int GetMax(int FirstNum , int SecondNum)
{
 	int MaxNumber;
    if ( FirstNum > SecondNum)
        MaxNumber = FirstNum;
   	else 
     	MaxNumber = SecondNum;
    return MaxNumber;
}    