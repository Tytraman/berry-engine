#ifndef __BERRY_SIMPLE_PLAYER_H__
#define __BERRY_SIMPLE_PLAYER_H__

#include <libcake/def.h>

#include <berry-engine/object.h>
#include <berry-engine/camera.h>

namespace berry {

    class SimplePlayer : public Object {
        public:
            Camera camera;
            float speed;

            SimplePlayer(SimplePlayer &) = delete;
            SimplePlayer(SimplePlayer &&) = delete;

            SimplePlayer(VAO &vao, ShaderProgram &shader,
                            float speed = 1.0f,
                            float x = 0.0f, float y = 0.0f, float z = 0.0f,
                            float degreesX = 0.0f, float degreesY = 0.0f, float degreesZ = 0.0f,
                            float scaleX = 1.0f, float scaleY = 1.0f, float scaleZ = 1.0f);

            void moveForward(float value);
            void moveRight(float value);
            void moveBackward(float value);
            void moveLeft(float value);
    };

}

#endif