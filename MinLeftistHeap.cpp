//
//  Author: Taylor Bauer
//  Date:   11.3.2019
//          EECS 560
//          Lab 08
//

#include <iostream>
#include "MinLeftistHeap.h"
using namespace std;

MinLeftistHeap::MinLeftistHeap() {
    root = nullptr;
}

// MinLeftistHeap::~MinLeftistHeap() {
//     while (root != nullptr) {
//         deleteMin();
//     }
// }

Node* MinLeftistHeap::merge(Node* H1, Node* H2) {
    if (H1 == nullptr) {
        return H2;
    }
    else if (H2 == nullptr) {
        return H1;
    }
    else if (H1->key > H2->key) {       // swap so the lesser is "on the left"
        Node* temp = H2;
        H2 = H1;
        H1 = temp;
    }

    H1->rightChild = merge(H1->rightChild, H2);     // this is where the "merging" happens

    if (H1->rightChild == nullptr) {
        // Do not rotate
    }
    else if (H1->leftChild == nullptr && H1->rightChild != nullptr) {
        Node* temp = H1->rightChild;
        H1->rightChild = H1->leftChild;
        H1->leftChild = temp;
    }
    else if (H1->leftChild->getRank() < H1->rightChild->getRank()) {         // this is what differentiates the leftist heap from a skew heap
         Node* temp = H1->rightChild;
         H1->rightChild = H1->leftChild;
         H1->leftChild = temp;
    }

    return H1;
}

Node* MinLeftistHeap::insert(int value) {
    Node* newNode = new Node(value);
    root = merge(root, newNode);
    return root;
}

Node* MinLeftistHeap::deleteMin() {
    if (root == nullptr) {
        return nullptr;
    }
    
    Node* left = root->leftChild;
    Node* right = root->rightChild;
    delete root;
    return merge(left, right);
}

void MinLeftistHeap::levelOrder() {
    int height = getHeight(root);
    for (int i = 0; i < height; i++) {
        levelOrder(root, i);
    }
}

void MinLeftistHeap::levelOrder(Node* node, int level) {
    if (node == nullptr) {
        return;
    }
    else if (level == 0) {
            cout << node->key << ' ';
    }
    else {
        levelOrder(node->leftChild, level - 1);
        levelOrder(node->rightChild, level - 1);
    }
}

int MinLeftistHeap::getHeight(Node* node) {
    int height = 0;
    while (node != nullptr) {
        height ++;
        if (getHeight(node->leftChild) > getHeight(node->rightChild)){
            node = node->leftChild;
        }
        else {
            node = node->rightChild;
        }
    }
    return height;
}

Node* MinLeftistHeap::getRoot() {
    return root;
}

void MinLeftistHeap::preOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->key << ' ';
    preOrder(node->leftChild);
    preOrder(node->rightChild);
    return;
}

void MinLeftistHeap::inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->leftChild);
    cout << node->key << ' ';
    inOrder(node->rightChild);
    return;
}

void MinLeftistHeap::postOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->leftChild);
    postOrder(node->rightChild);
    cout << node->key << ' ';
    return;
}