#include <berry-engine/engine.h>

#include <libcake/time.h>
#include <stdlib.h>

#include <iostream>
#include <glad/glad.h>

ushort berry::Engine::targetFPS = 60;
float berry::Engine::targetFrameTime = 1000.0f / berry::Engine::targetFPS;
ushort berry::Engine::FPS = 0;
float berry::Engine::frameTime = 0.0f;
float berry::Engine::deltaTime = 0;
ulonglong berry::Engine::lastFrame = cake_get_current_time_millis();
ushort berry::Engine::m_FPSCount = 0;
ushort berry::Engine::m_Timer = 0;

int berry::Engine::getMaxVertexAttribs() {
    int max;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &max);
    return max;
}

void berry::Engine::updateDeltaTime() {
    ulonglong now = cake_get_current_time_millis();
    frameTime = (float) (now - lastFrame);
    lastFrame = now;
    deltaTime = frameTime / 1000.0f;
}

cake_bool berry::Engine::updateFPSCount() {
    m_FPSCount++;
    m_Timer += frameTime;
    if(m_Timer >= 1000) {
        FPS = m_FPSCount;
        m_Timer = 0;
        m_FPSCount = 0;
        return cake_true;
    }
    return cake_false;
}

void berry::Engine::setTargetFPS(ushort value) {
    targetFPS = value;
    targetFrameTime = 1.0f / targetFPS;
}
