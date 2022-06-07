#ifndef __BERRY_CAMERA_H__
#define __BERRY_CAMERA_H__

#include <libcake/def.h>

#include <berry-engine/vectors.h>
#include <berry-engine/matrices.h>

namespace berry {

    class Camera {
        public:
            Vec3 pos;
            Vec3 baseUp;
            Vec3 front, right, up;

            float yaw, pitch;

            Camera(const Vec3 &pos, const Vec3 &front, const Vec3 &baseUp = Vec3(0.0f, 1.0f, 0.0f));

            Mat4 lookAt() const;
            void update();

    };

}

#endif