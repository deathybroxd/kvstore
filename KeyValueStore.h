#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H
#include "RB_Tree.h"

class KeyValueStore {
public:
    // default constructor
    KeyValueStore();

    // destuctor
    ~KeyValueStore();

    // delete copy constructor - no implementation
    KeyValueStore(const KeyValueStore&) = delete;

    // delete copy assignment operator - no implementation
    KeyValueStore& operator=(const KeyValueStore&) = delete;

    // put
    void Put(std::string key, std::string value);

    // get 
    std::optional<std::string> Get(std::string key);

    // remove
    void Remove(std::string key);

    // range query
    std::vector<std::pair<std::string, std::string>> RangeQuery(std::string low, std::string high);

    // get size
    int Size();

    // is empty
    bool IsEmpty();

    // clear tree
    void Clear();

private:
    RBTree<std::string, std::string> m_tree;
};

#endif