#pragma once

#include <list>
#include "hittables/Hittable.h"
#include "Camera.h"
#include "Image.h"

class Scene
{
public:
	Scene(Camera* camera);

	Image Render(unsigned int width, unsigned int height);

private:
	std::list<Hittable*> m_Hittables;
	Camera* m_Camera;
};