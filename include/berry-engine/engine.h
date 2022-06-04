#ifndef __BERRY_ENGINE_H__
#define __BERRY_ENGINE_H__

#include <libcake/def.h>

namespace berry {

    class Engine {
        public:
            static int getMaxVertexAttribs();
            static void updateDeltaTime();
            static cake_bool updateFPSCount();

            static void setTargetFPS(ushort value);

            static ushort targetFPS;
            static float targetFrameTime;
            static ushort FPS;
            
            static float frameTime;
            static float deltaTime;
            static ulonglong lastFrame;

        private:
            static ushort m_FPSCount;
            static ushort m_Timer;
    };

}

#endif