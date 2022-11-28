#include "Scene.h"

Scene::Scene(Camera* camera)
	: m_Camera(camera)
{

}

Image Scene::Render(unsigned int width, unsigned int height)
{
	return Image(width, height);

}