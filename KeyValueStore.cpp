#include "KeyValueStore.h"

// constructor
KeyValueStore::KeyValueStore() {
    
}

// destructor
KeyValueStore::~KeyValueStore() {

}

// put
void KeyValueStore::Put(std::string key, std::string value) {

}

// get 
std::optional<std::string> KeyValueStore::Get(std::string key) {

}

// remove
void KeyValueStore::Remove(std::string key) {

}

// range query
std::vector<std::pair<std::string, std::string>> KeyValueStore::RangeQuery(std::string low, std::string high) {

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