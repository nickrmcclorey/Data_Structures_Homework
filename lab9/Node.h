#pragma once
using namespace std;

template <class T>
class Node {
    public:
        T data;
        Node* left;
        Node* right;
        void RotateLeft(Node<T>* parent, Node<T>* child);
        void RotateRight(Node<T>* parent, Node<T>* child);
        Node();
        Node(T val);
        ~Node();
        void Insert(T itemToAdd);
        T* Find(T val);
        int Size();
        T Remove(T val);
        Node<T>* GetAllAscending();
        Node<T>* GetAllDescending();
        void EmptyTree();
        void AddToArray(Node<T> *trees, int &index, bool increase);
        int numChildren();
};

template <class T>
Node<T>::Node() {
    right = nullptr;
    left = nullptr;
}

template <class T>
Node<T>::Node(T val) {
    data = val;
    right = nullptr;
    left = nullptr;
}

template <class T>
void Node<T>::Insert(T itemToAdd) {
    if (itemToAdd > data) {
        if (right == nullptr) {
            right = new Node(itemToAdd);
        } else {
            right->Insert(itemToAdd);
        }
        right->Insert(itemToAdd);
    } else if (itemToAdd < data) {
        if (left == nullptr) {
            left = new Node(itemToAdd);
        } else {
            left->Insert(itemToAdd);
        }
    }
}

template <class T>
T* Node<T>::Find(T val) {
    if (data == val) {
        return &data;
    } else if (data > val) {

        if (left == nullptr) {
            return nullptr;
        }
        return left->Find(val);

    } else {

        if (right == nullptr) {
            return nullptr;
        }
        return right->Find(val);

    }
}

template <class T>
int Node<T>::Size() {
    int sum = 1;
    if (right != nullptr) {
        sum += right->Size();
    }
    if (left != nullptr) {
        sum += left->Size();
    }
    return sum;
}

template <class T>
Node<T>::~Node() {
    this->EmptyTree();
}

template <class T>
void Node<T>::EmptyTree() {
    if (right != nullptr) {
        delete right;
    }
    if (left != nullptr) {
        delete left;
    }
}


template <class T>
void Node<T>::AddToArray(Node<T> *trees, int &index, bool increase) {
    if (left != nullptr) {
        left->AddToArray(trees, index, increase);
    }
    trees[index] = *this;
    if (increase) {
        index++;
    } else {
        index--;
    }
    if (right != nullptr) {
        right->AddToArray(trees, index, increase);
    }
}

template <class T>
Node<T>* Node<T>::GetAllDescending() {
    Node<T> *toReturn = new Node<T>[Size()];
    int index = Size() - 1;
    AddToArray(toReturn, index, false);
    return toReturn;
}

template <class T>
int Node<T>::numChildren() {
    int sum = 0;
    if (left != nullptr) {
        sum++;
    }
    if (right!= nullptr) {
        sum++;
    }
    return sum;
}