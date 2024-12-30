#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <string>
#include <vector>

#include "shader.h"

#define MAX_BONES 4 

struct Vertex{
    /* Position */
    glm::vec3 Position;
    /* Normal */
    glm::vec3 Normal;
    /* TexCoords */
    glm::vec2 TexCoords;
    /* Tangent */
    glm::vec3 Tangent;
    /* Bitangent */
    glm::vec3 Bitangent;
    /* Bone ids */
    int m_BoneIds[MAX_BONES];
    /* Weights */
    float m_Weights[MAX_BONES];

};

struct Texture{
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh{
    public:
        /* Mesh Data */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        unsigned int VAO;

        /* Functions */
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void Draw(Shader &shader);
    private:
        unsigned int VBO, EBO;
        void setupMesh();

};



#endif