//
// Created by Prashant Bhandari on 3/27/17.
//

#include "Tree.h"

//
//
//public:
//
//
Tree::Tree() {
    root = NULL;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::insert(int data) {
    root = insert(root, data);
//        std::cout << root << std::endl;
}

bool Tree::search(int data) {
    return search(root, data);
}

void Tree::destroyTree() {
    root = destroyTree(root);
    std::cout << root;
}

void Tree::findMin() {
    if (findMinimum(root) == NULL) {
        std::cout << "Tree is empty" << std::endl;
    }
    else {
        std::cout << findMinimum(root)->data << " is minimum" << std::endl;
    }

}

void Tree::deleteNode(int data) {
    if (search(data)) {
        root = deleteNode(root, data);
    }
    else {
        std::cout << "Node not in the tree" << std::endl;
    }
}

void Tree::printInOrder() {
    printInOrder(root);
}

void Tree::printPreOrder() {
    printPreOrder(root);
}

void Tree::printPostOrder() {
    printPostOrder(root);
}

//
//
// Private
//
//

Node* Tree::insert(Node* root, int data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }

    else if (root->data < data) {
        root->right = insert(root->right, data);
    }
    return root;
}

bool Tree::search(Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == data){
        return true;
    }
    else if (root->data > data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

Node* Tree::destroyTree(Node* root) {
    if (root != NULL) {
        root->left = destroyTree(root->left);
        root->right = destroyTree(root->right);
        delete root;
    }
    return NULL;
}

Node* Tree::findMinimum(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->left == NULL) {
        return  root;
    }
    return findMinimum(root->left);
}

void Tree::printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    std::cout << root->data << std::endl;
    printInOrder(root->right);
}

void Tree::printPreOrder(Node* root) {
    if (root != NULL) {
        std::cout << root->data << std::endl;
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void  Tree::printPostOrder(Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        std::cout << root->data << std::endl;
    }

}

Node* Tree::deleteNode(Node* root, int data) {
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        }
        else if (root->left == NULL) {
            Node* tempRoot = root;
            root = root->right;
            delete tempRoot;
            tempRoot = NULL;
        }
        else if (root->right == NULL) {
            Node* tempRoot = root;
            root = root->left;
            delete tempRoot;
            tempRoot = NULL;
        }
        else {
            Node* nodeToDelete = findMinimum(root->right);
            root->data = nodeToDelete->data;
            root->right = deleteNode(root->right, nodeToDelete->data);
        }
    }
    return root;
}



