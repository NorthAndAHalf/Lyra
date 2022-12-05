#include "Shading.h"

#include <glm/geometric.hpp>
#include <algorithm>

glm::vec3 phong_reflect(Intersection* i, glm::vec3 light, glm::vec3 lightCol, float ai, float specStrength, float smoothness)
{
    glm::vec3 lightDir = glm::normalize(i->intersectionPoint - light);

    glm::vec3 ambient = ai * lightCol;
    glm::vec3 diffuse = lightCol * std::max(glm::dot(lightDir, i->normal), 0.0f);

    //Specular
    glm::vec3 viewDir = i->rayDir * -1.0f;
    glm::vec3 reflectDir = lightDir - 2 * glm::dot(lightDir, i->normal) * i->normal;
    glm::vec3 specular = specStrength * lightCol * std::pow(std::max(glm::dot(viewDir, reflectDir), 0.0f), smoothness);

    return i->colour * (ambient + diffuse) + specular;
}