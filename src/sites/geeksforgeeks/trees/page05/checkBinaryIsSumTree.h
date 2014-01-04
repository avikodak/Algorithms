/***************************************************************************************************************** 
 *  File Name   		: checkBinaryIsSumTree..h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\checkBinaryIsSumTree..h
 *  Created on			: Jan 4, 2014 :: 12:43:12 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 *****************************************************************************************************************/

/************************************************ Namespaces ****************************************************/
using namespace std;
using namespace __gnu_cxx;

/************************************************ User Includes *************************************************/
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <programming/ds/tree.h>
#include <programming/ds/linkedlist.h>
#include <programming/utils/treeutils.h>
#include <programming/utils/llutils.h>

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef CHECKBINARYISSUMTREE_H_
#define CHECKBINARYISSUMTREE_H_

int sumOfNodes(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return ptr->value + sumOfNodes(ptr->left) + sumOfNodes(ptr->right);
}

bool isBinaryTreeSumTree(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	int sumOfNodesLeftSubtree = sumOfNodes(ptr->left);
	int sumOfNodesRightSubtree = sumOfNodes(ptr->right);
	if(ptr->value != sumOfNodesLeftSubtree + sumOfNodesRightSubtree){
		return false;
	}
	return isBinaryTreeSumTree(ptr->left) && isBinaryTreeSumTree(ptr->right);
}

int isBinaryTreeSumTreeBottomUp(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return ptr->value;
	}
	int leftSum = isBinaryTreeSumTreeBottomUp(ptr->left);
	if(leftSum == INT_MAX){
		return INT_MAX;
	}
	int rightSum = isBinaryTreeSumTreeBottomUp(ptr->right);
	if(rightSum == INT_MAX){
		return INT_MAX;
	}
	if(leftSum + rightSum == ptr->value){
		return 2 * ptr->value;
	}else{
		return INT_MAX;
	}
}

#endif /* CHECKBINARYISSUMTREE_H_ */

/************************************************* End code *******************************************************/
