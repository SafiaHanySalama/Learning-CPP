/**
 * 
 * 
*/
#include "Lab1to5.hpp"
int main()
{
    Dog spot; //Default Constructor ->Lab2
    Dog twin {spot}; // Copy constructor, twin will be a copy of spot -> Lab4
    Dog ﬁdo {"Fido", 4}; //Overloaded Constructor -> Lab3
    return 0;
}