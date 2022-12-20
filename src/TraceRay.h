#pragma once

#include "Intersection.h"
#include "Scene.h"
#include "Ray.h"

Intersection TraceRay(Scene* scene, Ray* ray);