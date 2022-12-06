#pragma once

#include "glm/vec3.hpp"

struct Light
{
	Light(glm::vec3 _pos, glm::vec3 _colour, float _intensity)
		: pos(_pos), colour(_colour), intensity(_intensity) {}

	glm::vec3 pos;
	glm::vec3 colour;
	float intensity;
};