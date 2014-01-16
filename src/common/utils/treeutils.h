/*****************************************************************************************************************
 *  File Name   		: treeutils.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\common\utils\treeutils.h
 *  Created on			: Dec 10, 2013 :: 1:06:45 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 *****************************************************************************************************************/

/************************************************ Namespaces *****************************************************/

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

/************************************************ User defined constants *******************************************/

#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef TREEUTILS_H_
#define TREEUTILS_H_

/************************************************ Tree Utils *****************************************************/

tNode *createNewNode(int userInput){
	tNode *newNode = (tNode *)malloc(sizeof(tNode));
	newNode->value = userInput;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

tPNode *createNewPNode(int userInput){
	tPNode *newNode = (tPNode *)malloc(sizeof(tPNode));
	newNode->value = userInput;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
}

tNodeAuxVal *createNewAuxNode(int userInput,unsigned int auxValue = 1){
	tNodeAuxVal *newNode = (tNodeAuxVal *)malloc(sizeof(tNodeAuxVal));
	newNode->value = userInput;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->auxValue = auxValue;
}

void createTree(tNode **ptr,vector<int> userInput){
	if(*ptr == NULL){
		printf("Tree is not null");
		return;
	}
	if(*ptr == NULL){
		(*ptr) = createNewNode(userInput[0]);
	}
	queue<tNode *> auxSpace;
	auxSpace.push(*ptr);
	tNode *currentNode;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		currentNode = auxSpace.front();
		if(currentNode->left == NULL){
			currentNode->left = createNewNode(userInput[counter]);
			auxSpace.push(currentNode->left);
		}else{
			currentNode->right = createNewNode(userInput[counter]);
			auxSpace.push(currentNode->right);
			auxSpace.pop();
		}
	}
}

tNode *createTreeRecursive(vector<int> userInput,unsigned int currentIndex){
	if(userInput.size() == 0 || currentIndex >= userInput.size()){
		return NULL;
	}
	tNode *ptr;
	ptr = createNewNode(userInput[currentIndex]);
	ptr->left = createTreeRecursive(userInput,2*currentIndex+1);
	ptr->right = createTreeRecursive(userInput,2*currentIndex+2);
	return ptr;
}

void createTreeRecursiveAuxspace(tNode **ptr,queue<tNode *> &auxSpace,vector<int> userInput,unsigned int currentIndex){
	if(*ptr == NULL){
		(*ptr) = createNewNode(userInput[currentIndex]);
		auxSpace.push(*ptr);
	}else{
		tNode *currentNode = auxSpace.front();
		if(currentNode->left == NULL){
			currentNode->left = createNewNode(userInput[currentIndex]);
			auxSpace.push(currentNode->left);
		}else{
			currentNode->right = createNewNode(userInput[currentIndex]);
			auxSpace.push(currentNode->right);
		}
	}
	createTreeRecursive(ptr,auxSpace,userInput,currentIndex+1);
}

void insertNodeInTree(tNode **ptr,int userInput){
	if(*ptr == NULL){
		*ptr = createNewNode(userInput);
	}else{
		queue<tNode *> auxSpace;
		auxSpace.push(*ptr);
		tNode *currentNode;
		while(true){
			currentNode = auxSpace.front();
			if(currentNode->left != NULL && currentNode->right != NULL){
				auxSpace.pop();
			}else{
				if(currentNode->left == NULL){
					currentNode->left = createNewNode(userInput);
				}else{
					currentNode->right = createNewNode(userInput);
				}
				break;
			}
		}
	}
}

void appendToTree(tNode **ptr,vector<int> userInput){
	unsigned int counter = 0;
	if(*ptr == NULL){
		*ptr = createNewNode(userInput[counter]);
		counter+=1;
	}else{
		queue<tNode *> auxSpace;
		auxSpace.push(*ptr);
		tNode *currentNode;
		for(;counter < userInput.size();counter++){
			while(true){
				currentNode = auxSpace.front();
				if(currentNode->left != NULL && currentNode->right != NULL){
					auxSpace.push(currentNode->left);
					auxSpace.push(currentNode->right);
					auxSpace.pop();
				}else{
					if(currentNode->left == NULL){
						currentNode->left = createNewNode(userInput);
						auxSpace.push(currentNode->left);
					}else{
						currentNode->right = createNewNode(userInput);
						auxSpace.push(currentNode->right);
					}
					break;
				}
			}
		}
	}
}

