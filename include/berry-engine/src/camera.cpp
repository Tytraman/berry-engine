#include <berry-engine/camera.h>
#include <berry-engine/def.h>

#include <math.h>

berry::Camera::Camera(const Vec3 &pos, const Vec3 &front, const Vec3 &baseUp) {
    this->pos = pos;
    this->baseUp = baseUp;
    this->front = front;

    this->yaw = -90.0f;
    this->pitch = 0.0f;

    update();
}

berry::Mat4 berry::Camera::lookAt() const {
    Vec3 direction = Vec3::normalize(this->pos - (this->pos + this->front));
    Vec3 right = Vec3::normalize(Vec3::cross(this->up, direction));
    Vec3 up = Vec3(Vec3::cross(direction, right));

    float values[] = {
        right.x,               up.x,               direction.x,               0.0f,
        right.y,               up.y,               direction.y,               0.0f,
        right.z,               up.z,               direction.z,               0.0f,
        -right.dot(this->pos), -up.dot(this->pos), -direction.dot(this->pos), 1.0f
    };
    return Mat4(values);
}

void berry::Camera::update() {
    Vec3 front;
    float cosYaw = cosf(this->yaw * BERRY_PI / 180.0f);
    float cosPitch = cosf(this->pitch * BERRY_PI / 180.0f);

    float sinYaw = sinf(this->yaw * BERRY_PI / 180.0f);
    float sinPitch = sinf(this->pitch * BERRY_PI / 180.0f);

    front.x = cosYaw * cosPitch;
    front.y = sinPitch;
    front.z = sinYaw * cosPitch;

    this->front = Vec3::normalize(front);
    this->right = Vec3::normalize(Vec3::cross(this->front, this->baseUp));
    this->up = Vec3::normalize(Vec3::cross(this->right, this->front));
}
