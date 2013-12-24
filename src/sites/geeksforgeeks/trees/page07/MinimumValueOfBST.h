/***************************************************************************************************************** 
 *  File Name   		: MinimumValueOfBST.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\MinimumValueOfBST.h
 *  Created on			: Dec 17, 2013 :: 7:18:23 PM
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

#ifndef MINIMUMVALUEOFBST_H_
#define MINIMUMVALUEOFBST_H_

int minimumValueBST(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(ptr->left == NULL){
		return ptr->value;
	}
	return minimumValueBST(ptr->left);
}

int minimumValueBSTIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	tNode *currentNode = ptr;
	while(currentNode->left != NULL){
		currentNode = currentNode->left;
	}
	return currentNode->value;
}

/**************************************************Naive Algorithms *****************************************************/
void minimumValueBSTPreOrder(tNode *ptr,int &minValue = INT_MAX){
	if(ptr == NULL){
		return;
	}
	if(minValue > ptr->value){
		minValue = ptr->value;
	}
	minimumValueBSTPreOrder(ptr->left,minValue);
	minimumValueBSTPreOrder(ptr->right,minValue);
}

void minimumValueBSTInOrder(tNode *ptr,int &minValue = INT_MAX){
	if(ptr == NULL){
		return;
	}
	minimumValueBSTInOrder(ptr->left,minValue);
	if(minValue > ptr->value){
		minValue = ptr->value;
	}
	minimumValueBSTInOrder(ptr->right,minValue);
}

void minimumValueBSTPostOrder(tNode *ptr,int &minValue = INT_MAX){
	if(ptr == NULL){
		return;
	}
	minimumValueBSTPostOrder(ptr->left,minValue);
	minimumValueBSTPostOrder(ptr->right,minValue);
	if(minValue > ptr->value){
		minValue = ptr->value;
	}
}

int minimumValueBSTPreOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	auxSpace.push(ptr);
	int minValue = INT_MAX;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(minValue > currentNode->value){
			minValue = currentNode->value;
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
	}
	return minValue;
}

int minimumValueBSTInOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	int minValue = INT_MAX;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value < minValue){
				minValue = currentNode->value;
			}
			currentNode = currentNode->right;
		}
	}
	return minValue;
}

int minimumValueBSTPostOrderTwoStacksIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
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
	int minValue = INT_MAX;
	while(!secondaryAuxSpace.empty()){
		if(minValue > secondaryAuxSpace.top()->value){
			minValue = secondaryAuxSpace.top()->value;
		}
		secondaryAuxSpace.pop();
	}
	return minValue;
}

int minimumValueBSTPostOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode,*tempNode;
	int minValue = INT_MAX;
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
				tempNode = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = tempNode;
			}else{
				if(minValue > currentNode->value){
					minValue = currentNode->value;
				}
				currentNode = NULL;
			}
		}
	}
	return minValue;
}

int minimumValueBSTPreMorrisOrder(tNode *ptr){
	if(ptr == NULL){
		return INT_MAX;
	}
	tNode *currentNode = ptr,*tempNode;
	int minValue = INT_MAX;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == NULL){
				tempNode->right = currentNode;
				if(minValue > currentNode->value){
					minValue = currentNode->value;
				}
				currentNode = currentNode->left;
			}else{
				tempNode->right = NULL;
				currentNode = currentNode->right;
			}
		}else{
			if(minValue > currentNode->value){
				minValue = currentNode->value;
			}
			currentNode = currentNode->right;
		}
	}
	return minValue;
}

int minimumValueBSTInMorrisOrder(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	tNode *currentNode = ptr,*tempNode;
	int minValue = INT_MAX;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == NULL){
				tempNode->right = currentNode;
				currentNode = currentNode->left;
			}else{
				if(minValue > currentNode->value){
					minValue = currentNode->value;
				}
				tempNode->right = NULL;
				currentNode = currentNode->right;
			}
		}else{
			if(minValue > currentNode->value){
				minValue = currentNode->value;
			}
			currentNode = currentNode->right;
		}
	}
	return minValue;
}

int minimumValueBSTLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	queue<tNode *> auxSpace;
	tNode *currentNode;
	auxSpace.push(ptr);
	int minValue = INT_MAX;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		if(minValue > currentNode->value){
			minValue = currentNode->value;
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
	return minValue;
}

int minimumValueBSTHashmap(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	tHashmap *hashmapTree = getHashmapFormOfTree(ptr);
	hash_map<unsigned int,tNode *> indexNodeMap = hashmapTree->indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	int minValue = INT_MAX;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(minValue > itToIndexNodeMap->second->value){
			minValue = itToIndexNodeMap->second->value;
		}
	}
	return minValue;
}
#endif /* MINIMUMVALUEOFBST_H_ */

/************************************************* End code *******************************************************/
