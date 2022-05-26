#ifndef __BERRY_EBO_H__
#define __BERRY_EBO_H__

#include <libcake/def.h>

namespace berry {

    class EBO {
        public:
            uint *indices;
            ulonglong size;
            uint ebo;

            EBO(uint *indices, ulonglong size);
            ~EBO();

            void bind() const;
    };

}

#endif