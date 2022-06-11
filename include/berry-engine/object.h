#ifndef __BERRY_OBJECT_H__
#define __BERRY_OBJECT_H__

#include <libcake/def.h>

#include <berry-engine/vao.h>
#include <berry-engine/vectors.h>
#include <berry-engine/matrices.h>
#include <berry-engine/shaders.h>

namespace berry {

    class Object {

        public:
            Vec3 pos;
            Vec3 rotate;
            Vec3 scale;

            Object(Object &) = delete;
            Object(Object &&) = delete;
            Object(VAO &vao, ShaderProgram &shader,
                    float x = 0.0f, float y = 0.0f, float z = 0.0f,
                    float degreesX = 0.0f, float degreesY = 0.0f, float degreesZ = 0.0f,
                    float scaleX = 1.0f, float scaleY = 1.0f, float scaleZ = 1.0f);

            void render() const;
        private:
            VAO &vao;
            ShaderProgram &shader;
    };

}

#endif