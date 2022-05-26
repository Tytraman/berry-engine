#include <berry-engine/vao.h>

#include <stdlib.h>

#include <glad/glad.h>

berry::VAO::VAO(const VBO &_vbo, const EBO *_ebo) : vbo(_vbo) {
    this->ebo = _ebo;
    this->attributes.length = 0;
    this->attributes.elements = NULL;
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);
}

void berry::VAO::bind() const {
    glBindVertexArray(this->vao);
}

cake_bool berry::VAO::addAttribute(uint index, int componentsNumber, int stride, ulonglong offset) {
    void *ptr = realloc(this->attributes.elements, (this->attributes.length + 1) * sizeof(*this->attributes.elements));
    if(ptr == NULL)
        return cake_false;
    this->attributes.elements = (struct berry::VAO::attributes_b::elements_b *) ptr;

    this->attributes.elements[this->attributes.length].index = index;
    this->attributes.elements[this->attributes.length].componentsNumber = componentsNumber;
    this->attributes.elements[this->attributes.length].stride = stride;
    this->attributes.elements[this->attributes.length].offset = offset;

    (this->attributes.length)++;

    glBindVertexArray(this->vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo.vbo);
    if(this->ebo != nullptr)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo->ebo);
    glVertexAttribPointer(index, componentsNumber, GL_FLOAT, GL_FALSE, stride, (const void *) offset);
    glEnableVertexAttribArray(index);
    return cake_true;
}
