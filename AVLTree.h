//
//  AVLTree.hpp
//  CS202HW3
//
//  Created by Fırat Yıldız on 11/24/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include <stdio.h>
#include <iostream>
#include "PbBST.h"
#include "AVLTreeNode.h"

class AVLTree : public PbBST{    
public:
    AVLTree();
    void insert(int val); //inserts a value into the key
    void insertHelper(int& key, PbBSTNode*& node);
    void deleteKey(int val); //deletes a value from the tree
    void deleteKeyHelper(PbBSTNode*& node, int& key);
    void printTree(); //prints the tree
    void printTreeHelper(PbBSTNode*& node, int level);
    int getBalance(PbBSTNode *tryPtr);
    PbBSTNode* leftRotate(PbBSTNode *&tryPtr);
    PbBSTNode* rightRotate(PbBSTNode *&tryPtr);
    int findMaxInBinaryTree(PbBSTNode * ptr);
};
#endif /* AVLTree_h */
