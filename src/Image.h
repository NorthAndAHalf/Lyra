#pragma once

#include <vector>
#include <stdint.h>
#include <memory>
#include "glm/vec3.hpp"

class Image
{
public:
	Image(unsigned int width, unsigned int height) : m_Width(width), m_Height(height), m_Pixels((glm::vec3*) malloc(sizeof(glm::vec3)*width*height)) {}
	~Image() { delete m_Pixels; }

	void add_pixel(unsigned int width, unsigned int height, glm::vec3 p) { m_Pixels[width*height-1] = p; }
	glm::vec3& get_pixel(unsigned int width, unsigned int height) { return m_Pixels[width*height-1]; }

private:
	unsigned int m_Width;
	unsigned int m_Height;
	
	glm::vec3* m_Pixels;
};