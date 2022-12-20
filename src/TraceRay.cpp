#include "TraceRay.h"
#include "hittables/Hittable.h"

Intersection TraceRay(Scene* scene, Ray* ray)
{
	std::vector<Intersection> hits;
	for (Hittable* h : *scene->get_hittables())
	{
		hits.push_back(h->intersect(ray));
	}

	Intersection closest = hits.front();
	for (const Intersection& i : hits)
	{
		if (i.distance < closest.distance)
		{
			closest = i;
		}
	}

	return closest;
}