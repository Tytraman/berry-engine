#include <berry-engine/vertex.h>

berry::Vertex::Vertex(Vec3 _position, Vec2 _texCoords, Vec3 _normal, RGBColor _color) :
    position(_position), texCoords(_texCoords), normal(_normal), color(_color)
{}

