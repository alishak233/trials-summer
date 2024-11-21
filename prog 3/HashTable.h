#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashNode.h"
#include <vector>
#include <string>
#include <iostream>

template <typename T>
class HashTable {
private:
    std::vector<HashNode<T>*> table; // Array of pointers to HashNode
    int tableSize;                  // Total number of buckets
    int numElements;                // Number of elements in the table
    mutable unsigned long compareCount; // Tracks the number of comparisons (mutable for const methods)

    // Hash function
    int hashFunction(const T& key) const {
    unsigned long hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % tableSize;
    }
    return hash % tableSize;
    }


public:
    // Constructor
    HashTable(int size = 100000) : tableSize(size), numElements(0), compareCount(0) {
        table.resize(tableSize, nullptr);
    }

    // Destructor
    ~HashTable() {
        for (auto& node : table) {
            while (node) {
                HashNode<T>* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }

    // Insert a word into the hash table
    void insert(const T& key) {
        int hashIndex = hashFunction(key);

        // Check if the key already exists
        HashNode<T>* current = table[hashIndex];
        while (current) {
            if (current->key == key) {
                return; // Key already exists, no duplicate insertion
            }
            current = current->next;
        }

        // Insert new node at the beginning of the linked list
        HashNode<T>* newNode = new HashNode<T>(key);
        newNode->next = table[hashIndex];
        table[hashIndex] = newNode;
        ++numElements;
    }

    // Find a word in the hash table
    bool find(const T& key) const {
        int hashIndex = hashFunction(key);
        compareCount = 0; // Reset compareCount before search

        HashNode<T>* current = table[hashIndex];
        while (current) {
            compareCount++; // Increment compareCount for each comparison
            if (current->key == key) {
                return true; // Found the key
            }
            current = current->next;
        }
        return false; // Key not found
    }
    
    std::vector<T> getAllKeys() const {
        std::vector<T> keys;
        for (const auto& bucket : table) {
            HashNode<T>* current = bucket;
            while (current) {
                keys.push_back(current->key);
                current = current->next;
            }
        }
        return keys;
    }

    // Get the size (number of elements in the hash table)
    int getSize() const {
        return numElements;
    }

    // Check if the hash table is empty
    bool isEmpty() const {
        return numElements == 0;
    }
    
    // Get the comparison count
    unsigned long getCompareCount() const {
        return compareCount;
    }
};

#endif // HASHTABLE_H
