#ifndef __BERRY_SIMPLE_PLAYER_H__
#define __BERRY_SIMPLE_PLAYER_H__

#include <libcake/def.h>

#include <berry-engine/camera.h>

namespace berry {

    class SimplePlayer {
        public:
            Camera camera;
            float speed;

            SimplePlayer(
                float speed = 1.0f,
                float x = 0.0f, float y = 0.0f, float z = 0.0f
            );

            void moveForward(float value);
            void moveRight(float value);
            void moveBackward(float value);
            void moveLeft(float value);
    };

}

#endif