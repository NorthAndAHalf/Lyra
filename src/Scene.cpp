#include "Scene.h"
#include <iostream>

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

			for (Hittable* h : m_Hittables) 
			{
				hits.push_back(h->intersect(&ray));
			}

			Intersection closest = hits.front();
			for (const Intersection& i : hits)
			{
				if (i.distance < closest.distance)
				{
					closest = i;
				}
			}
			image.add_pixel(x, y, closest.colour);
		}
	}
	return image;
}
