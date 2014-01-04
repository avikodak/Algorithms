/***************************************************************************************************************** 
 *  File Name   		: insertionavltree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture12\insertionavltree.h
 *  Created on			: Dec 31, 2013 :: 5:43:41 PM
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

struct tAvlNode{
	int value;
	unsigned int height;
	tAvlNode *left;
	tAvlNode *right;
	tAvlNode *parent;
};

#ifndef INSERTIONAVLTREE_H_
#define INSERTIONAVLTREE_H_

tAvlNode *createAvlNode(int userInput){
	tAvlNode *newNode = (tAvlNode *)malloc(sizeof(tAvlNode));
	newNode->value = userInput;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->height = 1;
	return newNode;
}

tAvlNode *getInsertionPositionAvltree(tAvlNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}else{
		if(ptr->value == value){
			return NULL;
		}
		if(ptr->left > value){
			if(ptr->left == NULL){
				return ptr->left;
			}else{
				return getInsertionPositionAvltree(ptr->left,value);
			}
		}else{
			if(ptr->right == NULL){
				return ptr->right;
			}else{
				return getInsertionPositionAvltree(ptr->right,value);
			}
		}
	}
}

void rotateNodes(tAvlNode *parentNode,tAvlNode *childNode){
	tAvlNode *temp;
	tAvlNode *grandParent;
	grandParent = parentNode->parent;
	bool isParentLeftChild;
	if(grandParent->left == parentNode){
		isParentLeftChild = true;
	}else{
		isParentLeftChild = false;
	}
	if(parentNode->left == childNode){
		temp = childNode->right;
		childNode->right = parentNode;
		parentNode->parent = childNode;
		parentNode->left = temp;
		childNode->parent = grandParent;
		temp->parent = parentNode;
		if(isParentLeftChild){
			grandParent->left = childNode;
		}else{
			grandParent->right = childNode;
		}
	}else{
		if(parentNode->right == childNode){
			temp = childNode->left;
			childNode->left = parentNode;
			parentNode->parent = childNode;
			parentNode->right = temp;
			childNode->parent = grandParent;
			temp->parent = parentNode;
			if(isParentLeftChild){
				grandParent->left = childNode;
			}else{
				grandParent->right = childNode;
			}
		}
	}
}

void balanceAvltreePostinsertion(tAvlNode *node){
	tAvlNode *grandParentNode = node;
	node->height = 0;
	unsigned int leftHeight,rightHeight;
	while(grandParentNode != NULL){
		leftHeight = 0;
		rightHeight = 0;
		if(grandParentNode->left != NULL){
			leftHeight = grandParentNode->left->height;
		}
		if(grandParentNode->right != NULL){
			rightHeight = grandParentNode->right->height;
		}
		grandParentNode->height += 1;
		if(abs(leftHeight - rightHeight) > 1){
			tAvlNode *parentNode,*childNode;
			if(node->value < grandParentNode->value){
				parentNode = grandParentNode->left;
			}else{
				parentNode = grandParentNode->right;
			}
			if(parentNode->value > node->value){
				childNode = parentNode->left;
			}else{
				childNode = parentNode->right;
			}
			if((grandParentNode->left == parentNode && parentNode->left == childNode) || (grandParentNode->right == parentNode && parentNode->right == childNode)){
				rotateNodes(grandParentNode,parentNode);
				parentNode->height = grandParentNode->height - 1;
				grandParentNode->height = childNode->height;
			}else{
				rotateNodes(parentNode,childNode);
				rotateNodes(childNode,grandParentNode);
				childNode->height += 1;
				parentNode->height -= 1;
				grandParentNode->height = parentNode->height;
			}
			break;
		}
		grandParentNode = grandParentNode->parent;
	}
}

void insertIntoAVLTree(tAvlNode **ptr,int value){
	if((*ptr) == NULL){
		(*ptr) = createAvlNode(value);
	}else{
		tAvlNode *parentPtr = getInsertionPositionAvltree(*ptr,value);
		tAvlNode *newNode = createAvlNode(value);
		newNode->parent = parentPtr;
		if(value < parentPtr->value){
			parentPtr->left = newNode;
		}else{
			parentPtr->right = newNode;
		}
		balanceAvltreePostinsertion(newNode);
	}
}

#endif /* INSERTIONAVLTREE_H_ */

/************************************************* End code *******************************************************/