/****************************************** Tree with parent utils **********************************************/
void createTreeWithParent(tPNode **ptr,vector<int> userInput){
	if(ptr != NULL){
		printf("Tree is not null\n");
		return;
	}
	*ptr = createNewPNode(userInput[0]);
	queue<tPNode *> auxSpace;
	auxSpace.push(*ptr);
	tPNode *currentNode;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		currentNode = auxSpace.front();
		if(currentNode->left == NULL){
			currentNode->left = createNewPNode(userInput[counter]);
			currentNode->left->parent = currentNode;
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right == NULL){
			currentNode->right = createNewPNode(userInput[counter]);
			currentNode->right->parent = currentNode;
			auxSpace.push(currentNode->right);
			auxSpace.pop();
		}
	}
}


void createTreeWithParentRecursive(tNode **ptr,queue<tPNode *> &auxSpace,vector<int> userInput,unsigned int counter){
	if(*ptr == NULL){
		(*ptr) = createNewPNode(userInput[counter]);
		auxSpace.push(*ptr);
		createTreeWithParentRecursive(ptr,auxSpace,userInput,counter+1);
	}else{
		tPNode *currentNode = auxSpace.front();
		if(currentNode->left == NULL){
			currentNode->left = createNewPNode(userInput[counter]);
			currentNode->left->parent = currentNode;
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right == NULL){
			currentNode->right = createNewPNode(userInput[counter]);
			currentNode->right->parent = currentNode;
			auxSpace.push(currentNode->right);
			auxSpace.pop();
		}
	}
}

void insertANodeIntoTreeWithParent(tPNode **ptr,int userInput){
	if(*ptr == NULL){
		(*ptr) = createNewPNode(userInput);
	}else{
		queue<tPNode *> auxSpace;
		tPNode *currentNode;
		auxSpace.push(*ptr);
		tPNode *currentNode;
		while(!auxSpace.empty()){
			currentNode = auxSpace.front();
			if(currentNode->left != NULL){
				auxSpace.push(currentNode->left);
			}else{
				currentNode->left = createNewPNode(userInput);
				currentNode->left->parent = currentNode;
				break;
			}
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}else{
				currentNode->right = createNewPNode(userInput);
				currentNode->right->parent = currentNode;
				break;
			}
		}
	}
}

void appendTreeWithParent(tPNode *ptr,vector<int> userInput){
	unsigned int counter = 0;
	if(*ptr == NULL){
		(*ptr) = createNewPNode(userInput[counter]);
	}
	queue<tPNode *> auxSpace;
	auxSpace.push(*ptr);
	tPNode *currentNode;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		while(true){
			currentNode = auxSpace.front();
			if(currentNode->left != NULL){
				auxSpace.push(currentNode->left);
			}else{
				currentNode->left = createNewPNode(userInput[counter]);
				currentNode->left->parent = currentNode;
				auxSpace.push(currentNode->left);
				break;
			}
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}else{
				currentNode->right = createNewPNode(userInput[counter]);
				currentNode->right->parent = currentNode;
				auxSpace.push(currentNode->right);
				break;
			}
		}
	}
}

/************************************************ BST Utils *****************************************************/

tNode *getParentnodeInsertionBST(tNode *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	tNode *currentNode = ptr;
	while(true){
		if(currentNode->value >= userInput){
			if(currentNode->left == NULL){
				return currentNode;
			}else{
				currentNode = currentNode->left;
			}
		}else{
			if(currentNode->right == NULL){
				return currentNode;
			}else{
				currentNode = currentNode->right;
			}
		}
	}
}

