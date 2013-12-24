/***************************************************************************************************************** 
 *  File Name   		: IsTreeHeightBalanced.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\IsTreeHeightBalanced.h
 *  Created on			: Dec 23, 2013 :: 12:03:50 PM
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

#ifndef ISTREEHEIGHTBALANCED_H_
#define ISTREEHEIGHTBALANCED_H_

bool isTreeHeightBalancedTopToBottom(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	unsigned int leftHeight = heightOfTree(ptr->left);
	unsigned int rightHeight = heightOfTree(ptr->right);
	return abs(leftHeight-rightHeight) <= 1 && isTreeHeightBalancedTopToBottom(ptr->left) && isTreeHeightBalancedTopToBottom(ptr->right);
}

unsigned int isTreeHeightBalanceBottomUp(tNode *ptr,bool &isTreeHeightBalanced){
	if(ptr == NULL){
		return 0;
	}
	unsigned int leftHeight,rightHeight;
	if((leftHeight = isTreeHeightBalanceBottomUp(ptr->left)) == INT_MAX){
		return INT_MAX;
	}
	if((rightHeight = isTreeHeightBalanceBottomUp(ptr->right)) ==  INT_MAX){
		return INT_MAX;
	}
	if(abs(leftHeight - rightHeight) >= 1){
		isTreeHeightBalanced = false;
		return leftHeight + rightHeight + 1;
	}else{
		return INT_MAX;
	}
}

bool isTreeHeightBalancedBottomUpV2(tNode *ptr,int *height){
	if(ptr == NULL){
		return true;
	}
	int leftHeight,rightHeight;
	if(!isTreeHeightBalancedBottomUpV2(ptr->left,&leftHeight)){
		return false;
	}
	if(!isTreeHeightBalancedBottomUpV2(ptr->right,&rightHeight)){
		return false;
	}
	*height = max(leftHeight,rightHeight) + 1;
	return abs(leftHeight-rightHeight) <= 1?true:false;
}

struct tNodeAuxVal{
	int value;
	unsigned int auxValue;
	tNodeAuxVal *left;
	tNodeAuxVal *right;
};

unsigned int fillHeightsForNodes(tNodeAuxVal *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int leftHeight = fillHeightsForNodes(ptr->left);
	unsigned int rightHeight = fillHeightsForNodes(ptr->right);
	ptr->auxValue = max(leftHeight,rightHeight) + 1;
	return ptr->auxValue;
}

bool checkHeightBalancedAuxTree(tNodeAuxVal *ptr){
	if(ptr == NULL){
		return true;
	}
	if(abs(ptr->left->auxValue,ptr->right->auxValue) > 1){
		return false;
	}
	return checkHeightBalancedAuxTree(ptr->left) && checkHeightBalancedAuxTree(ptr->right);
}

bool isTreeHeightBalanceAuxTree(tNodeAuxVal *ptr){
	if(ptr == NULL){
		return true;
	}
	fillHeightsForNodes(ptr);
	return checkHeightBalancedAuxTree(ptr);
}
#endif /* ISTREEHEIGHTBALANCED_H_ */

/************************************************* End code *******************************************************/
