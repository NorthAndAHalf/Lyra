#include "Image.h"

Image::Image(unsigned int width, unsigned int height) 
	: m_Width(width), m_Height(height), m_Pixels((glm::vec3*)malloc(sizeof(glm::vec3) * width * height)) 
{
}

Image::~Image()
{
	delete m_Pixels;
}

void Image::add_pixel(unsigned int width, unsigned int height, glm::vec3 p)
{
	m_Pixels[width + m_Height * height] = p;
}

glm::vec3& Image::get_pixel(unsigned int width, unsigned int height)
{
	return m_Pixels[width + m_Height * height];
}

