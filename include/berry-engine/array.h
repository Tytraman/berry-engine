#ifndef __BERRY_ARRAY_H__
#define __BERRY_ARRAY_H__

#include <libcake/def.h>
#include <berry-engine/vertex.h>

namespace berry {

    class FloatArray {
        public:
            float *array;
            ulonglong length;

            FloatArray();
            ~FloatArray();

            float operator[](ulonglong index) const;

            cake_bool add(float value);
    };

    class UIntArray {
        public:
            uint *array;
            ulonglong length;

            UIntArray();
            ~UIntArray();

            uint operator[](ulonglong index) const;

            cake_bool add(uint value);
    };

    class VertexArray {
        public:
            Vertex *array;
            ulonglong length;

            VertexArray();
            ~VertexArray();

            Vertex operator[](ulonglong index) const;

            cake_bool add(Vertex value);
    };

    class Vec2Array {
        public:
            Vec2 *array;
            ulonglong length;

            Vec2Array();
            ~Vec2Array();

            Vec2 operator[](ulonglong index) const;

            cake_bool add(Vec2 value);
    };

    class Vec3Array {
        public:
            Vec3 *array;
            ulonglong length;

            Vec3Array();
            ~Vec3Array();

            Vec3 operator[](ulonglong index) const;

            cake_bool add(Vec3 value);
    };

}

#endif