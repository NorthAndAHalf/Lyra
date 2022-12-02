#pragma once

#include "Hittable.h"

class Sphere : public Hittable
{
public:
	Sphere(glm::vec3 centre, float radius, glm::vec3 colour);

	virtual Intersection intersect(Ray* r) override;

private:
	glm::vec3 m_Centre;
	float m_Radius;
	glm::vec3 m_Colour;
};