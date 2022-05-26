#ifndef __BERRY_VECTORS_H__
#define __BERRY_VECTORS_H__

#include <libcake/def.h>

namespace berry {

    class Vec2 {
        public:
            longlong x, y;

            Vec2(longlong x, longlong y);

    };

    class Vec3 {
        public:
            longlong x, y, z;

            Vec3(longlong x, longlong y, longlong z);
    };

}

#endif