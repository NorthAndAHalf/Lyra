#pragma once
#include "glm/vec3.hpp";
#include "Intersection.h"
#include "Light.h"
#include <vector>

glm::vec3 phong_reflect(Intersection* intersection, std::vector<Light*>* lights, float ai, float smoothness);
