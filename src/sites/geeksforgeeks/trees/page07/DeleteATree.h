/***************************************************************************************************************** 
 *  File Name   		: DeleteATree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\DeleteATree.h
 *  Created on			: Dec 13, 2013 :: 2:05:02 AM
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

#ifndef DELETEATREE_H_
#define DELETEATREE_H_

void deleteTreePostOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return;
	}
	deleteTreePostOrder(ptr->left);
	deleteTreePostOrder(ptr->right);
	tNode *tempSubTree;
	tempSubTree = ptr->left;
	ptr->left = NULL;
	free(tempSubTree);
	tempSubTree = ptr->right;
	ptr->right = NULL;
	free(tempSubTree);
}

void deleteTreePostOrderIterativeTwoStacks(tNode **ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	tNode *currentNode,*tempNode;
	primaryAuxSpace.push(*ptr);
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
		currentNode = secondaryAuxSpace.top();
		secondaryAuxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			continue;
		}
		tempNode = currentNode->left;
		currentNode->left = NULL;
		free(tempNode);
		tempNode = currentNode->right;
		currentNode->right = NULL;
		free(tempNode);
	}
	tempNode = *ptr;
	(*ptr) = NULL;
	free(tempNode);
}

void deleteTreePostOrderIterative(tNode **ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = *ptr,*tempNode;
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
				auxSpace.push(currentNode);
				auxSpace.pop();
				currentNode = tempNode;
			}else{
				if(currentNode->left != NULL && currentNode->right != NULL){
					tempNode = currentNode->left;
					currentNode->left = NULL;
					free(tempNode);
					tempNode = currentNode->right;
					currentNode->right = NULL;
					free(tempNode);
				}
				currentNode = NULL;
			}
		}
	}
	tempNode = (*ptr);
	(*ptr) = NULL;
	free(tempNode);
}

void deleteTreeHashMap(tNode **ptr){
	if(ptr == NULL){
		return;
	}
	tHashmap *hashmapTree = getHashmapFormOfTree(ptr);
	hash_map<unsigned int,tNode *> nodeIndexMap = hashmapTree->indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToNodeIndexMap;
	sort(nodeIndexMap.begin(),nodeIndexMap.end());
	tNode *currentNode,*tempNode;
	for(itToNodeIndexMap = nodeIndexMap.end() - 1;itToNodeIndexMap != nodeIndexMap.begin();itToNodeIndexMap--){
		currentNode = itToNodeIndexMap->second;
		if(currentNode->left != NULL || currentNode->right != NULL){
			if(currentNode->left != NULL){
				tempNode = currentNode->left;
				currentNode->left = NULL;
				free(currentNode);
			}
			if(currentNode->right != NULL){
				tempNode = currentNode->right;
				currentNode->right = NULL;
				free(currentNode);
			}
		}
	}
}

void deleteTreeLevelHashMap(tNode *ptr){
	if(ptr == NULL){
		return;
	}

}

#endif /* DELETEATREE_H_ */
/************************************************* End code *******************************************************/


