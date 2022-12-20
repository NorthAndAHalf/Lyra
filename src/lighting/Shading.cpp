#include "Shading.h"

#include <glm/geometric.hpp>
#include <algorithm>

// In the future, adapt this function to be able to work with emmisive objects as well as light objects, idk how emissive objects will work yet
// Future me problem :skull:

glm::vec3 phong_reflect(Intersection* i, std::vector<Light*>* lights, float ai, float smoothness)
{
    glm::vec3 finalCol = glm::vec3(0.0);

    for (const Light* l : *lights)
    {
        glm::vec3 lightDir = glm::normalize(i->intersectionPoint - l->colour);

        glm::vec3 ambient = ai * l->colour;
        glm::vec3 diffuse = l->intensity * l->colour * std::max(glm::dot(lightDir, i->normal), 0.0f);

        //Specular
        glm::vec3 viewDir = i->rayDir * -1.0f;
        glm::vec3 reflectDir = lightDir - 2 * glm::dot(lightDir, i->normal) * i->normal;
        glm::vec3 specular = l->intensity * l->colour * std::pow(std::max(glm::dot(viewDir, reflectDir), 0.0f), smoothness) * 5.0f;

        finalCol += (ambient + diffuse) + specular;
    }

    return i->colour * finalCol;
}