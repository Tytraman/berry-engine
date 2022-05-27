#include <berry-engine/shaders.h>

#include <glad/glad.h>

berry::VertexShader::VertexShader(const char *source) {
    this->source = cake_strutf8(source);
    this->shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->shader, 1, (char **) &this->source->bytes, NULL);
}

berry::VertexShader::VertexShader(Cake_String_UTF8 *source) {
    this->source = source;
    this->shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->shader, 1, (char **) &this->source->bytes, NULL);
}

berry::VertexShader::~VertexShader() {
    cake_free_strutf8(this->source);
}

char *berry::VertexShader::compile() const {
    glCompileShader(this->shader);
    int iv;
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &iv);
    if(!iv) {
        glGetShaderiv(this->shader, GL_INFO_LOG_LENGTH, &iv);
        char *log = new char[iv];
        glGetShaderInfoLog(this->shader, iv, NULL, log);
        return log;
    }
    return nullptr;
}

void berry::VertexShader::destroy() const {
    glDeleteShader(this->shader);
}

berry::FragmentShader::FragmentShader(const char *source) {
    this->source = cake_strutf8(source);
    this->shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->shader, 1, (char **) &this->source->bytes, NULL);
}

berry::FragmentShader::FragmentShader(Cake_String_UTF8 *source) {
    this->source = source;
    this->shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->shader, 1, (char **) &this->source->bytes, NULL);
}

berry::FragmentShader::~FragmentShader() {
    cake_free_strutf8(this->source);
}

char *berry::FragmentShader::compile() const {
    glCompileShader(this->shader);
    int iv;
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &iv);
    if(!iv) {
        glGetShaderiv(this->shader, GL_INFO_LOG_LENGTH, &iv);
        char *log = new char[iv];
        glGetShaderInfoLog(this->shader, iv, NULL, log);
        return log;
    }
    return nullptr;
}

void berry::FragmentShader::destroy() const {
    glDeleteShader(this->shader);
}

berry::ShaderProgram::ShaderProgram(const VertexShader &_vertex, const FragmentShader &_fragment) : vertex(_vertex), fragment(_fragment) {
    this->program = glCreateProgram();
    glAttachShader(this->program, vertex.shader);
    glAttachShader(this->program, fragment.shader);
}

char *berry::ShaderProgram::link() {
    glLinkProgram(this->program);
    int iv;
    glGetProgramiv(this->program, GL_LINK_STATUS, &iv);
    if(!iv) {
        glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &iv);
        char *log = new char[iv];
        glGetProgramInfoLog(this->program, iv, NULL, log);
        return log;
    }
    return nullptr;
}

void berry::ShaderProgram::use() {
    glUseProgram(this->program);
}

void berry::ShaderProgram::setUniform(const char *uniformName, float v) const {
    int location = glGetUniformLocation(this->program, uniformName);
    glUseProgram(this->program);
    glUniform1f(location, v);
}

void berry::ShaderProgram::setUniform(const char *uniformName, float v1, float v2) const {
    int location = glGetUniformLocation(this->program, uniformName);
    glUseProgram(this->program);
    glUniform2f(location, v1, v2);
}

void berry::ShaderProgram::setUniform(const char *uniformName, float v1, float v2, float v3) const {
    int location = glGetUniformLocation(this->program, uniformName);
    glUseProgram(this->program);
    glUniform3f(location, v1, v2, v3);
}

void berry::ShaderProgram::setUniform(const char *uniformName, float v1, float v2, float v3, float v4) const {
    int location = glGetUniformLocation(this->program, uniformName);
    glUseProgram(this->program);
    glUniform4f(location, v1, v2, v3, v4);
}

void berry::ShaderProgram::setUniform(const char *uniformName, const Mat4 &mat) const {
    int location = glGetUniformLocation(this->program, uniformName);
    glUseProgram(this->program);
    glUniformMatrix4fv(location, 1, GL_FALSE, mat.data);
}
