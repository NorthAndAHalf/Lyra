#pragma once

#include "glm/vec3.hpp"

enum class IntersectionType
{
	NONE = 0,
	VOLUME = 1,
	PRIMITIVE = 2
};

struct Intersection
{
	Intersection(IntersectionType _type, glm::vec3 _intersectionPoint, glm::vec3 _rayDir, glm::vec3 _normal) 
		: type(_type), intersectionPoint(_intersectionPoint), rayDir(_rayDir), normal(_normal) {}

	IntersectionType type;
	glm::vec3 intersectionPoint;
	glm::vec3 rayDir;
	glm::vec3 normal;
	// Possibly add material later
};
