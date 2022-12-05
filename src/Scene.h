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

	void add_hittable(Hittable* h) { m_Hittables.push_back(h); }

private:
	std::vector<Hittable*> m_Hittables;
	Camera* m_Camera;
};