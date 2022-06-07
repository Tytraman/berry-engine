#include <berry-engine/object.h>
#include <berry-engine/def.h>

#include <glad/glad.h>

berry::Object::Object(VAO &_vao, ShaderProgram &_shader, float x, float y, float z, float degreesX, float degreesY, float degreesZ, float scaleX, float scaleY, float scaleZ) : vao(_vao), shader(_shader) {
    this->pos = Vec3(x, y, z);
    this->rotate = Vec3(degreesX, degreesY, degreesZ);
    this->scale = Vec3(scaleX, scaleY, scaleZ);
}

void berry::Object::render() const {
    Mat4 model(1.0f);
    model = Mat4::translate(model, this->pos.x, this->pos.y, this->pos.z);
    model = Mat4::rotateX(model, this->rotate.x * BERRY_PI / 180.0f);
    model = Mat4::rotateY(model, this->rotate.y * BERRY_PI / 180.0f);
    model = Mat4::rotateZ(model, this->rotate.z * BERRY_PI / 180.0f);
    model = Mat4::scale(model, this->scale.x, this->scale.y, this->scale.z);
    shader.setUniform("model", model);

    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, vao.vbo.verticesNumber);
}
