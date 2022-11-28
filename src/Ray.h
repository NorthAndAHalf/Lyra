#pragma once

#include "glm/vec3.hpp"

class Ray
{
public:
	Ray(glm::vec3 orig, glm::vec3 dir);

	glm::vec3 at(float t);

	void set_origin(glm::vec3 orig) { m_Orig = orig; }
	glm::vec3 get_origin() { return m_Orig; }

	void set_direction(glm::vec3 dir) { m_Dir = dir; }
	glm::vec3 get_direction() { return m_Dir; }

private:
	glm::vec3 m_Orig;
	glm::vec3 m_Dir;
};