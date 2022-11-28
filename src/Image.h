#pragma once

#include <vector>
#include <stdint.h>
#include <memory>
#include "glm/vec3.hpp"

class Image
{
public:
	Image(unsigned int width, unsigned int height);
	~Image();

	// These are 0 based
	void add_pixel(unsigned int width, unsigned int height, glm::vec3 p);
	glm::vec3& get_pixel(unsigned int width, unsigned int height);

	unsigned int get_width() { return m_Width; }
	unsigned int get_height() { return m_Height; }

private:
	unsigned int m_Width;
	unsigned int m_Height;
	
	glm::vec3* m_Pixels;
};