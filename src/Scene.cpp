#include "Scene.h"
#include <iostream>
#include "lighting/Shading.h"
#include "lighting/Light.h"
#include "TraceRay.h"

Scene::Scene(Camera* camera)
	: m_Camera(camera)
{

}

Image Scene::Render(unsigned int width, unsigned int height)
{
	Image image = Image(width, height);
	
	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			glm::vec3 pixel = glm::vec3((2 * ((double)x / (double)width)) - 1, (2 * ((double)y / (double)height)) - 1, 0.0);
			Ray ray = Ray(m_Camera->get_pos() + pixel, m_Camera->get_direction());
			std::list<Intersection> hits = std::list<Intersection>();

			Intersection closest = TraceRay(this, &ray);
			image.add_pixel(x, y, phong_reflect(&closest, &m_Lights, 0.2f, 15.0f));
		}
	}
	return image;
}
