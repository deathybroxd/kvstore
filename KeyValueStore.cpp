#include "KeyValueStore.h"

// constructor (empty)
KeyValueStore::KeyValueStore() {}

// destructor (empty)
KeyValueStore::~KeyValueStore() {}

// put
bool KeyValueStore::Put(std::string key, std::string value) {
    for(std::size_t i = 0; i < m_keys.size(); i++) {
        if(m_keys.at(i) == key) {
            return false;
        }
    }
    m_keys.push_back(key);
    m_tree.Insert(key, value);
    return true;
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
bool KeyValueStore::Remove(std::string key) {
    for(std::size_t i = 0; i < m_keys.size(); i++) {
        if(m_keys.at(i) == key) {
            m_tree.Remove(key);
            m_keys.erase(m_keys.begin() + i);
            return true;
        }
    }
    return false;
}

// range query
std::vector<std::pair<std::string, std::string>> KeyValueStore::RangeQuery(std::string low, std::string high) {
    return m_tree.RangeQuery(low, high);
}

void KeyValueStore::Print() {
    m_tree.InOrder();
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