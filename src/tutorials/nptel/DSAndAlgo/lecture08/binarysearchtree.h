/***************************************************************************************************************** 
 *  File Name   		: binarysearchtree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture08\binarysearchtree.h
 *  Created on			: Dec 30, 2013 :: 7:02:06 PM
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

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

bool doesNodeExists(tNode *ptr,int key){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == key){
		return true;
	}
	if(ptr->value > key){
		return doesNodeExists(ptr->left,key);
	}else{
		return doesNodeExists(ptr->right,key);
	}
}

tNode *getNodeBST(tNode *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value == key){
		return ptr;
	}
	if(ptr->value > key){
		return getNodeBST(ptr->left,key);
	}else{
		return getNodeBST(ptr->right,key);
	}
}

tNode *getNodeBSTIterative(tNode *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}
	tNode *currentNode = ptr;
	while(currentNode != NULL){
		if(currentNode->value == key){
			return currentNode;
		}
		currentNode = currentNode->value > key?currentNode->left:currentNode->right;
	}
	return NULL;
}

int getMinvalBST(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	return ptr->left == NULL?ptr->value:getMinvalBST(ptr->left);
}

int getMinvalueBSTIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	tNode *currentNode = ptr;
	while(currentNode->left != NULL){
		currentNode = currentNode->left;
	}
	return currentNode->value;
}

int getMaxvalBST(tNode *ptr){
	if(ptr == NULL){
		return INT_MAX;
	}
	return ptr->right == NULL?ptr->value:getMaxvalBST(ptr->right);
}

int getMaxvalueBSTIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MAX;
	}
	tNode *currentNode = ptr;
	while(currentNode->right != NULL){
		currentNode = currentNode->right;
	}
	return currentNode->value;
}

tNode *getSuccessorIterative(tNode *ptrToKey,tNode *ptr){
	if(ptrToKey == NULL){
		return NULL;
	}
	tNode *currentNode;
	if(ptrToKey->right != NULL){
		currentNode = ptrToKey->right;
		while(currentNode->right != NULL){
			currentNode =  currentNode->right;
		}
		return currentNode;
	}else{
		currentNode = ptr;
		tNode *successor = NULL;
		while(currentNode != ptrToKey){
			if(currentNode->value > ptrToKey->value){
				successor = currentNode;
				currentNode = currentNode->left;
			}else{
				currentNode = currentNode->right;
			}
		}
		return successor;
	}
}

tNode *getSucccessor(tNode *ptr){

}

tNode *getPredecessorIterative(tNode *ptrToKey,tNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	tNode *currentNode;
	if(ptrToKey->left != NULL){
		currentNode = ptrToKey->left;
	}else{
		currentNode = ptr;
		tNode *predecessor = NULL;
		while(currentNode != ptrToKey){
			if(currentNode->value > ptrToKey->value){
				currentNode = currentNode->left;
			}else{
				predecessor = currentNode;
				currentNode = currentNode->right;
			}
		}
		return predecessor;
	}
}

tNode *getPredecessor(tNode *ptr){

}



#endif /* BINARYSEARCHTREE_H_ */
/************************************************* End code *******************************************************/
