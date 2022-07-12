#ifndef __BERRY_PAIR_H__
#define __BERRY_PAIR_H__

namespace berry {

    template<typename A, typename B>
    class Pair{
        public:
            Pair(){};

            Pair(const A &key, const B &value) {
                this->m_Key = key;
                this->m_Value = value;
            }

            A getKey() const {
                return m_Key;
            }

            B getValue() const {
                return m_Value;
            }

            void setKey(const A &key) {
                this->m_Key = key;
            }

            void setValue(const B &value) {
                this->m_Value = value;
            }

        private:
            A m_Key;
            B m_Value;
    };

}

#endif