void createBST(tNode **ptr,vector<int> userInput){
	if(*ptr == NULL){
		tNode *newNode = createNewNode(userInput[0]);
		(*ptr) = newNode;
	}
	tNode *traversalNode = *ptr,*parentPtr;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		parentPtr = getParentnodeInsertionBST(*ptr,userInput[counter]);
		if(parentPtr->value > userInput[counter]){
			parentPtr->left = createNewNode(userInput[counter]);
		}else{
			parentPtr->right = createNewNode(userInput[counter]);
		}
	}
}

void createBSTRecursive(tNode **ptr,tNode *currentNode,vector<int> userInput,unsigned int index){
	if(userInput.size() == 0 || index >= userInput.size()){
		return;
	}
	if(*ptr == NULL){
		tNode *newNode = createNewNode(userInput[index]);
		(*ptr) = newNode;
		createTreeRecursive(ptr,ptr,userInput,index+1);
	}else{
		if(userInput[index] > currentNode->value){
			if(currentNode->left == NULL){
				currentNode->left = createNewNode(userInput[index]);
				createBSTRecursive(ptr,*ptr,userInput,index+1);
			}else{
				createBSTRecursive(ptr,currentNode->left,userInput,index);
			}
		}else{
			if(currentNode->right == NULL){
				currentNode->right = createNewNode(userInput[index]);
				createBSTRecursive(ptr,*ptr,userInput,index+1);
			}else{
				createBSTRecursive(ptr,currentNode->right,userInput,index);
			}
		}
	}
}

void createFrequencyBSTForLL(tNodeAuxVal **ptr,tNodeAuxVal *currentNode,llNode *lptr){
	if(lptr == NULL){
		return;
	}
	if((*ptr) == NULL){
		(*ptr) = createNewAuxNode(lptr->value);
		createBST(ptr,*ptr,lptr->next);
	}else{
		if(currentNode->value == lptr->value){
			currentNode->auxValue += 1;
			createBST(ptr,*ptr,lptr->next);
		}else{
			if(currentNode->value > lptr->value){
				if(currentNode->left == NULL){
					currentNode->left = createNewAuxNode(lptr->value);
					createBST(ptr,*ptr,lptr->next);
				}else{
					createBST(ptr,currentNode->left,lptr);
				}
			}else{
				if(currentNode->right == NULL){
					currentNode->right = createNewAuxNode(lptr->value);
					createBST(ptr,*ptr,lptr->next);
				}else{
					createBST(ptr,currentNode->right,lptr);
				}
			}
		}
	}
}

void createFrequencyBST(tNodeAuxVal **ptr,tNodeAuxVal *currentNode,vector<int> userInput,unsigned int counter = 0){
	if(*ptr == NULL){
		(*ptr) = createNewAuxNode(userInput[counter]);
		createFrequencyBST(ptr,*ptr,userInput,counter+1);
	}else{
		if(currentNode->value == userInput[counter]){
			currentNode->auxValue += 1;
			createFrequencyBST(ptr,*ptr,userInput,counter+1);
		}else{
			if(currentNode->value > userInput[counter]){
				if(currentNode->left == NULL){
					currentNode->left = createNewAuxNode(userInput[counter]);
					createFrequencyBST(ptr,*ptr,userInput,counter+1);
				}else{
					createFrequencyBST(ptr,currentNode->left,userInput,counter+1);
				}
			}else{
				if(currentNode->right == NULL){
					currentNode->right = createNewAuxNode(userInput[counter]);
					createFrequencyBST(ptr,*ptr,userInput,counter+1);
				}else{
					createFrequencyBST(ptr,currentNode->right,userInput,counter+1);
				}
			}
		}
	}
}
struct tNodeAuxVal{
	int value;
	unsigned int auxValue;
	tNodeAuxVal *left;
	tNodeAuxVal *right;
};

tNodeAuxVal *getParentPtrForInsertionFBST(tNodeAuxVal *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}else{
		if(ptr->value > key){
			if(ptr->left == NULL){
				return ptr;
			}else{
				return getParentPtrForInsertionFBST(ptr->left,key);
			}
		}else{
			if(ptr->right == NULL){
				return ptr;
			}else{
				return getParentPtrForInsertionFBST(ptr->right,key);
			}
		}
	}

}

