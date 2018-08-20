#pragma once
#include <iostream>

//returns the closest >= power of 2 to the param number (5->8, 14->16, 4->4, 65->128, etc.)
unsigned int FindClosestPowerOf2toNumber(unsigned int);
unsigned int ownStrlen(const char*);

//acts like !=, but instead returns an int(positive or 0 if the are the same, or negative if they are different, this is how the std::string compare works
int compare(const char*, const char*);

//substring for char*, dangerous returns dynamicly allocated memory, needs to be handled, seems exception safe otherwise
char*subcharPtr(const char*,unsigned int, unsigned int);

void ownStrcpy(char*, const char*);
