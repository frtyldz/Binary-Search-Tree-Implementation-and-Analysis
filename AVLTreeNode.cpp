//
//  AVLTreeNode.cpp
//  CS202HW3
//
//  Created by Fırat Yıldız on 11/24/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#include "AVLTreeNode.h"

AVLTreeNode::AVLTreeNode(){
    rightChildPtr = NULL;
    leftChildPtr = NULL;
}
AVLTreeNode::AVLTreeNode(int key, AVLTreeNode* rightN, AVLTreeNode* leftN){
    item = key;
    rightChildPtr = rightN;
    leftChildPtr = leftN;
    height = 1;
}
