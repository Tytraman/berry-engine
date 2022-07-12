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
                ArrayList<Vec3> &vertexPositions,
                ArrayList<Vec2> &texCoords,
                ArrayList<Vec3> &normalPositions,
                ArrayList<uint> &vertexIndices,
                ArrayList<uint> &texCoordsIndices,
                ArrayList<uint> &normalIndices
            );

            /* Getters */
            cake_bool isValid() const;
            ArrayList<Vertex> getVertices() const;
            ulonglong getVerticesNumber() const;
            ArrayList<uint> getIndices() const;
            ulonglong getIndicesNumber() const;
            uint *getIndicesPtr();

            uint getVBO() const;
            uint getEBO() const;
            uint getVAO() const;

            /* Setters */
            void setValid(cake_bool value);

        private:
            ArrayList<Vertex> m_Vertices;
            ArrayList<uint> m_Indices;

            uint m_VBO;
            uint m_EBO;
            uint m_VAO;

            cake_bool m_Valid;
    };

}

#endif