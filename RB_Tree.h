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

    // checks if the tree is inorder
    void InOrder();

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
        Node(K key, V value) {
            m_key = key;
            m_value = value;
            m_color = RED; // new nodes are red by default
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
        Node* child = node->m_right;
        node->m_right = child->m_left;

        if(child->m_left != m_nil) {
            child->m_left->m_parent = node;
        }

        child->m_parent = node->m_parent; 

        if(node->m_parent == m_nil) {
            m_root = child;
        } else if (node == node->m_parent->m_left) {
            node->m_parent->m_left = child;
        } else {
            node->m_parent->m_right = child;
        }

        child->m_left = node;
        node->m_parent = child;
    }

    // helper function to rotateright
    void RotateRight(Node* node) {
        Node* child = node->m_left;
        node->m_left = child->m_right;

        if(child->m_right != m_nil) {
            child->m_right->m_parent = node;
        }

        child->m_parent = node->m_parent;

        if(node->m_parent == m_nil) {
            m_root = child;
        } else if (node == node->m_parent->m_right) {
            node->m_parent->m_right = child;
        } else {
            node->m_parent->m_left = child;
        }

        child->m_right = node;
        node->m_parent = child;
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

    // insertFix - fixes red black inheritance with uncles and grandparents
    void InsertFixup(Node* node) {
        while(node->m_parent->m_color == RED) {
            Node* grandparent = node->m_parent->m_parent;
            Node* uncle;
            if(grandparent->m_left == node->m_parent) {
                uncle = grandparent->m_right;
            } else {
                uncle = grandparent->m_left;
            }  

            // left case
            if (node->m_parent == grandparent->m_left) {
                if(uncle->m_color == RED) {
                    node->m_parent->m_color = BLACK;
                    uncle->m_color = BLACK;
                    grandparent->m_color = RED;
                    node = grandparent;
                } else if (node == node->m_parent->m_right && node->m_parent == grandparent->m_left) {
                    node = node->m_parent;
                    RotateLeft(node);
                } else {
                    node->m_parent->m_color = BLACK;
                    grandparent->m_color = RED;
                    RotateRight(grandparent);
                }
            } else { // right case
                if (uncle->m_color == RED) {
                    node->m_parent->m_color = BLACK;
                    uncle->m_color = BLACK;
                    grandparent->m_color = RED;
                    node = grandparent;
                } else if (node == node->m_parent->m_left && node->m_parent == grandparent->m_right) {
                    node = node->m_parent;
                    RotateRight(node);
                } else {
                    node->m_parent->m_color = BLACK;
                    grandparent->m_color = RED;
                    RotateLeft(grandparent);
                }
            }
        }
        m_root->m_color = BLACK;
    }

    // deleteFix
    void DeleteFixup(Node* node) {

    }

    // overloaded inorder, recursive
    void InOrder(Node* node) {
        if(node == m_nil) {
            return;
        }
        InOrder(node->m_left);
        std::cout << node->m_key << ": " << node->m_value << std::endl;
        InOrder(node->m_right);

    }
};

// ===== implementations ===== //

// default constructor
template <typename K, typename V>
RBTree<K, V>::RBTree() {
    m_nil = new Node(); // this node will be black
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
    Node* newNode = new Node(key, value);
    Node* parent = m_nil; // one step behind the curr
    Node* curr = m_root;
    
    // search for m_nil
    while(curr != m_nil) {
        parent = curr;
        if(key < curr->m_key) {
            curr = curr->m_left;
        } else {
            curr = curr->m_right;
        }
    }
    newNode->m_parent = parent;

    // fixup the pointers
    if(parent == m_nil) { // empty case
        m_root = newNode;
    } else if(key < parent->m_key) { // set the newnode as the left of the parent
        parent->m_left = newNode;
    } else { // set to the right
        parent->m_right = newNode;
    }

    newNode->m_left = m_nil;
    newNode->m_right = m_nil;
    m_size++;
    InsertFixup(newNode);
}

// remove
template <typename K, typename V>
V RBTree<K, V>::Remove(K key) {

}

// search
template <typename K, typename V>
V RBTree<K, V>::Search(K key) {
    Node* curr = m_root;
    while(curr != m_nil) {
        if(curr->m_key == key){
            return curr->m_value;
        }
        
        if(key < curr->m_key) {
            curr = curr->m_left;
        } else {
            curr = curr->m_right;
        }
    }
    return V{};
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
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V>
void RBTree<K, V>::Clear() {
}

template <typename K, typename V>
void RBTree<K, V>::InOrder() {
    InOrder(m_root); // calls private overloaded inorder
}

#endif