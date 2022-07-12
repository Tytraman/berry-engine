#include <berry-engine/compression.h>

#include <stdio.h>

berry::LeafNode::LeafNode(char _c, ushort _freq, LeafNode *_left, LeafNode *_right) :
    c(_c), freq(_freq), left(_left), right(_right)
{}

void berry::Huffman::compress(const Cake_String_UTF8 *str, ArrayList<Pair<uchar, Cake_String_UTF8 *>> &dest) {
    ArrayList<LeafNode> list;
    ulonglong i;
    // Récupération des caractères
    for(i = 0; i < str->data.length; ++i) {
        for(LeafNode &node : list) {
            if(node.c == str->bytes[i]) {
                node.freq++;
                goto skip;
            }
        }
        list.push(LeafNode((str->bytes[i])));
    skip: ;
    }

    ushort j;
    // Trie dans l'ordre croissant
    for(i = 0; i < list.getLength() - 1; ++i) {
        for(j = i + 1; j < list.getLength(); ++j) {
            if(list[j].freq < list[i].freq)
                list.swap(i, j);
        }
    }

    while(list.getLength() > 1) {
        LeafNode z('\0', list[0].freq + list[1].freq, new LeafNode(list[0]), new LeafNode(list[1]));
        list.remove(0);
        list.remove(0);
        for(i = 0; i < list.getLength(); ++i) {
            if(z.freq < list[i].freq)
                break;
        }
        list.insert(z, i);
    }

    ArrayList<Triple<LeafNode *, Cake_String_UTF8 *, cake_byte>> history;
    Cake_String_UTF8 *firstCode = cake_strutf8("");
    history.push(Triple<LeafNode *, Cake_String_UTF8 *, cake_byte>(list.getRawData(), firstCode, 0));
    LeafNode *currentNode;
    Cake_String_UTF8 *currentCode;

    while(history.getLength() > 0) {
        Triple<LeafNode *, Cake_String_UTF8 *, cake_byte> *current = history.getRawData() + history.getLength() - 1;
        currentNode = current->getLeft();
        currentCode = current->getMiddle();

        switch(current->getRight()) {
            default: break;
            // A gauche
            case 0:{
                current->setRight(1);
                if(currentNode->left != nullptr) {
                    Cake_String_UTF8 *copy = cake_strutf8("");
                    cake_strutf8_copy(copy, currentCode);
                    cake_strutf8_add_char_array(copy, "0");
                    history.push(Triple<LeafNode *, Cake_String_UTF8 *, cake_byte>(currentNode->left, copy, 0));
                }
            } continue;
            // A droite
            case 1:{
                current->setRight(2);
                if(currentNode->right != nullptr) {
                    Cake_String_UTF8 *copy = cake_strutf8("");
                    cake_strutf8_copy(copy, currentCode);
                    cake_strutf8_add_char_array(copy, "1");
                    history.push(Triple<LeafNode *, Cake_String_UTF8 *, cake_byte>(currentNode->right, copy, 0));
                }
            } continue;
        }
        if(currentNode->c != '\0')
            dest.push(Pair<uchar, Cake_String_UTF8 *>(currentNode->c, currentCode));
        history.pop();
    }
    cake_free_strutf8(firstCode);
    dest.pop();
}
