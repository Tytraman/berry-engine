#include <berry-engine/mesh.h>

#include <glad/glad.h>

berry::Mesh::Mesh() :
    m_Valid(cake_false)
{}

berry::Mesh::Mesh(
    ArrayList<Vec3> &vertexPositions,
    ArrayList<Vec2> &texCoords,
    ArrayList<Vec3> &normalPositions,
    ArrayList<uint> &vertexIndices,
    ArrayList<uint> &texCoordsIndices,
    ArrayList<uint> &normalIndices
) :
    m_Valid(cake_true)
{
    ulonglong i;
    for(i = 0; i < vertexIndices.getLength(); ++i) {
        Vertex vertex(
            vertexPositions[vertexIndices[i]],
            texCoords[texCoordsIndices[i]],
            normalPositions[normalIndices[i]],
            RGBColor(1.0f, 1.0f, 1.0f)
        );
        m_Vertices.push(vertex);
    }

    // VBO
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_Vertices.getLength() * sizeof(Vertex), m_Vertices.getRawData(), GL_STATIC_DRAW);

    // EBO
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.getLength() * sizeof(uint), m_Indices.getRawData(), GL_STATIC_DRAW);

    // VAO
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);
    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (const void *) 0);
    // Texture positions
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (const void *) (3 * sizeof(float)));
    // Normal positions
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (const void *) (5 * sizeof(float)));
    // Color
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (const void *) (8 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
}

/* Getters */

cake_bool berry::Mesh::isValid() const {
    return m_Valid;
}

berry::ArrayList<berry::Vertex> berry::Mesh::getVertices() const {
    return m_Vertices;
}

ulonglong berry::Mesh::getVerticesNumber() const {
    return m_Vertices.getLength();
}

berry::ArrayList<uint> berry::Mesh::getIndices() const {
    return m_Indices;
}

ulonglong berry::Mesh::getIndicesNumber() const {
    return m_Indices.getLength();
}

uint *berry::Mesh::getIndicesPtr() {
    return m_Indices.getRawData();
}

uint berry::Mesh::getVBO() const {
    return m_VBO;
}

uint berry::Mesh::getEBO() const {
    return m_EBO;
}

uint berry::Mesh::getVAO() const {
    return m_VAO;
}

/* Setters */

void berry::Mesh::setValid(cake_bool value) {
    this->m_Valid = value;
}
