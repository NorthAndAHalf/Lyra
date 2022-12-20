#pragma once

#include <list>
#include "hittables/Hittable.h"
#include "Camera.h"
#include "Image.h"
#include "lighting/Light.h"

class Scene
{
public:
	Scene(Camera* camera);

	Image Render(unsigned int width, unsigned int height);

	void add_hittable(Hittable* h) { m_Hittables.push_back(h); }
	void add_light(Light* l) { m_Lights.push_back(l); }

	const std::vector<Hittable*>* get_hittables() { return &m_Hittables; }

private:
	std::vector<Hittable*> m_Hittables;
	std::vector<Light*> m_Lights;
	Camera* m_Camera;
};