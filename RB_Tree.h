/* 
The RBTree class is templated,
all implementations are written 
in this file 
*/
#ifndef RB_TREE_H
#define RB_TREE_H
#include <iostream>
#include <vector>
#include <string>
#include <utility>

// key, value
template <typename K, typename V>
class RBTree {
public:
    // default constructor, overloaded constructor not needed
    RBTree();

    // destructor
    ~RBTree();

    // delete copy constructor, no implementation needed
    RBTree(const RBTree&) = delete;

    // delete copy assignment operator, no implementation needed
    RBTree<K, V>& operator=(const RBTree&) = delete;

    // insert node
    void Insert(K key, V value);

    // remove node and return
    V Remove(K key);

    // search for node
    V Search(K key);

    // returns a vector of all the stuff in the range
    std::vector<std::pair<K, V>> RangeQuery(K low, K high);

    // return m_size
    int Size();

    // checks if tree is empty
    bool IsEmpty();

    // clear nodes
    void Clear();

private:
    // ===== VARIABLES ===== //
    // RED = 0, BLACK = 1
    enum Color {RED, BLACK}; 

    struct Node {
        K m_key;
        V m_value;
        Color m_color;
        Node* m_left;
        Node* m_right;
        Node* m_parent;

        // default constructor for the sentinel node only
        // m_key and m_value go unused in this case
        Node() {
            m_color = BLACK;
            m_left = nullptr;
            m_right = nullptr;
            m_parent = nullptr;
        }

        // overloaded constructor
        Node(K key, V value, Color color) {
            m_key = key;
            m_value = value;
            m_color = color;
            m_left = nullptr;
            m_right = nullptr;
            m_parent = nullptr;
        }
    };

    int m_size;
    Node* m_root;
    Node* m_nil; // sentinel node

    // ===== PRIVATE HELPER FUNCTIONS ===== //

    // helper function to rotateleft
    void RotateLeft(Node* node) {

    }

    // helper function to rotateright
    void RotateRight(Node* node) {

    }

    // transplant a node
    void Transplant(Node* node1, Node* node2) {

    }

    // find minimum
    Node* FindMin(Node* node) {

    }

    // helper for clear and destructor
    void DestroyTree(Node* node) {

    }

    // insertFix
    void InsertFixup(Node* node) {

    }

    // deleteFix
    void DeleteFixup(Node* node) {

    }

};

// ===== implementations ===== //

// default constructor
template <typename K, typename V>
RBTree<K, V>::RBTree() {
    m_nil = new Node();
    m_root = m_nil;
    m_size = 0;
}

// destructor
template <typename K, typename V>
RBTree<K, V>::~RBTree() {
    Clear();
}

// insert
template <typename K, typename V>
void RBTree<K, V>::Insert(K key, V value) {

}

// remove
template <typename K, typename V>
V RBTree<K, V>::Remove(K key) {

}

// search
template <typename K, typename V>
V RBTree<K, V>::Search(K key) {

}

// rangequery
template <typename K, typename V>
std::vector<std::pair<K, V>> RBTree<K, V>::RangeQuery(K low, K high) {

}

// return size
template <typename K, typename V>
int RBTree<K, V>::Size() {
    return m_size;
}

// check if empty
template <typename K, typename V>
bool RBTree<K, V>::IsEmpty() {
    if(m_root == m_nil) {
        return false;
    } else {
        return true;
    }
}

#endif