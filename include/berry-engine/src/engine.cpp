#include <berry-engine/engine.h>

#include <stdlib.h>

#include <glad/glad.h>

int berry::Engine::getMaxVertexAttribs() {
    int max;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &max);
    return max;
}
