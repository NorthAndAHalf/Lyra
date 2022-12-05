#pragma once
#include "glm/vec3.hpp";
#include "Intersection.h"

glm::vec3 phong_reflect(Intersection* intersection, glm::vec3 light, glm::vec3 lightCol, float ai, float specStrength, float smoothness);
