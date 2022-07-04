#include <berry-engine/array.h>

#include <stdlib.h>

/* ========== FloatArray ========== */

berry::FloatArray::FloatArray() {
    this->array = NULL;
    this->length = 0;
}

berry::FloatArray::~FloatArray() {
    free(this->array);
}

cake_bool berry::FloatArray::add(float value) {
    void *ptr = realloc(array, (length + 1) * sizeof(float));
    if(ptr == NULL)
        return cake_false;
    array = (float *) ptr;
    array[length] = value;
    length++;
    return cake_true;
}

float berry::FloatArray::operator[](ulonglong index) const {
    return *(array + index);
}

/* ========== UIntArray ========== */

berry::UIntArray::UIntArray() {
    this->array = NULL;
    this->length = 0;
}

berry::UIntArray::~UIntArray() {
    free(this->array);
}

cake_bool berry::UIntArray::add(uint value) {
    void *ptr = realloc(array, (length + 1) * sizeof(uint));
    if(ptr == NULL)
        return cake_false;
    array = (uint *) ptr;
    array[length] = value;
    length++;
    return cake_true;
}

uint berry::UIntArray::operator[](ulonglong index) const {
    return *(array + index);
}

/* ========== VertexArray ========== */

berry::VertexArray::VertexArray() {
    this->array = NULL;
    this->length = 0;
}

berry::VertexArray::~VertexArray() {
    free(this->array);
}

cake_bool berry::VertexArray::add(Vertex value) {
    void *ptr = realloc(array, (length + 1) * sizeof(Vertex));
    if(ptr == NULL)
        return cake_false;
    array = (Vertex *) ptr;
    array[length] = value;
    length++;
    return cake_true;
}

berry::Vertex berry::VertexArray::operator[](ulonglong index) const {
    return *(array + index);
}

/* ========== Vec2Array ========== */

berry::Vec2Array::Vec2Array() {
    this->array = NULL;
    this->length = 0;
}

berry::Vec2Array::~Vec2Array() {
    free(this->array);
}

cake_bool berry::Vec2Array::add(Vec2 value) {
    void *ptr = realloc(array, (length + 1) * sizeof(Vec2));
    if(ptr == NULL)
        return cake_false;
    array = (Vec2 *) ptr;
    array[length] = value;
    length++;
    return cake_true;
}

berry::Vec2 berry::Vec2Array::operator[](ulonglong index) const {
    return *(array + index);
}

/* ========== Vec3Array ========== */

berry::Vec3Array::Vec3Array() {
    this->array = NULL;
    this->length = 0;
}

berry::Vec3Array::~Vec3Array() {
    free(this->array);
}

cake_bool berry::Vec3Array::add(Vec3 value) {
    void *ptr = realloc(array, (length + 1) * sizeof(Vec3));
    if(ptr == NULL)
        return cake_false;
    array = (Vec3 *) ptr;
    array[length] = value;
    length++;
    return cake_true;
}

berry::Vec3 berry::Vec3Array::operator[](ulonglong index) const {
    return *(array + index);
}
