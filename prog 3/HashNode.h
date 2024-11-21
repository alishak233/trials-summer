#ifndef HASHNODE_H
#define HASHNODE_H

template <typename T>
class HashNode {
public:
    T key;
    HashNode* next;

    // Constructor
    HashNode(T key) : key(key), next(nullptr) {}
};

#endif // HASHNODE_H