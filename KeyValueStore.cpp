#include "KeyValueStore.h"

// constructor (empty)
KeyValueStore::KeyValueStore() {}

// destructor (empty)
KeyValueStore::~KeyValueStore() {}

// put
void KeyValueStore::Put(std::string key, std::string value) {
    m_tree.Insert(key, value);
}

// get 
std::optional<std::string> KeyValueStore::Get(std::string key) {
    auto result = m_tree.Search(key);
    if(result.has_value()) {
        return result.value();
    } else {
        return std::nullopt;
    }
}

// remove
void KeyValueStore::Remove(std::string key) {
    m_tree.Remove(key);
}

// range query
std::vector<std::pair<std::string, std::string>> KeyValueStore::RangeQuery(std::string low, std::string high) {
    return m_tree.RangeQuery(low, high);
}

// get size
int KeyValueStore::Size() {
    return m_tree.Size();
}

// is empty
bool KeyValueStore::IsEmpty() {
    return m_tree.IsEmpty();
}

// clear tree
void KeyValueStore::Clear() {
    m_tree.Clear();
}