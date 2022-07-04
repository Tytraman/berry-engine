#ifndef __BERRY_OBJECT_H__
#define __BERRY_OBJECT_H__

#include <libcake/def.h>

#include <berry-engine/vao.h>
#include <berry-engine/vectors.h>
#include <berry-engine/matrices.h>
#include <berry-engine/shaders.h>
#include <berry-engine/mesh.h>

namespace berry {

    class Object {
        public:
            Object(
                Mesh &mesh,
                float x = 0.0f, float y = 0.0f, float z = 0.0f,
                float degreesX = 0.0f, float degreesY = 0.0f, float degreesZ = 0.0f,
                float scaleX = 1.0f, float scaleY = 1.0f, float scaleZ = 1.0f
            );

            void render(ShaderProgram &shader) const;
        private:
            Vec3 m_Pos;
            Vec3 m_Rotate;
            Vec3 m_Scale;

            Mesh &m_Mesh;
    };

}

#endif