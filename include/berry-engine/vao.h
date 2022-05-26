#ifndef __BERRY_VAO_H__
#define __BERRY_VAO_H__

#include <libcake/def.h>

#include <berry-engine/vbo.h>
#include <berry-engine/ebo.h>

namespace berry {

    class VAO {
        public:
            uint vao;

            VAO(const VAO &) = delete;
            VAO(const VAO &&) = delete;

            VAO(const VBO &vbo, const EBO *ebo = nullptr);
            cake_bool addAttribute(uint index, int componentsNumber, int stride, ulonglong offset);

            void bind() const;
        private:
            struct attributes_b{
                ulonglong length;
                struct elements_b {
                    uint index;
                    int componentsNumber;
                    int stride;
                    ulonglong offset;
                } *elements;
            };
            const VBO &vbo;
            const EBO *ebo;

            attributes_b attributes;
    };

}

#endif