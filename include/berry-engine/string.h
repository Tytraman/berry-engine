#ifndef __BERRY_STRING_H__
#define __BERRY_STRING_H__

#include <berry-engine/types.h>
#include <berry-engine/array.h>

namespace berry {

    class String {

        public:
            String();
            String(const String &str);
            String(String &&str);
            String(const char *str);
            String(const byte *src, ulonglong size);
            
            ~String();

            String &operator=(const String &str);

            String &operator+=(const char *str);
            String &operator+=(const String &str);

            String operator+(const char *str);
            String operator+(const String &str);

            char operator[](ulonglong index) const;

            void clear();
            String &insert(ulonglong index, const char *str);

            String &append(const char *str);
            String &append(const String &str);
            
            const char *search(const char *str, ulonglong size) const;
            const char *search(const char *str) const;

            const char *searchFromEnd(const char *str, ulonglong size) const;
            const char *searchFromEnd(const char *str) const;

            const char *searchFromIndex(ulonglong index, const char *str, ulonglong size, ulonglong *nextIndex = nullptr) const;

            void split(const char *delim, ArrayList<String> &dest) const;

            ulonglong size() const;
            char *str();

            byte *begin() const;
            byte *end() const;

            static ulonglong count(const char *str);

        private:
            byte *m_Data;
            ulonglong m_Size;
    };

    inline String String::operator+(const char *str) {
        String s = this->str();
        s += str;
        return s;
    }

    inline String String::operator+(const String &str) {
        String s = *this;
        s += str;
        return s;
    }

    inline String &String::append(const char *str) {
        return *this += str;
    }

    inline String &String::append(const String &str) {
        return *this += str;
    }

    inline const char *String::search(const char *str, ulonglong size) const {
        return searchFromIndex(0, str, size);
    }

    inline const char *String::search(const char *str) const {
        return search(str, String::count(str));
    }

    inline const char *String::searchFromEnd(const char *str) const {
        return searchFromEnd(str, String::count(str));
    }

}

#endif