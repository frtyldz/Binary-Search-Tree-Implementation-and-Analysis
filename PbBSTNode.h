/** * Title: Binary Search Trees * Author: Firat Yildiz * ID: 21502717 * Section: 01 * Assignment: 2 * Description: BST */ 

#ifndef PbBSTNode_h
#define PbBSTNode_h
#include <stdio.h>

class PbBSTNode{
public:
    PbBSTNode(){};
    PbBSTNode(const int& nodeItem, PbBSTNode *left = NULL, PbBSTNode *right = NULL);
    
public:
    int item;
    PbBSTNode *leftChildPtr;
    PbBSTNode *rightChildPtr;
    
    friend class PbBST;
};
#endif /* PbBSTNode_h */
