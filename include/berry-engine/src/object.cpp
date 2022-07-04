#include <berry-engine/object.h>
#include <berry-engine/def.h>

#include <glad/glad.h>

berry::Object::Object(
    Mesh &mesh,
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

    glBindVertexArray(m_Mesh.getVAO());
    glDrawArrays(GL_TRIANGLES, 0, m_Mesh.getVerticesNumber());
    //glDrawElements(GL_TRIANGLES, m_Mesh.getIndicesNumber(), GL_UNSIGNED_INT, m_Mesh.getIndicesPtr());
}
