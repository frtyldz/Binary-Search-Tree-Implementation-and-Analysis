//
//  AVLTreeNode.hpp
//  CS202HW3
//
//  Created by Fırat Yıldız on 11/24/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#ifndef AVLTreeNode_h
#define AVLTreeNode_h

#include <stdio.h>
#include "PbBSTNode.h"

class AVLTreeNode : public PbBSTNode{
public:
    AVLTreeNode();
    AVLTreeNode(int key, AVLTreeNode* rightN, AVLTreeNode* leftN);
protected:
    int height = 0;
};

#endif /* AVLTreeNode_h */
