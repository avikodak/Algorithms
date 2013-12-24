/***************************************************************************************************************** 
 *  File Name   		: ConvertTreeIntoMirrorImage.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\ConvertTreeIntoMirrorImage.h
 *  Created on			: Dec 13, 2013 :: 2:09:20 AM
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

#ifndef CONVERTTREEINTOMIRRORIMAGE_H_
#define CONVERTTREEINTOMIRRORIMAGE_H_

void convertTreeIntoMirrorImageTopToBottom(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return;
	}
	tNode *tempNode = ptr->left;
	ptr->left = ptr->right;
	ptr->right = tempNode;
	convertTreeIntoMirrorImageTopToBottom(ptr->left);
	convertTreeIntoMirrorImageTopToBottom(ptr->right);
}

void convertTreeIntoMirrorImageBottomTop(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return;
	}
	convertTreeIntoMirrorImageBottomTop(ptr->left);
	convertTreeIntoMirrorImageBottomTop(ptr->right);
	tNode *tempNode = ptr->left;
	ptr->left = ptr->right;
	ptr->right = tempNode;
}

void convertTreeIntoMirrorImageIterativeLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode,*tempNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			continue;
		}
		tempNode = currentNode->left;
		currentNode->left = currentNode->right;
		currentNode->right = tempNode;
		auxSpace.push(currentNode->left);
		auxSpace.push(currentNode->right);
	}
}

void convertTreeIntoMirrorImagePostOrderTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return;
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
	tNode *tempNode;
	while(!secondaryAuxSpace.empty()){
		currentNode = secondaryAuxSpace.top();
		tempNode = currentNode->left;
		currentNode->left = currentNode->right;
		currentNode->right = tempNode;
	}
}

void convertTreeIntoMirrorImagePostOrderOneStack(tNode *ptr){
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
				tempNode  = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = tempNode;
			}else{
				tempNode = currentNode->left;
				currentNode->left = currentNode->right;
				currentNode->right = tempNode;
				currentNode = NULL;
			}
		}
	}
}

void convertTreeIntoMirrorImageHashMap(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tHashMap *hashMapFormTree = getHashmapFormOfTree(ptr);
	hash_map<unsigned int,tNode *> indexNodeMap = hashMapFormTree->indexNodeMap;
	sort(indexNodeMap.begin(),indexNodeMap.end());
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	tNode *currentNode,*tempNode;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNode = itToIndexNodeMap->second;
		tempNode = currentNode->left;
		currentNode->left = currentNode->right;
		currentNode->right = tempNode;
	}
}

#endif /* CONVERTTREEINTOMIRRORIMAGE_H_ */
/************************************************* End code *******************************************************/
