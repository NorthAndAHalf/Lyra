#pragma once

#include "glm/vec3.hpp"
#include <stdint.h>

class Camera
{
public:
	Camera(uint32_t focalLength, glm::vec3 pos, glm::vec3 dir) : m_FocalLength(focalLength), m_Pos(pos), m_Dir(dir) {}

	uint32_t get_focal_length() { return m_FocalLength; }
	void set_pos(uint32_t focalLength) { m_FocalLength = focalLength; }

	glm::vec3 get_pos() { return m_Pos; }
	void set_pos(glm::vec3 pos) { m_Pos = pos; }

	glm::vec3 get_direction() { return m_Dir; }
	void set_direction(glm::vec3 dir) { m_Dir = dir; }

private:
	uint32_t m_FocalLength;
	glm::vec3 m_Pos;
	glm::vec3 m_Dir;
};