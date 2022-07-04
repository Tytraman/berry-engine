#ifndef __BERRY_VERTEX_H__
#define __BERRY_VERTEX_H__

#include <libcake/def.h>
#include <berry-engine/vectors.h>
#include <berry-engine/color.h>

namespace berry {

    struct Vertex {
        Vec3 position;
        Vec2 texCoords;
        Vec3 normal;
        RGBColor color;

        Vertex(Vec3 position, Vec2 texCoords, Vec3 normal, RGBColor color);
    };

}

#endif