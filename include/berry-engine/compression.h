#ifndef __BERRY_COMPRESSION_H__
#define __BERRY_COMPRESSION_H__

#include <libcake/strutf8.h>
#include <berry-engine/array.h>
#include <berry-engine/pair.h>
#include <berry-engine/triple.h>

namespace berry {

    struct LeafNode {
        uchar c;
        ushort freq;
        LeafNode *left;
        LeafNode *right;

        LeafNode(char c, ushort freq = 1, LeafNode *left = nullptr, LeafNode *right = nullptr);
    };

    class Huffman {
        public:
            static void compress(const Cake_String_UTF8 *str, ArrayList<Pair<uchar, Cake_String_UTF8 *>> &dest);
    };

}

#endif