/***************************************************************************************************************** 
 *  File Name   		: deletionavltree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture12\deletionavltree.h
 *  Created on			: Dec 31, 2013 :: 5:43:52 PM
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

#ifndef DELETIONAVLTREE_H_
#define DELETIONAVLTREE_H_

struct tAvlNode{
	int value;
	unsigned int height;
	tAvlNode *left;
	tAvlNode *right;
	tAvlNode *parent;
};

void rotateNodes(tAvlNode *parentNode,tAvlNode *childNode){

}

void balanceAvlTreePostDeletion(tAvlNode *ptr){
	tAvlNode *grandParent = ptr;
	unsigned int leftHeight,rightHeight;
	while(grandParent != NULL){
		leftHeight = 0;
		rightHeight = 0;
		if(grandParent->left != NULL){
			leftHeight = grandParent->left->height;
		}
		if(grandParent->right != NULL){
			rightHeight = grandParent->right->height;
		}
		if(abs(leftHeight - rightHeight) > 0){
			tAvlNode *parentNode,*childNode;
			parentNode = grandParent->left->height > grandParent->right->height?grandParent->left:grandParent->right;
			if(parentNode->left->height != parentNode->right->height){
				childNode = parentNode->left->height > parentNode->right->height?parentNode->left:parentNode->right;
			}else{
				if(parentNode->parent->left == parentNode){
					childNode = parentNode->left;
				}else{
					childNode = parentNode->right;
				}
			}
			if((grandParent->left  == parentNode && parentNode->left == childNode)||(grandParent->right == parentNode && parentNode->right == childNode)){
				rotateNodes(grandParent,parentNode);

			}else{
				rotateNodes(parentNode,childNode);
				rotateNodes(childNode,grandParent);
			}
		}else{
			grandParent->height -= 1;
		}
		grandParent = grandParent->parent;
	}
}

tAvlNode *searchForNode(tAvlNode *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	tAvlNode *crawler = ptr;
	while(crawler != NULL){
		if(crawler->value == userInput){
			return crawler;
		}
		if(crawler->value > userInput){
			crawler = crawler->left;
		}else{
			crawler = crawler->right;
		}
	}
	return NULL;
}

void deleteFromAvltree(tAvlNode **ptr,int userInput){
	tAvlNode *ptrToKey = searchForNode(*ptr,userInput);
	if(ptrToKey != NULL){
		tAvlNode *nodeToBeDeleted;
		if(ptrToKey->left == NULL || ptrToKey->right == NULL){
			if(ptrToKey->left == NULL && ptrToKey->right == NULL){
				nodeToBeDeleted = ptrToKey;
				ptrToKey = ptrToKey->parent;
				if(ptrToKey->parent->left == ptrToKey){
					ptrToKey->left = NULL;
				}else{
					ptrToKey->right = NULL;
				}
				free(nodeToBeDeleted);
				balanceAvlTreePostDeletion(ptrToKey);
			}
			if(ptrToKey->left != NULL){
				ptrToKey->value = ptrToKey->left->value;
				nodeToBeDeleted = ptrToKey->left;
				ptrToKey->left = NULL;
				free(nodeToBeDeleted);
				balanceAvlTreePostDeletion(ptrToKey);
			}else{
				ptrToKey->value = ptrToKey->right->value;
				nodeToBeDeleted = ptrToKey->right;
				ptrToKey->right = NULL;
				free(nodeToBeDeleted);
				balanceAvlTreePostDeletion(ptrToKey);
			}
		}else{
			tAvlNode *predecessorNode = ptrToKey->left;
			while(predecessorNode->right != NULL){
				predecessorNode = predecessorNode->right;
			}
			ptrToKey->value = predecessorNode->value;
			nodeToBeDeleted = predecessorNode;
			predecessorNode->parent = predecessorNode->left;
			predecessorNode = predecessorNode->left;
			free(nodeToBeDeleted);
			balanceAvlTreePostDeletion(predecessorNode);
		}
	}
}

#endif /* DELETIONAVLTREE_H_ */

/************************************************* End code *******************************************************/
