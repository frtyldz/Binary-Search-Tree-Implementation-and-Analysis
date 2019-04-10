//
//  main.cpp
//  CS202HW3
//
//  Created by Fırat Yıldız on 11/24/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "PbBST.h"
#include "analysis.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    AVLTree* tr = new AVLTree();
    //analysis a;
    tr->insert(5);
    tr->insert(10);
    tr->insert(15);
    tr->insert(60);
    tr->insert(8);
    tr->insert(40);
    tr->insert(2);
    tr->insert(30);
    tr->insert(17);
    tr->insert(12);
    tr->insert(74);
    //tr->printTree();
    cout<< tr->findMaxInBinaryTree(tr->root);
    /*cout<<endl;
    cout<<endl;
    cout<<endl;
    tr->deleteKey(30);
    tr->deleteKey(10);
    tr->deleteKey(8);
    tr->deleteKey(74);
    tr->deleteKey(5);
    tr->printTree();
    cout<<endl;
    cout<<endl;
    cout<<endl;*/
    //a.heightAnalysis();
    return 0;
}


