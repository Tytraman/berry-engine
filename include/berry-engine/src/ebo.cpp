#include <berry-engine/ebo.h>

#include <glad/glad.h>

berry::EBO::EBO(uint *indices, ulonglong size) {
    this->size = size;
    this->indices = (uint *) new uchar[this->size];
    memcpy(this->indices, indices, this->size);
    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->size, this->indices, GL_STATIC_DRAW);
}

berry::EBO::~EBO() {
    delete this->indices;
}

void berry::EBO::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
}
