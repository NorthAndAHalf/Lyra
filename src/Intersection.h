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
	Intersection(IntersectionType _type, double _distance, glm::vec3 _intersectionPoint, glm::vec3 _rayDir, glm::vec3 _normal, glm::vec3 _colour)
		: type(_type), distance(_distance), intersectionPoint(_intersectionPoint), rayDir(_rayDir), normal(_normal), colour(_colour) {}

	IntersectionType type;
	double distance;
	glm::vec3 intersectionPoint;
	glm::vec3 rayDir;
	glm::vec3 normal;
	glm::vec3 colour;
	// Possibly add material later
};
