#pragma once

#include "Intersection.h"
#include "Scene.h"
#include "Ray.h"

glm::vec3 TraceRay(Scene* scene, Ray* ray, int bounceLimit);