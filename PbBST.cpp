/** * Title: Binary Search Trees * Author: Firat Yildiz * ID: 21502717 * Section: 01 * Assignment: 2 * Description: BST */ 

#include "PbBST.h"
#include "PbBSTNode.h"
#include <stdio.h>
#include <math.h>
#include <queue>
#include <iostream>

using namespace std;

PbBST::PbBST(){
    root = NULL;
    numberOfNodes = 0;
    numberOfFullBT = 0;
}

PbBST::PbBST(const int& tree){
    root = new PbBSTNode(tree, NULL, NULL);
    numberOfNodes = 1;
    numberOfFullBT = 0;
}

void PbBST::insertKey(int &key){
    numberOfNodes++;
    searchTreeInsert(root, key);
}


void PbBST::searchTreeInsert(PbBSTNode*& treePtr, int& key){
    if(treePtr == NULL)
        treePtr = new PbBSTNode(key, NULL, NULL);
    else if(key < treePtr->item)
        searchTreeInsert(treePtr->leftChildPtr, key);
    else
        searchTreeInsert(treePtr->rightChildPtr, key);
}

void PbBST::deleteKey(int key){
    numberOfNodes--;
    searchTreeDeleted(root, key);
}

void PbBST::searchTreeDeleted(PbBSTNode*& treePtr, int key){
    if(treePtr == NULL)
        cout<<"There is no element in the tree\n";
    else if(key == treePtr->item)
        deleteItem(treePtr);
    else if(key < treePtr->item)
        searchTreeDeleted(treePtr->leftChildPtr, key);
    else
        searchTreeDeleted(treePtr->rightChildPtr, key);
}

void PbBST::deleteItem(PbBSTNode *&nodePtr){
    PbBSTNode *delPtr;
    int replacementItem;
    
    if ((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)) {
        delete nodePtr;
        nodePtr = NULL;
    }
    else if(nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else if(nodePtr->rightChildPtr==NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    else{
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void PbBST::processLeftmost(PbBSTNode *& nodePtr, int & treeItem){
    if(nodePtr-> leftChildPtr == NULL){
        treeItem = nodePtr->item;
        PbBSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr,treeItem);
}

int PbBST::getHeight(){
    return getHeightHelper(root);
}

int PbBST::getHeightHelper(PbBSTNode *subTreePtr){
    
    if(subTreePtr == NULL)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->leftChildPtr),getHeightHelper(subTreePtr->rightChildPtr));
}

int PbBST::findNodesRequired(){
    return pow( 2, this->getHeight()) - 1 - numberOfNodes;
}

int PbBST::getNodeCount(){
    return numberOfNodes;
}

int PbBST::findFullBTLevel(){

    int level = 0;
    
    if (root == NULL)
        return numberOfFullBT;
    
    queue<PbBSTNode *> ourQue;
    ourQue.push(root);
    
    while (ourQue.empty() == false)
    {
        int levelNode = ourQue.size();
        if(levelNode == pow(2,level)){
            level ++;
            numberOfFullBT++;
        }
        else
            return numberOfFullBT;
        
        while (levelNode > 0)
        {
            PbBSTNode *node = ourQue.front();
            ourQue.pop();
            if (node->leftChildPtr != NULL)
                ourQue.push(node->leftChildPtr);
            if (node->rightChildPtr != NULL)
                ourQue.push(node->rightChildPtr);
            levelNode--;
        }
    }
    return numberOfFullBT;
}

void PbBST:: mirrorTree(){
    mirrorTreeHelper(root);
}

void PbBST::mirrorTreeHelper(PbBSTNode *rootStart){
    if((rootStart->leftChildPtr != NULL) && (rootStart->leftChildPtr != NULL)){
        PbBSTNode* temp = rootStart->leftChildPtr;
        rootStart->leftChildPtr = rootStart->rightChildPtr;
        rootStart->rightChildPtr = temp;
        mirrorTreeHelper(rootStart->rightChildPtr);
        mirrorTreeHelper(rootStart->leftChildPtr);
    }
}







