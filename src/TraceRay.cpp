#include "TraceRay.h"
#include "hittables/Hittable.h"
#include "lighting/Shading.h"
#include "glm/geometric.hpp"

// TODO: Reorganise these into namespaces for each type of ray tracing
// i.e whitted and distributed
// Maybe leave functions outside of namespaces like TraceWhitted() and TraceDistributed() or something
// then put the recursive functions in their respective namespaces

Intersection TraceRayRec(Scene* scene, Ray* ray, int bounceLimit)
{
	std::vector<Intersection> hits;
	for (Hittable* h : *scene->get_hittables())
	{
		hits.push_back(h->intersect(ray));
	}

	Intersection rayHit = hits.front();
	for (const Intersection& i : hits)
	{
		if (i.distance < rayHit.distance)
		{
			rayHit = i;
		}
	}

	if (bounceLimit <= 0) return rayHit;

	Ray bounceRay = Ray(rayHit.intersectionPoint, glm::reflect(rayHit.rayDir, rayHit.normal));
	Intersection bounce = TraceRayRec(scene, &bounceRay, bounceLimit - 1);

	if (bounce.type == IntersectionType::PRIMITIVE)
	{
		rayHit.colour = (flat_colour(rayHit) + flat_colour(bounce)) / 2.0f;
	}

	return rayHit;
}

glm::vec3 TraceRay(Scene* scene, Ray* ray, int bounceLimit)
{
	return flat_colour(TraceRayRec(scene, ray, bounceLimit));
}