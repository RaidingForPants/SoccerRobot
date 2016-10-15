/*
 * Vector.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#include “Vector.h”
#include <math.h>

Vector::Vector(): x(0), y(0){}

Vector::Vector(float x, float y): x(x), y(y){}

float Vector::getMagnitude(){
	return sqrt(pow(x, 2)+pow(y, 2));
}
