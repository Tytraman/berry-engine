#include <berry-engine/vbo.h>

#include <glad/glad.h>

#include <stdio.h>

berry::VBO::VBO(const void *buffer, longlong size) {
    this->buffer = new uchar[size];
    this->size   = size;

    memcpy(this->buffer, buffer, this->size);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->size, this->buffer, GL_STATIC_DRAW);
}

berry::VBO::~VBO() {
    delete (uchar *) this->buffer;
}

void berry::VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
}
