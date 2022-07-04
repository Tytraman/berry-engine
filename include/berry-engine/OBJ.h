#ifndef __BERRY_OBJ_H__
#define __BERRY_OBJ_H__

#include <libcake/def.h>

#include <berry-engine/mesh.h>
#include <berry-engine/array.h>

namespace berry {

    class OBJ {
        public:
            static Mesh load(const char *filename);
    };

}

#endif