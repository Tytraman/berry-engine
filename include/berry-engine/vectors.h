#ifndef __BERRY_VECTORS_H__
#define __BERRY_VECTORS_H__

#include <libcake/def.h>

namespace berry {

    class Vec2 {
        public:
            float x, y;

            Vec2(float x, float y);

            Vec2 operator+(float value);
            Vec2 operator-(float value);
            Vec2 operator*(float value);
            Vec2 operator/(float value);

            Vec2 operator-();

            Vec2 operator+(const Vec2 &vec);
            Vec2 operator-(const Vec2 &vec);

            void operator+=(float value);
            void operator-=(float value);
            void operator*=(float value);
            void operator/=(float value);

            void negate();

            float length() const;
            float dot(const Vec2 &vec) const;
    };

    class Vec3 {
        public:
            float x, y, z;

            Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

            Vec3 operator+(float value) const;
            Vec3 operator-(float value) const;
            Vec3 operator*(float value) const;
            Vec3 operator/(float value) const;

            Vec3 operator-();

            Vec3 operator+(const Vec3 &vec) const;
            Vec3 operator-(const Vec3 &vec) const;

            void operator+=(float value);
            void operator-=(float value);
            void operator*=(float value);
            void operator/=(float value);

            void operator+=(const Vec3 &vec);
            void operator-=(const Vec3 &vec);

            void negate();

            float length() const;
            float dot(const Vec3 &vec) const;

            static Vec3 normalize(const Vec3 &vec);
            static Vec3 cross(const Vec3 &a, const Vec3 &b);
    };

    class Vec4 {
        public:
            float x, y, z, w;

            Vec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

            float length() const;
            float dot(const Vec4 &vec) const;
    };

}

#endif