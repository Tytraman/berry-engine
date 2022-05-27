#include <berry-engine/matrices.h>

#include <math.h>
#include <iostream>

berry::Mat4::Mat4(float diagonalValue) : data() {
    this->data[0] = diagonalValue;
    this->data[5] = diagonalValue;
    this->data[10] = diagonalValue;
    this->data[15] = diagonalValue;
}

berry::Mat4::Mat4(float values[16]) {
    memcpy(this->data, values, 16 * sizeof(float));
}

float berry::Mat4::operator()(int i, int j) const {
    return this->data[i + j * 4];
}

berry::Mat4 berry::Mat4::operator+(const Mat4 &mat) const {
    Mat4 ret(0.0f);
    uchar i;
    for(i = 0; i < 16; ++i)
        ret.data[i] = this->data[i] + mat.data[i];
    return ret;
}

berry::Mat4 berry::Mat4::operator-(const Mat4 &mat) const {
    Mat4 ret(0.0f);
    uchar i;
    for(i = 0; i < 16; ++i)
        ret.data[i] = this->data[i] - mat.data[i];
    return ret;
}

berry::Mat4 berry::Mat4::operator*(float value) const {
    Mat4 ret(0.0f);
    uchar i;
    for(i = 0; i < 16; ++i)
        ret.data[i] = this->data[i] * value;
    return ret;
}

berry::Mat4 berry::Mat4::operator*(const Mat4 &mat) const {
    Mat4 ret(0.0f);

    uchar p = 0;
    uchar i;
    uchar j;
    uchar k = 0;
    uchar l;

    uchar temp;

    for(j = 0; j < 4; ++j) {
        for(temp = 0; temp < 4; ++temp) {
            for(i = 0, l = 0; i < 4; ++i, ++l) {
                ret.data[p] += this->data[i + j * 4] * mat.data[k + l * 4];
            }
            k = (k + 1) % 4;
            p++;
        }
    }

    return ret;
}

berry::Vec4 berry::Mat4::operator*(const Vec4 &vec) const {
    return {
        this->data[0] * vec.x + this->data[1] * vec.y + this->data[2] * vec.z + this->data[3] * vec.w,
        this->data[4] * vec.x + this->data[5] * vec.y + this->data[6] * vec.z + this->data[7] * vec.w,
        this->data[8] * vec.x + this->data[9] * vec.y + this->data[10] * vec.z + this->data[11] * vec.w,
        this->data[12] * vec.x + this->data[13] * vec.y + this->data[14] * vec.z + this->data[15] * vec.w
    };
}

berry::Mat4 berry::Mat4::scale(const Mat4 &mat, float x, float y, float z) {
    float values[] = {
        x,    0.0f, 0.0f, 0.0f,
        0.0f, y,    0.0f, 0.0f,
        0.0f, 0.0f, z,    0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return Mat4(values) * mat;
}

berry::Mat4 berry::Mat4::translate(const Mat4 &mat, float x, float y, float z) {
    float values[] = {
        1.0f, 0.0f, 0.0f, x,
        0.0f, 1.0f, 0.0f, y,
        0.0f, 0.0f, 1.0f, z,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return Mat4(values) * mat;
}

berry::Mat4 berry::Mat4::rotateX(const Mat4 &mat, float radians) {
    float values[] = {
        1.0f, 0.0f,          0.0f,           0.0f,
        0.0f, cosf(radians), -sinf(radians), 0.0f,
        0.0f, sinf(radians), cosf(radians),  0.0f,
        0.0f, 0.0f,          0.0f,           1.0f
    };
    return Mat4(values) * mat;
}

berry::Mat4 berry::Mat4::rotateY(const Mat4 &mat, float radians) {
    float values[] = {
        cosf(radians),  0.0f, sinf(radians), 0.0f,
        0.0f,           1.0f, 0.0f,          0.0f,
        -sinf(radians), 0.0f, cos(radians),  0.0f,
        0.0f,           0.0f, 0.0f,          1.0f
    };
    return Mat4(values) * mat;
}

berry::Mat4 berry::Mat4::rotateZ(const Mat4 &mat, float radians) {
    float values[] = {
        cosf(radians), -sinf(radians), 0.0f, 0.0f,
        sinf(radians), cosf(radians),  0.0f, 0.0f,
        0.0f,          0.0f,           1.0f, 0.0f,
        0.0f,          0.0f,           0.0f, 1.0f
    };
    return Mat4(values) * mat;
}

void berry::Mat4::print() const {
    std::cout <<
        "{" << std::endl <<
        "  " << this->data[0] << ", " << this->data[1] << ", " << this->data[2] << ", " << this->data[3] << "," << std::endl <<
        "  " << this->data[4] << ", " << this->data[5] << ", " << this->data[6] << ", " << this->data[7] << "," << std::endl <<
        "  " << this->data[8] << ", " << this->data[9] << ", " << this->data[10] << ", " << this->data[11] << "," << std::endl <<
        "  " << this->data[12] << ", " << this->data[13] << ", " << this->data[14] << ", " << this->data[15] << std::endl << "}" << std::endl;
}
