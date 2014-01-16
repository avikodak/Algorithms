/***************************************************************************************************************** 
 *  File Name   		: InsertRedBlackTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture15\InsertRedBlackTree.h
 *  Created on			: Jan 9, 2014 :: 9:26:30 PM
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

#ifndef INSERTREDBLACKTREE_H_
#define INSERTREDBLACKTREE_H_

struct tRBNode{
	int value;
	tRBNode *left;
	tRBNode *right;
	tRBNode *parent;
	bool isRedNode;
};

tRBNode *createNewRBNode(int value){
	tRBNode *newNode = (tRBNode *)malloc(sizeof(tRBNode));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->isRedNode = true;
}

tRBNode *getRbNodeForInsertion(tRBNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}else{
		if(ptr->value == value){
			return NULL;
		}else{
			if(ptr->value > value){
				if(ptr->left == NULL){
					return ptr->left;
				}else{
					return getRbNodeForInsertion(ptr->left,value);
				}
			}else{
				if(ptr->right == NULL){
					return ptr->right;
				}else{
					return getRbNodeForInsertion(ptr->right,value);
				}
			}
		}
	}
}

void changeColorsPostInsertion(tRBNode *ptr){
	if(ptr == NULL){
		return;
	}
	ptr->left->isRedNode = false;
	ptr->right->isRedNode = false;
	ptr->isRedNode = true;
}

void rotateNodesRbPostInsertion(tRBNode *parentPtr,tRBNode *childPtr){
	if(ptr == NULL){
		return;
	}
	tRBNode *grandParentNode = parentPtr->parent;
	if(grandParentNode->left == parentPtr){
		grandParentNode->left = childPtr;
		childPtr->parent = grandParentNode;
	}else{
		grandParentNode->right = childPtr;
		childPtr->parent = grandParentNode;
	}
	if(parentPtr->left == childPtr){

	}else{

	}
}

void restoreRbTreeProps(tRBNode *ptr){
	if(ptr == NULL || !ptr->parent->isRedNode){
		return;
	}
	ptr = ptr->parent;
	tRBNode *parentNode = ptr->parent;
	if(parentNode->parent == NULL){
		parentNode->isRedNode = false;
		return;
	}
	bool isLeftChild;
	isLeftChild = parentNode->left == ptr?true:false;
	if(isLeftChild){
		if(parentNode->right->isRedNode){
			changeColorsPostInsertion(parentNode);
			restoreRbTreeProps(parentNode);
		}else{
			rotateNodesRbPostInsertion(parentNode);
		}
	}else{
		if(parentNode->left->isRedNode){
			changeColorsPostInsertion(parentNode);
			restoreRbTreeProps(parentNode);
		}else{
			rotateNodesRbPostInsertion(parentNode);
		}
	}
}

void insertNodeIntoRedBlackTree(tRBNode **ptr,int value){
	if(*ptr == NULL){
		(*ptr) = createNewRBNode(value);
		(*ptr)->isRedNode = false;
	}else{
		tRBNode *parentNode = getRbNodeForInsertion(*ptr,value);
		if(parentNode != NULL){
			if(parentNode->value > value){
				parentNode->left = createNewRBNode(value);
				parentNode->left->parent = parentNode;
				restoreRbTreeProps(parentNode->left);
			}else{
				parentNode->right = createNewRBNode(value);
				parentNode->right->parent = parentNode;
				restoreRbTreeProps(parentNode->right);
			}
		}
	}
}

#endif /* INSERTREDBLACKTREE_H_ */

/************************************************* End code *******************************************************/
