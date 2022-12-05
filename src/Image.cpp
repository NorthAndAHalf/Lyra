#include "Image.h"
#include <iostream>

Image::Image(unsigned int width, unsigned int height) 
	: m_Width(width), m_Height(height), m_Pixels(std::vector<glm::vec3>()) 
{
}

void Image::add_pixel(unsigned int width, unsigned int height, glm::vec3 p)
{
	m_Pixels.insert(m_Pixels.begin() + (width + m_Width * height), p);
}

glm::vec3& Image::get_pixel(unsigned int width, unsigned int height)
{
	return m_Pixels.at(width + m_Width * height);
}

