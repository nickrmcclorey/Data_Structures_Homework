#pragma once
#include "Node.h"
using namespace std;

template <class T>
class BinaryTree {
    private:
        Node<T>* root;
        void RotateLeft(Node<T>* parent, Node<T>* child);
        void RotateRight(Node<T>* parent, Node<T>* child);
        Node<T>* RemoveRoot();
        int levels(Node<T>* parent);
        void Balance(Node<T> *node);
    public:
        Node<T>* findParent(T val);
        BinaryTree();
        ~BinaryTree();
        void Insert(T itemToAdd);
        T* Find(T val);
        int Size();
        Node<T>* Remove(T val);
        Node<T>* LeastGreater(Node<T> *ptr);
        bool IsBalanced();
        Node<T>* GetAllAscending();
        Node<T>* GetAllDescending();
        void EmptyTree();
};

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    EmptyTree();
}

template <class T>
void BinaryTree<T>::EmptyTree() {
    if (root != nullptr) {
        delete root;
    }
}

template <class T>
int BinaryTree<T>::Size() {
    if (root == nullptr) {
        return 0;
    }
    return root->Size();
}

template <class T>
void BinaryTree<T>::Insert(T val) {
    if (root == nullptr) {
        root = new Node<T>(val);
    } else {
        root->Insert(val);
    }
    Balance(root);
}

template <class T>
void BinaryTree<T>::RotateLeft(Node<T>* parent, Node<T>* child) {
    if (child == root) {
        if (child->right->right != nullptr) {
            root = child->right;
            child->right = root->left;
            root->left = child;
        } else {
            root = child->right->left;
            parent = child->right;
            child->right = root->left;
            root->left = child;
            parent->left = root->right;
            root->right = parent;
        }
    } else if (parent->right == child) {
        parent->right = child->right;
        child->right = child->right->left;
        parent->right->left = child;
    } else {
        parent->left = child->right;
        child->right = child->right->left;
        parent->left->left = child;
    }
}

template <class T>
void BinaryTree<T>::RotateRight(Node<T>* parent, Node<T>* child) {
    if (child == root) {
        if (child->left->left != nullptr) {
            root = child->left;
            child->left = root->right;
            root->right = child;
        } else {
            root = child->left->right;
            parent = child->left;
            child->left = root->right;
            root->right = child;
            parent->right = root->left;
            root->left = parent;
        }
    } else if (parent->left == child) {
        parent->left = child->left;
        child->left = child->left->right;
        parent->left->right = child;
    } else {
        parent->right = child->left;
        child->left = child->left->right;
        parent->right->right = child;
    }
}


template <class T>
Node<T>* BinaryTree<T>::RemoveRoot() {
    Node<T>* formerRoot = root;
    if (root->numChildren() < 2) {
        if (root->left != nullptr) {
            root = root->left;
        } else {
            root = root->right;
        }
    } else {
        Node<T>* replace = LeastGreater(root);
        replace = Remove(replace->data);

        replace->left = root->left;
        replace->right = root->right;
        root = replace;
    }

    Balance(root);
    return formerRoot;
}

template <class T>
Node<T>* BinaryTree<T>::Remove(T val){
    //not root
    //not empty tree
    Node<T> *parent = findParent(val);
    if (parent == nullptr) {
        return nullptr;
    }
    Node<T>* temp;
    // if the node to remove doesn't have two children
    if((parent->left != nullptr && parent->left->data == val && parent->left->numChildren() < 2) || (parent->right != nullptr && parent->right->data == val && parent->right->numChildren() < 2)){
        
        if(parent->left != nullptr && parent->left->data == val){
            // node to remove is parent->left
            temp = parent->left;
            // parent points to the removed node's child
            if (temp->left != nullptr) {
                parent->left = temp->left;
            } else {
                parent->left = temp->right;
            }
        }
        else{ // node to remove is parent->right
            temp = parent->right;
            // parent points to the removed node's child
            if (temp->left != nullptr) {
                parent->right = temp->left;
            } else {
                parent->right = temp->right;
            }
        }
    }
    else {
        Node<T> *replace = nullptr;
        if (parent->left != nullptr && parent->left->data == val) {
            replace = LeastGreater(parent->left);
            replace = Remove(replace->data);
            temp = parent->left;

            // modify pointers to insert replacment in place of removed element
            replace->left = temp->left;
            replace->right = temp->right;
            parent->left = replace;

        } else {
            replace = LeastGreater(parent->left);
            replace = Remove(replace->data);
            temp = parent->right;
            
            // modify pointers to insert replacment in place of removed element
            replace->left = temp->left;
            replace->right = temp->right;
            parent->right = replace;
        }
    }
    Balance(root);
    return temp;            
}

template <class T>
Node<T>* BinaryTree<T>::LeastGreater(Node<T> *ptr){
    Node<T> *temp = ptr->right;
    if (temp == nullptr) {
        return nullptr;
    }
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

template <class T>
Node<T>* BinaryTree<T>::GetAllAscending() {
    int size = this->Size();
    if (size == 0) {
        return nullptr;
    }
    Node<T>* array = new Node<T>[size];
    int index = 0;
    root->AddToArray(array, index, true);
    return array;
}


template <class T>
Node<T>* BinaryTree<T>::GetAllDescending() {
    int size = this->Size();
    if (size == 0) {
        return nullptr;
    }
    Node<T>* array = new Node<T>[size];
    int index = size - 1;
    root->AddToArray(array, index, false);
    return array;
}

template <class T>
T* BinaryTree<T>::Find(T val) {
    Node<T>* temp = root;
    while (temp != nullptr && temp->data != val) {
        if (temp->data > val) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    if (temp == nullptr) {
        return nullptr;
    }
    return &temp->data;
}

template<class T>
int BinaryTree<T>::levels(Node<T>* parent) {
    if (parent == nullptr) {
        return 0;
    }
    int leftLevels = 1 + levels(parent->left);
    int rightLevels = 1 + levels(parent->right);

    return max(rightLevels, leftLevels);
}

template <class T>
Node<T>* BinaryTree<T>::findParent(T childValue) {
    if (root == nullptr) {
        return nullptr;
    }

    Node<T>* current = root;
    while ((current->left != nullptr && current->left->data != childValue) &&
           (current->right != nullptr && current->right->data != childValue)) {
        if (current->data > childValue) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current->left != nullptr && current->left->data == childValue) {
        return current;
    } else if (current->right != nullptr && current->right->data == childValue) {
        return current;
    } else {
        return nullptr;
    }
}

template <class T>
void BinaryTree<T>::Balance(Node<T> *node) {
    if (node == nullptr) {
        return;
    }
    Balance(node->left);
    Balance(node->right);

    int rightLevels = levels(node->right);
    int leftLevels = levels(node->left);

    if (rightLevels >= leftLevels + 2) {
        RotateLeft(findParent(node->data), node);
    } else if (leftLevels >= rightLevels + 2) {
        RotateRight(findParent(node->data), node);
    }
}

template <class T>
bool BinaryTree<T>::IsBalanced() {
    if (root == nullptr) {
        return true;
    }
    int rightLevels = levels(root->right);
    int leftLevels = levels(root->left);

    return (leftLevels <= rightLevels + 1 && rightLevels <= leftLevels + 1);
}
