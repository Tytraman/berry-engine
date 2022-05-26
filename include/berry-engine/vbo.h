#ifndef __BERRY_VBO_H__
#define __BERRY_VBO_H__

#include <libcake/def.h>

namespace berry {

    class VBO {
        public:
            uint vbo;
            void *buffer;
            longlong size;

        VBO(const void *buffer, longlong size);
        ~VBO();
        void bind() const;
    };

}

#endif