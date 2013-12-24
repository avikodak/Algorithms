/***************************************************************************************************************** 
 *  File Name   		: Treetraversals.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page08\Treetraversals.h
 *  Created on			: Dec 10, 2013 :: 1:57:22 PM
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
#include <programming/utils/treeutils.h>

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef TREETRAVERSALS_H_
#define TREETRAVERSALS_H_

void preOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	printf("%d\t",ptr->value);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}

void postOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	postOrderTraversal(ptr->left);
	postOrderTraversal(ptr->right);
	printf("%d\t",ptr->value);
}

void inOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	inOrderTraversal(ptr->left);
	printf("%d\t",ptr->value);
	inOrderTraversal(ptr->right);
}

void preOrderTraversalIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
}

void postOrderTraversalIterativeTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	tNode *currentNode;
	primaryAuxSpace.push(ptr);
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpace.push(currentNode);
		if(currentNode->left != NULL){
			primaryAuxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			primaryAuxSpace.push(currentNode->right);
		}
	}
	while(!secondaryAuxSpace.empty()){
		printf("%d\t",secondaryAuxSpace.top()->value);
		secondaryAuxSpace.pop();
	}
}

void postOrderTraversalIterativeOneStack(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*tempNode;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->right == auxSpace.top()){
				tempNode = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = tempNode;
			}else{
				printf("%d\t",currentNode->value);
				currentNode = NULL;
			}
		}
	}
}

void inOrderTraversalIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	while(!auxSpace.empty()&&currentNode != NULL){
		if(currentNode->left != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

void morrisPreOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNode *currentNode,*tempNode;
	currentNode = ptr;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL || tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right != currentNode){
				tempNode->right = NULL;
				currentNode = currentNode->right;
			}else{
				tempNode->right = currentNode;
				printf("%d\t",currentNode->value);
				currentNode = currentNode->left;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

void threadedPostOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
}

void morrisInOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNode *currentNode = ptr,*tempNode;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == currentNode){
				tempNode->right = NULL;
				printf("%d\t",currentNode->value);
				currentNode = currentNode->right;
			}else{
				tempNode->right =currentNode;
				currentNode = currentNode->left;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}
#endif /* TREETRAVERSALS_H_ */

/************************************************* End code *******************************************************/
