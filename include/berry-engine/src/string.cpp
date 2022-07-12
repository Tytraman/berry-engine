#include <berry-engine/string.h>

#include <stdlib.h>
#include <string.h>

berry::ulonglong berry::String::count(const char *str) {
    ulonglong a = 0;
    while(str[a] != '\0')
        a++;
    return a;
}

berry::String::String() {
    m_Data = NULL;
    m_Size = 0;
}

berry::String::String(const char *str) {
    m_Size = String::count(str);
    m_Data = (byte *) malloc((m_Size + 1) * sizeof(byte));
    memcpy(m_Data, str, m_Size * sizeof(byte));
    m_Data[m_Size] = '\0';
}

berry::String::String(const byte *src, ulonglong size) {
    m_Size = size;
    m_Data = (byte *) malloc((m_Size + 1) * sizeof(byte));
    memcpy(m_Data, src, m_Size * sizeof(byte));
    m_Data[m_Size] = '\0';
}

berry::String::String(const String &str) {
    if(str.m_Data != NULL) {
        m_Data = (byte *) malloc((str.m_Size + 1) * sizeof(byte));
        if(m_Data != NULL) {
            m_Size = str.m_Size;
            memcpy(m_Data, str.m_Data, str.m_Size * sizeof(byte));
            m_Data[m_Size] = '\0';
        }else
            m_Size = 0;
    }else {
        m_Size = 0;
        m_Data = NULL;
    }
}

berry::String::~String() {
    free(m_Data);
}

berry::String &berry::String::operator+=(const char *str) {
    ulonglong length = String::count(str);
    ulonglong total = length + m_Size;
    void *ptr = realloc(m_Data, (total + 1) * sizeof(byte));
    if(ptr == NULL)
        return *this;
    m_Data = (byte *) ptr;
    memcpy(m_Data + m_Size, str, length * sizeof(byte));
    m_Size = total;
    m_Data[m_Size] = '\0';
    return *this;
}

berry::String &berry::String::operator+=(const String &str) {
    ulonglong total = str.m_Size + m_Size;
    void *ptr = realloc(m_Data, (total + 1) * sizeof(byte));
    if(ptr == NULL)
        return *this;
    m_Data = (byte *) ptr;
    memcpy(m_Data + m_Size, str.m_Data, str.m_Size * sizeof(byte));
    m_Size = total;
    m_Data[m_Size] = '\0';
    return *this;
}

char berry::String::operator[](ulonglong index) const {
    return (char) m_Data[index];
}

void berry::String::clear() {
    free(m_Data);
    m_Data = NULL;
    m_Size = 0;
}

berry::String &berry::String::insert(ulonglong index, const char *str) {
    if(index > m_Size)
        return *this;
    ulonglong length = String::count(str);
    ulonglong total = length + m_Size;
    void *ptr = realloc(m_Data, (total + 1) * sizeof(byte));
    if(ptr == NULL)
        return *this;
    if(index < m_Size)
        memcpy(m_Data + index + length, m_Data + index, (m_Size - index) * sizeof(byte));
    memcpy(m_Data + index, str, length * sizeof(byte));
    m_Size = total;
    m_Data[m_Size] = '\0';
    return *this;
}

const char *berry::String::search(const char *str, ulonglong size) const {
    if(size > m_Size)
        return nullptr;
    ulonglong i;
    byte *f = (byte *) str;
    byte *ptr = m_Data;
    for(i = 0; i < m_Size; ++i) {
        if(m_Data[i] == *f) {
            f++;
            if(*f == '\0')
                return (const char *) ptr;
        }else {
            f = (byte *) str;
            ptr = m_Data + i + 1;
        }
    }
    return nullptr;
}

const char *berry::String::searchFromEnd(const char *str, ulonglong size) const {
    if(size > m_Size)
        return nullptr;
    byte *current = m_Data + m_Size - size;
    byte *f;
    byte *g;
    while(current >= m_Data) {
        f = (byte *) str;
        g = current;
        while(*f == *g) {
            f++;
            if(*f == '\0')
                return (const char *) current;
            g++;
        }
        current--;
    }
    return nullptr;
}

berry::ulonglong berry::String::size() const {
    return m_Size;
}

char *berry::String::str() {
    return (char *) m_Data;
}

berry::byte *berry::String::begin() const {
    return m_Data;
}

berry::byte *berry::String::end() const {
    return m_Data + m_Size;
}
