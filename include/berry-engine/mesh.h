#ifndef __BERRY_MESH_H__
#define __BERRY_MESH_H__

#include <libcake/def.h>
#include <berry-engine/array.h>
#include <berry-engine/shaders.h>

namespace berry {

    class Mesh {
        public:
            Mesh();
            Mesh(
                Vec3Array &vertexPositions,
                Vec2Array &texCoords,
                Vec3Array &normalPositions,
                UIntArray &vertexIndices,
                UIntArray &texCoordsIndices,
                UIntArray &normalIndices
            );

            /* Getters */
            cake_bool isValid() const;
            VertexArray getVertices() const;
            ulonglong getVerticesNumber() const;
            UIntArray getIndices() const;
            ulonglong getIndicesNumber() const;
            uint *getIndicesPtr();

            uint getVBO() const;
            uint getEBO() const;
            uint getVAO() const;

            /* Setters */
            void setValid(cake_bool value);

        private:
            VertexArray m_Vertices;
            UIntArray m_Indices;

            uint m_VBO;
            uint m_EBO;
            uint m_VAO;

            cake_bool m_Valid;
    };

}

#endif