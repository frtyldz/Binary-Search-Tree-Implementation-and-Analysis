/** * Title: Binary Search Trees * Author: Firat Yildiz * ID: 21502717 * Section: 01 * Assignment: 2 * Description: BST */

#include "PbBSTNode.h"
#include <stdio.h>
#include <iostream>

using namespace std;
    
PbBSTNode ::PbBSTNode(const int& nodeItem, PbBSTNode *left, PbBSTNode *right){
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}
