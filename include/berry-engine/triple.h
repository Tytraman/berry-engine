#ifndef __BERRY_TRIPLE_H__
#define __BERRY_TRIPLE_H__

namespace berry {

    template<typename A, typename B, typename C>
    class Triple {
        public:
            Triple(){};

            Triple(const A &left, const B &middle, const C &right) {
                this->m_Left = left;
                this->m_Middle = middle;
                this->m_Right = right;
            }

            A getLeft() const {
                return m_Left;
            }

            B getMiddle() const {
                return m_Middle;
            }

            C getRight() const {
                return m_Right;
            }

            void setLeft(const A &value) {
                this->m_Left = value;
            }

            void setMiddle(const B &value) {
                this->m_Middle = value;
            }

            void setRight(const C &value) {
                this->m_Right = value;
            }

        private:
            A m_Left;
            B m_Middle;
            C m_Right;
    };

}

#endif