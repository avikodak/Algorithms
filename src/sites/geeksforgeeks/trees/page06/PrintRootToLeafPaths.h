/***************************************************************************************************************** 
 *  File Name   		: PrintRootToLeafPaths.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\PrintRootToLeafPaths.h
 *  Created on			: Dec 23, 2013 :: 9:37:30 PM
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

#ifndef PRINTROOTTOLEAFPATHS_H_
#define PRINTROOTTOLEAFPATHS_H_

void printRootToLeafPaths(tNode *ptr,queue<tNode *> topToBottomNodes){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		while(!topToBottomNodes.empty()){
			printf("%d\t",topToBottomNodes.front()->value);
		}
		printf("\n");
		return;
	}
	topToBottomNodes.push(ptr);
	printRootToLeafPaths(ptr->left,topToBottomNodes);
	printRootToLeafPaths(ptr->right,topToBottomNodes);
}

void printRootToLeafPathsHashmap(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tHashmap *hashmapFormTree = getHashmapFormOfTree(ptr);
	hash_map<unsigned int,tNode *> indexNodeMap = hashmapFormTree->indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap,temp;
	tNode *currentNode;
	unsigned int currentNodeIndex;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNode = itToIndexNodeMap->second;
		if(currentNode->left == NULL && currentNode->right == NULL){
			currentNodeIndex = itToIndexNodeMap->first;
			stack<int> auxSpace;
			auxSpace.push(currentNode->value);
			currentNodeIndex /= 2;
			while(currentNodeIndex > 0){
				auxSpace.push(indexNodeMap.find(currentNodeIndex)->second->value);
				currentNodeIndex /= 2;
			}
			while(!auxSpace.empty()){
				printf("%d\t",auxSpace.top());
				auxSpace.pop();
			}
		}
	}
}

void printRootToLeafPathsWithParentPtr(tPNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		stack<tPNode *> auxSpace;
		tPNode *currentNode = ptr;
		while(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->parent;
		}
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.top()->value);
			auxSpace.pop();
		}
		printf("\n");
		return;
	}
	printRootToLeafPathsWithParentPtr(ptr->left);
	printRootToLeafPathsWithParentPtr(ptr->right);
}

void printNodeToParent(tPNode *ptr){
	if(ptr == NULL){
		return;
	}
	tPNode *currentNode = ptr;
	while(currentNode != NULL){
		printf("%d\t",currentNode->value);
		currentNode = currentNode->parent;
	}
	printf("\n");
}

void printRootToLeafPathsWithParentPtrIterative(tPNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tPNode *> auxSpace;
	tPNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			printNodeToParent(currentNode);
		}else{
			if(currentNode->right == NULL){
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left == NULL){
				auxSpace.push(currentNode->left);
			}
		}
	}
}

#endif /* PRINTROOTTOLEAFPATHS_H_ */

/************************************************* End code *******************************************************/
