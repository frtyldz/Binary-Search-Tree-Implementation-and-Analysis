/** * Title: Binary Search Trees * Author: Firat Yildiz * ID: 21502717 * Section: 01 * Assignment: 3 * Description: BST */ 

#ifndef PbBST_h
#define PbBST_h

#include <stdio.h>
#include <iostream>
#include "PbBSTNode.h"

class PbBST{
public:
    PbBSTNode *root;
    int numberOfNodes;
    int numberOfFullBT;
    
public:
    PbBST();
    PbBST(const int& tree);
    void insertKey(int& key);
    void searchTreeInsert(PbBSTNode*& treePtr, int& key);
    void deleteKey(int key);
    void searchTreeDeleted(PbBSTNode*& treePtr, int key);
    void deleteItem(PbBSTNode*& nodePtr);
    void processLeftmost(PbBSTNode *& nodePtr, int & treeItem);
    int findNodesRequired();
    int findFullBTLevel();
    void findFullBTLevelHelper(PbBSTNode *TreePtr, int level);
    int getHeightHelper(PbBSTNode *subTreePtr);
    void mirrorTree();
    void mirrorTreeHelper(PbBSTNode* rootStart);
    int getNodeCount();
    int getHeight();
    ~PbBST();
};

#endif /* PbBST_hpp */