void createFrequencyBSTIterative(tNodeAuxVal **ptr,vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	tNodeAuxVal *nodeForInsertion;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(ptr == NULL){
			(*ptr) = createNewAuxNode(userInput[counter]);
		}else{
			nodeForInsertion = getParentPtrForInsertionFBST(*ptr,userInput[counter]);
			if(nodeForInsertion->value > userInput[counter]){
				nodeForInsertion->left = createNewAuxNode(userInput[counter]);
			}else{
				nodeForInsertion->right = createNewAuxNode(userInput[counter]);
			}
		}
	}
}

void insertNodeBST(tNode **ptr,int userInput){
	if(*ptr == NULL){
		(*ptr) = createNewNode(userInput);
	}else{
		tNode *traversalPtr = *ptr;
		while(true){
			if(traversalPtr->value > userInput){
				if(traversalPtr->left == NULL){
					traversalPtr->left = createNewNode(userInput);
					break;
				}
				traversalPtr = traversalPtr->left;
			}else{
				if(traversalPtr->right == NULL){
					traversalPtr->right = createNewNode(userInput);
					break;
				}
				traversalPtr = traversalPtr->right;
			}
		}
	}
}

void deleteNodeBST(tNode **ptr,int userInput){

}

bool doesNodeExistsInBST(tNode *ptr,int value){
	if(ptr == NULL){
		return false;
	}
	tNode *traversalPtr = ptr;
	while(traversalPtr != NULL && traversalPtr->value == value){
		traversalPtr = traversalPtr->value > value?traversalPtr->left:traversalPtr->right;
	}
	return traversalPtr == NULL?false:true;
}

bool doesNodeExistsInBSTRecursive(tNode *ptr,int value){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == value){
		return true;
	}
	return ptr->value > value?doesNodeExistsInBST(ptr->left,value):doesNodeExistsInBST(ptr->right,value);
}

tNode *searchForNodeBSTIterative(tNode *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	tNode *traversalPtr = ptr;
	while(traversalPtr != NULL && traversalPtr->value == userInput){
		traversalPtr = traversalPtr->value > userInput?traversalPtr->left:traversalPtr->right;
	}
	return traversalPtr;
}

tNode *searchForNodeBSTRecursive(tNode *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value == userInput){
		return ptr;
	}
	return ptr->value > userInput?searchForNodeBSTRecursive(ptr->left,userInput):searchForNodeBSTRecursive(ptr->right,userInput);
}

tNodeAuxVal *searchForNodeABSTIterative(tNodeAuxVal *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	tNodeAuxVal *currentNode = ptr;
	while(currentNode != NULL){
		if(currentNode->value == userInput){
			return currentNode;
		}
		currentNode = currentNode->value > userInput?currentNode->left:currentNode->right;
	}
	return NULL;
}

tNodeAuxVal * searchForNodeABST(tNodeAuxVal *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value == userInput){
		return ptr;
	}
	return ptr->value >userInput?searchForNodeABST(ptr->left,userInput):searchForNodeABST(ptr->right,userInput);
}
/********************************************** Get Tree Nodes ***************************************************/
tLHashMap *levelOrderNodesTwoQueues(tNode *ptr){
	hash_map<unsigned int,vector<tNode *> > levelNodeMap;
	if(ptr == NULL){
		return levelNodeMap;
	}

}

tLHashMap * levelOrderNodesOneQueue(tNode *ptr){
	hash_map<unsigned int,vector<tNode *> > levelNodeMap;
	if(ptr == NULL){
		return levelNodeMap;
	}
}

void preOrderTreeNodeVector(tNode *ptr,vector<tNode *> &preOrderNodes){
	if(ptr == NULL){
		return;
	}
	preOrderNodes.push_back(ptr);
	preOrderTreeNodeVector(ptr->left,preOrderNodes);
	preOrderTreeNodeVector(ptr->right,preOrderNodes);
}

void inOrderTreeNodeVector(tNode *ptr,vector<tNode *> &inOrderNodes){
	if(ptr == NULL){
		return;
	}
	inOrderTreeNodeVector(ptr->left,inOrderNodes);
	inOrderNodes.push_back(ptr);
	inOrderTreeNodeVector(ptr->right,inOrderNodes);
}

