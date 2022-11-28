#pragma once

#include "Intersection.h"
#include "Ray.h"

class Hittable
{
	virtual Intersection intersect(Ray* r) = 0;
};