
#include "src/Tree.h"

int main() {
    std::cout << "This is Binary Search Tree." << std::endl;
    Tree testTree1;
    testTree1.insert(15);
    testTree1.insert(10);
    testTree1.insert(20);
    testTree1.deleteNode(10);
    if (testTree1.search(15)) {
        std::cout << "found" << std::endl;
    }
    else {
        std::cout << "Not Found" << std::endl;
    }
//    testTree1.destroyTree();
    testTree1.findMin();
    return 0;
}