void postOrderTreeNodeVector(tNode *ptr,vector<tNode *> &postOrderNodes){
	if(ptr == NULL){
		return;
	}
	postOrderTreeNodeVector(ptr->left,postOrderNodes);
	postOrderTreeNodeVector(ptr->right,postOrderNodes);
	postOrderNodes.push_back(ptr);
}

vector<tNode *> preOrderNodesIterative(tNode *ptr){
	vector<tNode *> preOrderNodes;
	if(ptr == NULL){
		return preOrderNodes;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		preOrderNodes.push_back(currentNode);
		auxSpace.pop();
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
	}
	return preOrderNodes;
}

vector<tNode *> postOrderNodeTwoStacksIterative(tNode *ptr){
	vector<tNode *> postOrderNodes;
	if(ptr == NULL){
		return postOrderNodes;
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
		postOrderNodes.push_back(secondaryAuxSpace.top());
		secondaryAuxSpace.pop();
	}
	return postOrderNodes;
}

vector<tNode *> postOrderNodeIterativeOneStack(tNode *ptr){
	vector<tNode *> postOrderNodes;
	if(ptr == NULL){
		return postOrderNodes;
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
			if(currentNode == auxSpace.top()){
				tempNode = auxSpace.top();
				auxSpace.pop();
				currentNode = tempNode;
			}else{
				postOrderNodes.push_back(currentNode);
				currentNode = NULL;
			}
		}
	}
	return postOrderNodes;
}

vector<tNode *> inOrderNodesIterative(tNode *ptr){
	vector<tNode *> inOrderNodes;
	if(ptr == NULL){
		return inOrderNodes;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			inOrderNodes.push_back(currentNode);
			currentNode = currentNode->right;
		}
	}
	return inOrderNodes;
}

vector<tNode *> preOrderNodesIterativeMorris(tNode *ptr){
	vector<tNode *> preOrderNodes;
	if(ptr == NULL){
		return preOrderNodes;
	}
	tNode *currentNode = ptr,*tempNode;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right != currentNode){
				tempNode->right = NULL;
				currentNode = currentNode->right;
			}else{
				tempNode->right = currentNode;
				preOrderNodes.push_back(currentNode);
				currentNode = currentNode->left;
			}
		}else{
			preOrderNodes.push_back(currentNode);
			currentNode = currentNode->right;
		}
	}
	return preOrderNodes;
}

vector<tNode *> inOrderNodesIterativeMorris(tNode *ptr){
	vector<tNode *> inOrderNodes;
	if(ptr == NULL){
		return inOrderNodes;
	}
	tNode *currentNode = ptr,*tempNode;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			if(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == currentNode){
				tempNode->right = NULL;
				inOrderNodes.push_back(currentNode);
				currentNode = currentNode->right;
			}else{
				tempNode->right = currentNode;
				currentNode = currentNode->left;
			}
		}else{
			inOrderNodes.push_back(currentNode);
			currentNode = currentNode->right;
		}
	}
	return inOrderNodes;
}

/********************************************** Get Tree Values ***************************************************/
void preOrderTreeValuesVector(tNode *ptr,vector<int> &preOrderValues){
	if(ptr == NULL){
		return;
	}
	preOrderValues.push_back(ptr->value);
	preOrderTreeValuesVector(ptr->left,preOrderValues);
	preOrderTreeValuesVector(ptr->right,preOrderValues);
}

void inOrderTreeValuesVector(tNode *ptr,vector<int> &inOrderValues){
	if(ptr == NULL){
		return;
	}
	inOrderTreeValuesVector(ptr->left,inOrderValues);
	inOrderValues.push_back(ptr->value);
	inOrderTreeValuesVector(ptr->right,inOrderValues);
}

void postOrderTreeValuesVector(tNode *ptr,vector<int> &postOrderValues){
	if(ptr == NULL){
		return;
	}
	postOrderTreeValuesVector(ptr->left,postOrderValues);
	postOrderTreeValuesVector(ptr->right,postOrderValues);
	postOrderValues.push_back(ptr->value);
}

