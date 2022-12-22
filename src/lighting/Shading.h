#pragma once
#include "glm/vec3.hpp";
#include "Intersection.h"
#include "Light.h"
#include <vector>

glm::vec3 phong_reflect(const Intersection* intersection, const std::vector<Light*>* lights, float ai, float smoothness);

glm::vec3 flat_colour(const Intersection& intersection);