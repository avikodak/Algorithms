/***************************************************************************************************************** 
 *  File Name   		: DoubleTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\DoubleTree.h
 *  Created on			: Dec 24, 2013 :: 6:41:57 PM
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

#ifndef DOUBLETREE_H_
#define DOUBLETREE_H_

void convertIntoDoubleTree(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	convertIntoDoubleTree(ptr->left);
	convertIntoDoubleTree(ptr->right);
	tNode *newNode = createNewNode(ptr->value);
	newNode->left = ptr->left;
	ptr->left = newNode;
}

void convertIntoDoubleTreePostOrderTwoStacksIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> primaryAuxspace,secondaryAuxspace;
	tNode *currentNode,*newNode;
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		if(currentNode->left != NULL){
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		newNode = createNewNode(currentNode->value);
		newNode->left = currentNode->left;
		currentNode->left = newNode;
	}
}

void convertIntoDoubleTreePostOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode,*temp,*newNode;
	currentNode = ptr;
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
				temp = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = temp;
			}else{
				newNode = createNewNode(currentNode->value);
				newNode->left = currentNode->left;
				currentNode->left = newNode;
				currentNode = NULL;
			}
		}
	}
}

void convertIntoDoubleTreePreorderIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,bool> statusFlags;
	hash_map<uint32_t,bool>::iterator itToStatusFlags;
	stack<tNode *> auxSpace;
	tNode *currentNode,*newNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(statusFlags.find((uint32_t)currentNode) == statusFlags.end()){
			newNode = createNewNode(currentNode->value);
			newNode->left = currentNode->left;
			currentNode->left = newNode;
			statusFlags.insert(pair<uint32_t,bool>((uint32_t)newNode,true));
			statusFlags.insert(pair<uint32_t,bool>((uint32_t)currentNode,true));
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
	}
}

void convertIntoDoubleTreeInOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*newNode;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			newNode = createNewNode(currentNode->value);
			newNode->left = currentNode->left;
			currentNode->left = newNode;
			currentNode = currentNode->right;
		}
	}
}

void convertIntoDoubleTreeInOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	convertIntoDoubleTreeInOrder(ptr->left);
	tNode *newNode = createNewNode(ptr->value);
	newNode->left = ptr->left;
	ptr->left = newNode;
	convertIntoDoubleTreeInOrder(ptr->right);
}

#endif /* DOUBLETREE_H_ */
/************************************************* End code *******************************************************/
