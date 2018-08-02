#pragma once
#include <iostream>
#include "String2.h"
unsigned int FindClosestPowerOf2toNumber(unsigned int); //returns the closest bigger power of 2 to the param number 
unsigned int ownStrlen(const char*);
int compare(const char*, const char*);

//substring for char*, dangerous returns dynamicly allocated memory, needs to be handled, seems exception safe otherwise
char*subcharPtr(const char*,unsigned int, unsigned int);
void ownStrcpy(char*, const char*);