vector<int> preOrderValuesIterative(tNode *ptr){
	vector<int> preOrderValues;
	if(ptr == NULL){
		return preOrderValues;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		preOrderValues.push_back(currentNode->value);
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
	}
	return preOrderValues;
}

vector<int> inOrderValuesIterative(tNode *ptr){
	vector<int> inOrderValues;
	if(ptr == NULL){
		return inOrderValues;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			inOrderValues.push_back(currentNode->value);
			currentNode = currentNode->right;
		}
	}
	return inOrderValues;
}

vector<int> postOrderValuesIterativeTwoStacks(tNode *ptr){
	vector<int> postOrderValues;
	if(ptr == NULL){
		return postOrderValues;
	}
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	tNode *currentNode;
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
		postOrderValues.push_back(secondaryAuxSpace.top()->value);
		secondaryAuxSpace.pop();
	}
}

vector<int> postOrderValuesIterative(tNode *ptr){
	vector<int> postOrderValues;
	if(ptr == NULL){
		return postOrderValues;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*tempNode;
	while(!auxSpace.empty()&&currentNode != NULL){
		if(currentNode != NULL){
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->right == auxSpace.top()){
				tempNode = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = tempNode;
			}else{
				postOrderValues.push_back(currentNode->value);
				currentNode = NULL;
			}
		}
	}
}

vector<int> preOrderValuesMorrisIterative(tNode *ptr){
	vector<int> preOrderValues;
	if(ptr == NULL){
		return preOrderValues;
	}
	tNode *currentNode = ptr,*tempNode;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == currentNode){
				tempNode->right  = NULL;
				currentNode  = currentNode->right;
			}else{
				tempNode->right = currentNode;
				preOrderValues.push_back(currentNode->value);
				currentNode = currentNode->left;
			}
		}else{
			preOrderValues.push_back(currentNode->value);
			currentNode = currentNode->right;
		}
	}
	return preOrderValues;
}

vector<int> inOrderValuesMorrisTraversal(tNode *ptr){
	vector<int> inOrderValues;
	if(ptr == NULL){
		return inOrderValues;
	}
	tNode *currentNode = ptr,*tempNode;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == currentNode){
				inOrderValues.push_back(tempNode->value);
				tempNode->right = NULL;
				currentNode = currentNode->right;
			}else{
				tempNode->right = currentNode;
				currentNode = currentNode->left;
			}
		}else{
			inOrderValues.push_back(currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

/****************************************** Tree as hashmap utils **************************************************/

tHashmap *getHashmapFormOfTree(tNode *ptr,unsigned int startrank = 0){
	if(ptr == NULL){
		return NULL;
	}
	hash_map<unsigned int,tNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	queue<tNode *> auxSpace;
	auxSpace.push(ptr);
	if(startrank == 0){
		indexNodeMap.insert(pair<unsigned int,tNode *>(0,ptr));
		nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,0));
	}else{
		indexNodeMap.insert(pair<unsigned int,tNode *>(1,ptr));
		nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	}
	tNode *currentNode;
	unsigned int currentNodeIndex;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		currentNodeIndex = nodeIndexMap.find((uint32_t)(currentNode));
		if(currentNode->left != NULL){
			if(startrank == 0){
				indexNodeMap.insert(pair<unsigned int,tNode *>(2*currentNodeIndex + 1,ptr));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,2*currentNodeIndex + 1));
			}else{
				indexNodeMap.insert(pair<unsigned int,tNode *>(2*currentNodeIndex,ptr));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,2*currentNodeIndex));
			}
		}
		if(currentNode->right != NULL){
			if(startrank == 0){
				indexNodeMap.insert(pair<unsigned int,tNode *>(2*currentNodeIndex + 2,ptr));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,2*currentNodeIndex + 2));
			}else{
				indexNodeMap.insert(pair<unsigned int,tNode *>(2*currentNodeIndex + 1,ptr));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,2*currentNodeIndex + 1));
			}
		}
	}
}

#endif /* TREEUTILS_H_ */

/************************************************* End code *******************************************************/
