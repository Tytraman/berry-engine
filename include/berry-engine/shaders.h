#ifndef __BERRY_SHADERS_H__
#define __BERRY_SHADERS_H__

#include <libcake/def.h>
#include <libcake/strutf8.h>

namespace berry {

    class VertexShader {
        public:
            Cake_String_UTF8 *source;
            uint shader;

            VertexShader(const VertexShader &) = delete;
            VertexShader(const VertexShader &&) = delete;

            VertexShader(const char *source);
            VertexShader(Cake_String_UTF8 *source);
            ~VertexShader();

            char *compile() const;
            void destroy() const;
    };

    class FragmentShader {
        public:
            Cake_String_UTF8 *source;
            uint shader;

            FragmentShader(const FragmentShader &) = delete;
            FragmentShader(const FragmentShader &&) = delete;

            FragmentShader(const char *source);
            FragmentShader(Cake_String_UTF8 *source);
            ~FragmentShader();

            char *compile() const;
            void destroy() const;
    };

    class ShaderProgram {
        public:
            const VertexShader &vertex;
            const FragmentShader &fragment;
            uint program;

            ShaderProgram(const VertexShader &vertex, const FragmentShader &fragment);
            ShaderProgram(const ShaderProgram &) = delete;
            ShaderProgram(const ShaderProgram &&) = delete;

            char *link();
            void use();

            void setUniform(const char *uniformName, float v) const;
            void setUniform(const char *uniformName, float v1, float v2) const;
            void setUniform(const char *uniformName, float v1, float v2, float v3) const;
            void setUniform(const char *uniformName, float v1, float v2, float v3, float v4) const;
    };

}

#endif