//
// Created by Prashant Bhandari on 3/27/17.
// Binary Search tree implementation .
//

#ifndef BST_TREE_H
#define BST_TREE_H

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Tree {
public:
    Tree();
    ~Tree();
    void insert(int);
    bool search(int);
    void destroyTree();
    void findMin();
    void deleteNode(int);

private:
    Node* root;
    Node* insert(Node*, int);
    bool search(Node*, int);
    Node* destroyTree(Node*);
    Node* findMinimum(Node*);
    Node* deleteNode(Node*, int);
};


#endif //BST_TREE_H
