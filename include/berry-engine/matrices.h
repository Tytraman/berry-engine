#ifndef __BERRY_MATRICES_H__
#define __BERRY_MATRICES_H__

#include <libcake/def.h>

#include <berry-engine/vectors.h>

namespace berry {

    class Mat4 {
        public:
            Mat4(float diagonalValue);
            Mat4(float values[16]);

            float operator()(int i, int j) const;

            Mat4 operator+(const Mat4 &mat) const;
            Mat4 operator-(const Mat4 &mat) const;

            Mat4 operator*(float value) const;

            Mat4 operator*(const Mat4 &mat) const;

            Vec4 operator*(const Vec4 &vec) const;

            static Mat4 scale(const Mat4 &mat, float x, float y, float z);
            static Mat4 translate(const Mat4 &mat, float x, float y, float z);
            static Mat4 rotateX(const Mat4 &mat, float radians);
            static Mat4 rotateY(const Mat4 &mat, float radians);
            static Mat4 rotateZ(const Mat4 &mat, float radians);

            static Mat4 perspective(float fovy, float aspectRatio, float znear, float zfar);

            void print() const;

            float data[16];
    };

}

#endif