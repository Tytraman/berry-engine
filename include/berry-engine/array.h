#ifndef __BERRY_ARRAY_H__
#define __BERRY_ARRAY_H__

#include <berry-engine/types.h>
#include <berry-engine/vertex.h>

#include <utility>
#include <stdlib.h>
#include <stdio.h>

namespace berry {

    template<typename T>
    class ArrayList {
        public:
            ArrayList() {
                m_Array = NULL;
                m_Length = 0;
            }

            ArrayList(const ArrayList &another) {
                if(another.m_Array != NULL) {
                    m_Array = (byte *) malloc(another.m_Length * sizeof(T));
                    if(m_Array != NULL) {
                        memcpy(m_Array, another.m_Array, another.m_Length * sizeof(T));
                        m_Length = another.m_Length;
                    }else
                        m_Length = 0;
                }else {
                    m_Length = 0;
                    m_Array = NULL;
                }
            }

            ~ArrayList() {
                T *current = (T *) m_Array;
                T *end = ((T *) m_Array) + m_Length;
                while(current != end) {
                    current->~T();
                    current++;
                }
                free(m_Array);
            }

            boolean push(const T &value) {
                void *ptr = realloc(m_Array, (m_Length + 1) * sizeof(T));
                if(ptr == NULL)
                    return false;
                m_Array = (byte *) ptr;
                ((T *) m_Array)[m_Length] = value;
                m_Length++;
                return true;
            }

            template<typename... Types>
            boolean emplace(Types&&... args) {
                void *ptr = realloc(m_Array, (m_Length + 1) * sizeof(T));
                if(ptr == NULL)
                    return false;
                m_Array = (byte *) ptr;
                *(((T *) m_Array) + m_Length) = { std::forward<Types>(args)... };
                m_Length++;
                return true;
            }

            boolean insert(const T &value, ulonglong index) {
                if(index > m_Length)
                    return false;
                void *ptr = realloc(m_Array, (m_Length + 1) * sizeof(T));
                if(ptr == NULL)
                    return false;
                m_Array = (byte *) ptr;
                if(index < m_Length)
                    memcpy(((T *) m_Array) + index + 1, ((T *) m_Array) + index, (m_Length - index) * sizeof(T));
                ((T *) m_Array)[index] = value;
                m_Length++;
                return true;
            }

            boolean remove(ulonglong index, T *backup = nullptr) {
                if(index >= m_Length)
                    return false;
                if(backup != nullptr)
                    *backup = ((T *) m_Array)[index];
                if(index < m_Length - 1)
                    memcpy(((T *) m_Array) + index, ((T *) m_Array) + index + 1, (m_Length - index) * sizeof(T));
                m_Length--;
                if(m_Length == 0) {
                    free(m_Array);
                    m_Array = NULL;
                }else {
                    void *ptr = realloc(m_Array, m_Length * sizeof(T));
                    if(ptr != NULL)
                        m_Array = (byte *) ptr;
                }
                return true;
            }

            boolean pop(T *backup = nullptr) {
                if(m_Length == 0)
                    return false;
                if(backup != nullptr)
                    *backup = ((T *) m_Array)[m_Length - 1];
                m_Length--;
                if(m_Length == 0) {
                    free(m_Array);
                    m_Array = NULL;
                }else {
                    void *ptr = realloc(m_Array, m_Length * sizeof(T));
                    if(ptr != NULL)
                        m_Array = (byte *) ptr;
                }
                return true;
            }

            boolean swap(ulonglong i, ulonglong j) {
                if(i >= m_Length || j >= m_Length)
                    return false;
                T temp = ((T *) m_Array)[i];
                ((T *) m_Array)[i] = ((T *) m_Array)[j];
                ((T *) m_Array)[j] = temp;
                return true;
            }

            T operator[](ulonglong index) const {
                return (T) *((T *) m_Array + index);
            }

            T *begin() const {
                return (T *) m_Array;
            }

            T *end() const {
                return (T *) m_Array + m_Length;
            }

            ulonglong getLength() const {
                return m_Length;
            }

            T *get(ulonglong index) const {
                if(index >= m_Length)
                    return nullptr;
                return ((T *) m_Array + index);
            }

            T *getRawData() {
                return (T *) m_Array;
            }

        private:
            byte *m_Array;
            ulonglong m_Length;
    };

}

#endif