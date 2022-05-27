#include <berry-engine/vectors.h>

#include <math.h>

berry::Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

berry::Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

berry::Vec2 berry::Vec2::operator+(float value) {
    return { this->x + value, this->y + value };
}

berry::Vec2 berry::Vec2::operator-(float value) {
    return { this->x - value, this->y - value };
}

berry::Vec2 berry::Vec2::operator*(float value) {
    return { this->x * value, this->y * value };
}

berry::Vec2 berry::Vec2::operator/(float value) {
    return { this->x / value, this->y / value };
}

berry::Vec2 berry::Vec2::operator-() {
    return { -this->x, -this->y };
}

void berry::Vec2::operator+=(float value) {
    this->x += value;
    this->y += value;
}

void berry::Vec2::operator-=(float value) {
    this->x -= value;
    this->y -= value;
}

void berry::Vec2::operator*=(float value) {
    this->x *= value;
    this->y *= value;
}

void berry::Vec2::operator/=(float value) {
    this->x /= value;
    this->y /= value;
}

void berry::Vec2::negate() {
    this->x = -this->x;
    this->y = -this->y;
}

berry::Vec2 berry::Vec2::operator+(const Vec2 &vec) {
    return { this->x + vec.x, this->y + vec.y };
}

berry::Vec2 berry::Vec2::operator-(const Vec2 &vec) {
    return { this->x - vec.x, this->y - vec.y };
}

float berry::Vec2::length() const {
    return sqrtf((this->x * this->x) + (this->y * this->y));
}

float berry::Vec2::dot(const Vec2 &vec) const {
    return (this->x * vec.x) + (this->y * vec.y);
}

berry::Vec3 berry::Vec3::operator+(float value) {
    return { this->x + value, this->y + value, this->z + value };
}

berry::Vec3 berry::Vec3::operator-(float value) {
    return { this->x - value, this->y - value, this->z - value };
}

berry::Vec3 berry::Vec3::operator*(float value) {
    return { this->x * value, this->y * value, this->z * value };
}

berry::Vec3 berry::Vec3::operator/(float value) {
    return { this->x / value, this->y / value, this->z / value };
}

berry::Vec3 berry::Vec3::operator-() {
    return { -this->x, -this->y, -this->z };
}

berry::Vec3 berry::Vec3::operator+(const Vec3 &vec) {
    return { this->x + vec.x, this->y + vec.y, this->z + vec.z };
}

berry::Vec3 berry::Vec3::operator-(const Vec3 &vec) {
    return { this->x - vec.x, this->y - vec.y, this->z - vec.z };
}

void berry::Vec3::operator+=(float value) {
    this->x += value;
    this->y += value;
    this->z += value;
}

void berry::Vec3::operator-=(float value) {
    this->x -= value;
    this->y -= value;
    this->z -= value;
}

void berry::Vec3::operator*=(float value) {
    this->x *= value;
    this->y *= value;
    this->z *= value;
}

void berry::Vec3::operator/=(float value) {
    this->x /= value;
    this->y /= value;
    this->z /= value;
}

void berry::Vec3::negate() {
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
}

float berry::Vec3::length() const {
    return sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

float berry::Vec3::dot(const Vec3 &vec) const {
    return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
}

berry::Vec4::Vec4(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float berry::Vec4::length() const {
    return sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
}

float berry::Vec4::dot(const Vec4 &vec) const {
    return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z) + (this->w * vec.w);
}
