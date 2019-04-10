//
//  AVLTree.cpp
//  CS202HW3/Users/firatyildiz/Desktop/CS202/CS202HW3/CS202HW3/CS202HW3/PbBSTNode.cpp
//
//  Created by Fırat Yıldız on 11/24/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
///Users/firatyildiz/Desktop/CS202/CS202HW3/CS202HW3/CS202HW3/AVLTree.h

#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "PbBST.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

AVLTree::AVLTree(){
    root = NULL;
}

int AVLTree::getBalance(PbBSTNode *tryPtr){
    if(tryPtr == NULL)
        return 0;
    else{
        return getHeightHelper(tryPtr->leftChildPtr) - getHeightHelper(tryPtr->rightChildPtr);
    }
}

PbBSTNode* AVLTree::leftRotate(PbBSTNode*& tryPtr){
    PbBSTNode* temp = tryPtr;
    PbBSTNode* leftOfChild = tryPtr->rightChildPtr->leftChildPtr;
    tryPtr = tryPtr->rightChildPtr;
    tryPtr->leftChildPtr = temp;
    temp->rightChildPtr = leftOfChild;
    return tryPtr;
}

PbBSTNode* AVLTree::rightRotate(PbBSTNode*& tryPtr){
    PbBSTNode* temp = tryPtr;
    PbBSTNode* rightOfChild = tryPtr->leftChildPtr->rightChildPtr;
    tryPtr = tryPtr->leftChildPtr;
    tryPtr->rightChildPtr = temp;
    temp->leftChildPtr = rightOfChild;
    return tryPtr;
}

void AVLTree::insert(int val){
    insertHelper(val, root);
}

void AVLTree::insertHelper(int &key, PbBSTNode *&node){
    if(node == NULL)
        node = new AVLTreeNode(key, NULL, NULL);
    else if( node->item > key)
        insertHelper(key , node->leftChildPtr);
    else
        insertHelper(key, node->rightChildPtr);

    int balance = getBalance(node);
    if( balance > 1)
    {
        int subBalance = getBalance(node->leftChildPtr) ;
        if( subBalance >= 0){
            rightRotate(node);
        }
        else{
            node->leftChildPtr = leftRotate(node->leftChildPtr);
            rightRotate(node);
        }
    }
    
    else if(balance < -1)
    {
        int subBalance = getBalance(node->rightChildPtr) ;
        if (subBalance > 0){
            node->rightChildPtr = rightRotate(node->rightChildPtr);
            leftRotate(node);
        }
        
        else{
            //cout<<"Left rotation"<<endl;
            leftRotate(node);
        }
    }
}

//deletes a value from the tree
void AVLTree::deleteKey(int val){
    deleteKeyHelper(root, val);
}

void AVLTree::deleteKeyHelper(PbBSTNode *&node, int &key){
    if(node == NULL)
        cout<<"There is no element in the tree\n";
    else if(key == node->item)
        deleteItem(node);
    else if(key < node->item)
        deleteKeyHelper(node->leftChildPtr, key);
    else
        deleteKeyHelper(node->rightChildPtr, key);
    
    
    int balance = getBalance(node);
    
    if( balance > 1)
    {
        int subBalance = getBalance(node->leftChildPtr) ;
        if( subBalance >= 0){
            rightRotate(node);
        }
        else{
            node->leftChildPtr = leftRotate(node->leftChildPtr);
            rightRotate(node);
        }
    }
    
    else if(balance < -1)
    {
        int subBalance = getBalance(node->rightChildPtr) ;
        if (subBalance > 0){
            node->rightChildPtr = rightRotate(node->rightChildPtr);
            leftRotate(node);
        }
        
        else{
            leftRotate(node);
        }
    }
}

void AVLTree::printTree(){
    printTreeHelper(root, 1);
}

void AVLTree::printTreeHelper(PbBSTNode*& node, int level){
    int i;
    if (node != NULL)
    {
        printTreeHelper(node->rightChildPtr, level + 1);
        printf("\n");
        if (node == root)
            cout << "Root -> ";
        for (i = 0; i < level && node != root; i++)
            cout << "        ";
        cout << node->item;
        printTreeHelper(node->leftChildPtr, level + 1);
    }
}
int AVLTree::findMaxInBinaryTree(PbBSTNode* ptr){
    int max1 = -1;
    int result1, result2;
    
    if(ptr != NULL){
        result1 = findMaxInBinaryTree(ptr->leftChildPtr);
        result2 = findMaxInBinaryTree(ptr->rightChildPtr);
        max1 = max(result1, result2,ptr->item);
    }
    return max1;
}
