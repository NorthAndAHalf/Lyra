#include "Scene.h"

Scene::Scene(Camera* camera)
	: m_Camera(camera)
{

}

Image Scene::Render(unsigned int width, unsigned int height)
{
	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			
		}
	}
	return Image(width, height);
}
