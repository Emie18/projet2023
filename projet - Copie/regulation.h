#ifndef REGULATION_H
#define REGULATION_H

#include <stdio.h>
#include <stdlib.h>
#include "define.h" 

float regulationTest(int regul,float consigne,float* tabT, int nT);
float regulation(float consigne,temp_t temp, int regul,	float* temperature);
#endif