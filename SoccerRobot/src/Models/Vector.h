/*
 * Vector.h
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#ifndef VECTOR_H
#define VECTOR_H

struct Vector{
	float x;
	float y;

	Vector();
	Vector(float x, float y);

	float getMagnitude();
};

#endif
