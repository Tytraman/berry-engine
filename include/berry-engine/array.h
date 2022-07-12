#ifndef __BERRY_ARRAY_H__
#define __BERRY_ARRAY_H__

#include <libcake/def.h>
#include <berry-engine/vertex.h>

#include <stdlib.h>
#include <stdio.h>

namespace berry {

    template<typename T>
    class ArrayList {
        public:
            ArrayList() {
                this->m_Array = NULL;
                this->m_Length = 0;
            }

            ~ArrayList() {
                free(this->m_Array);
            }

            cake_bool push(const T &value) {
                void *ptr = realloc(m_Array, (m_Length + 1) * sizeof(T));
                if(ptr == NULL)
                    return cake_false;
                m_Array = (T *) ptr;
                m_Array[m_Length] = value;
                m_Length++;
                return cake_true;
            }

            cake_bool insert(const T &value, ulonglong index) {
                if(index > m_Length)
                    return cake_false;
                void *ptr = realloc(m_Array, (m_Length + 1) * sizeof(T));
                if(ptr == NULL)
                    return cake_false;
                m_Array = (T *) ptr;
                if(index < m_Length)
                    memcpy(m_Array + index + 1, m_Array + index, (m_Length - index) * sizeof(T));
                m_Array[index] = value;
                m_Length++;
                return cake_true;
            }

            cake_bool remove(ulonglong index, T *backup = nullptr) {
                if(index >= m_Length)
                    return cake_false;
                if(backup != nullptr)
                    *backup = m_Array[index];
                if(index < m_Length - 1)
                    memcpy(m_Array + index, m_Array + index + 1, (m_Length - index) * sizeof(T));
                m_Length--;
                if(m_Length == 0) {
                    free(m_Array);
                    m_Array = NULL;
                }else {
                    void *ptr = realloc(m_Array, m_Length * sizeof(T));
                    if(ptr != NULL)
                        m_Array = (T *) ptr;
                }
                return cake_true;
            }

            cake_bool pop(T *backup = nullptr) {
                if(m_Length == 0)
                    return cake_false;
                if(backup != nullptr)
                    *backup = m_Array[m_Length - 1];
                m_Length--;
                if(m_Length == 0) {
                    free(m_Array);
                    m_Array = NULL;
                }else {
                    void *ptr = realloc(m_Array, m_Length * sizeof(T));
                    if(ptr != NULL)
                        m_Array = (T *) ptr;
                }
                return cake_true;
            }

            cake_bool swap(ulonglong i, ulonglong j) {
                if(i >= m_Length || j >= m_Length)
                    return cake_false;
                T temp = m_Array[i];
                m_Array[i] = m_Array[j];
                m_Array[j] = temp;
                return cake_true;
            }

            T operator[](ulonglong index) const {
                return *(m_Array + index);
            }

            T *begin() const {
                return m_Array;
            }

            T *end() const {
                return m_Array + m_Length;
            }

            ulonglong getLength() const {
                return m_Length;
            }

            T *getRawData() {
                return m_Array;
            }

        private:
            T *m_Array;
            ulonglong m_Length;
    };

}

#endif