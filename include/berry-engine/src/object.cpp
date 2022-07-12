#include <berry-engine/object.h>
#include <berry-engine/def.h>

#include <glad/glad.h>

berry::Object::Object(
    Mesh *mesh,
    float x, float y, float z,
    float degreesX, float degreesY, float degreesZ,
    float scaleX, float scaleY, float scaleZ
) :
    m_Mesh(mesh)
{
    m_Pos = Vec3(x, y, z);
    m_Rotate = Vec3(degreesX, degreesY, degreesZ);
    m_Scale = Vec3(scaleX, scaleY, scaleZ);
}

void berry::Object::render(ShaderProgram &shader) const {
    Mat4 model(1.0f);
    model = Mat4::translate(model, m_Pos.x, m_Pos.y, m_Pos.z);
    model = Mat4::rotateX(model, m_Rotate.x * BERRY_PI / 180.0f);
    model = Mat4::rotateY(model, m_Rotate.y * BERRY_PI / 180.0f);
    model = Mat4::rotateZ(model, m_Rotate.z * BERRY_PI / 180.0f);
    model = Mat4::scale(model, m_Scale.x, m_Scale.y, m_Scale.z);
    shader.setUniform("model", model);

    glBindVertexArray(m_Mesh->getVAO());
    glDrawArrays(GL_TRIANGLES, 0, m_Mesh->getVerticesNumber());
}

/* Getters */

berry::Vec3 berry::Object::getPosition() const {
    return m_Pos;
}

berry::Vec3 berry::Object::getRotation() const {
    return m_Rotate;
}

berry::Vec3 berry::Object::getScale() const {
    return m_Scale;
}

berry::Mesh *berry::Object::getMesh() {
    return m_Mesh;
}

/* Setters */

void berry::Object::setPosition(const Vec3 &position) {
    m_Pos = position;
}

void berry::Object::setRotation(const Vec3 &rotation) {
    m_Rotate = rotation;
}

void berry::Object::setScale(const Vec3 &scale) {
    m_Scale = scale;
}

void berry::Object::setMesh(Mesh *mesh) {
    m_Mesh = mesh;
}
