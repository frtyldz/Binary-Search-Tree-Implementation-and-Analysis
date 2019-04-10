//
//  analysis.cpp
//  CS202HW3
//
//  Created by Fırat Yıldız on 11/25/18.
//  Copyright © 2018 Fırat Yıldız. All rights reserved.
//

#include "analysis.h"
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "PbBST.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

void analysis::heightAnalysis(){
    int size = 4000;
    int lSize = 80000;
    cout<<"Part b - Height analysis of AVL trees"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"Array Size         Random           Ascending            Descending"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    AVLTree* trial = new AVLTree();
    AVLTree* trial1 = new AVLTree();
    AVLTree* trial2 = new AVLTree();
    for(int i = size; i <= lSize; i = i + 4000){
        
        //Random number array
        for(int j = i - 4000; j < i; j++){
            trial->insert(i * rand());
        }
        cout<< i <<"                "<<trial->getHeight();
        
        //Ascending order array
        for(int j = i - 4000; j < i; j++){
            trial1->insert(j);
        }
        cout<< "                   "<<trial1->getHeight();
        
        //Descending order array
        int limit = i - 4000;
        for(int j = i; j > limit; j--){
            trial2->insert(j);
        }
        cout<<"               "<<trial2->getHeight()<<endl;
    }
}
