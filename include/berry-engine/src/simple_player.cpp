#include <berry-engine/simple_player.h>
#include <berry-engine/engine.h>

berry::SimplePlayer::SimplePlayer(float _speed, float x, float y, float z) :
    camera(Vec3(x, y, z), Vec3(0.0f, 0.0f, -1.0f)), speed(_speed)
{}

void berry::SimplePlayer::moveForward(float value) {
    Vec3 front = this->camera.front;
    // On bloque l'axe Y pour ne pas "voler"
    front.y = 0.0f;
    float length = front.length();
    front.x *= 1.0f / length;
    front.z *= 1.0f / length;
    this->camera.pos += front * value * this->speed * Engine::realDeltaTime;
}

void berry::SimplePlayer::moveRight(float value) {
    Vec3 right = this->camera.right;
    // On bloque l'axe Y pour ne pas "voler"
    right.y = 0.0;
    float length = right.length();
    right.x *= 1.0f / length;
    right.z *= 1.0f / length;
    this->camera.pos += right * value * this->speed * Engine::realDeltaTime;
}

void berry::SimplePlayer::moveBackward(float value) {
    Vec3 front = this->camera.front;
    // On bloque l'axe Y pour ne pas "voler"
    front.y = 0.0f;
    float length = front.length();
    front.x *= 1.0f / length;
    front.z *= 1.0f / length;
    this->camera.pos -= front * value * this->speed * Engine::realDeltaTime;
}

void berry::SimplePlayer::moveLeft(float value) {
    Vec3 right = this->camera.right;
    // On bloque l'axe Y pour ne pas "voler"
    right.y = 0.0f;
    float length = right.length();
    right.x *= 1.0 / length;
    right.z *= 1.0f / length;
    this->camera.pos -= right * value * this->speed * Engine::realDeltaTime;
}
