#include "Ray.h"

Ray::Ray(glm::vec3 orig, glm::vec3 dir)
	: m_Orig(orig), m_Dir(dir)
{
}

glm::vec3 Ray::at(float t)
{
	return m_Orig + t * m_Dir;
}