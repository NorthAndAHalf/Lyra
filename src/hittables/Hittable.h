#pragma once

#include "Intersection.h"
#include "Ray.h"

class Hittable
{
public:
	virtual Intersection intersect(Ray* r) = 0;
};