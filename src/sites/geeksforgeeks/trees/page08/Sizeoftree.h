/***************************************************************************************************************** 
 *  File Name   		: Sizeoftree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page08\Sizeoftree.h
 *  Created on			: Dec 10, 2013 :: 1:59:08 PM
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

#ifndef SIZEOFTREE_H_
#define SIZEOFTREE_H_

unsigned int sizeOfTreePreOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1 + sizeOfTreePreOrder(ptr->left) + sizeOfTreePreOrder(ptr->right);
}

unsigned int sizeOfTreeInOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return sizeOfTreeInOrder(ptr->left) + 1 + sizeOfTreeInOrder(ptr->right);
}

unsigned int sizeOfTreePostOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return sizeOfTreePostOrder(ptr->left)+ sizeOfTreePostOrder(ptr->right) + 1;
}

unsigned int sizeOfTreeInOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	queue<tNode *> auxspace;
	tNode *currentNode;
	auxspace.push(ptr);
	unsigned int sizeOfTree;
	while(!auxspace.empty()){
		currentNode = auxspace.front();
		auxspace.pop();
		sizeOfTree += 1;
		if(currentNode->left != NULL){
			auxspace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxspace.push(currentNode->right);
		}
		auxspace.pop();
	}
	return sizeOfTree;
}

unsigned int sizeOfTreeHashMap(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tHashmap *treeHashMap;
	hash_map<unsigned int,unsigned int> nodeIndexMap = treeHashMap->nodeIndexMap;
	return nodeIndexMap.size();
}

unsigned int sizeOfTreePreOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	unsigned int sizeOfTree = 0;
	tNode *currentNode;
	while(!auxSpace.empty()){
		sizeOfTree++;
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
	return sizeOfTree;
}

unsigned int sizeOfTreePostOrderTwoStacksIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	primaryAuxSpace.push(ptr);
	unsigned int sizeOfTree = 0;
	tNode *currentNode;
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		secondaryAuxSpace.push(currentNode);
		if(currentNode->left != NULL){
			primaryAuxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			primaryAuxSpace.push(currentNode->right);
		}
	}
	/**
	 * or simply
	 * sizeOfTree = secondaryAuxSpace.size();
	 */
	while(!secondaryAuxSpace.empty()){
		sizeOfTree++;
		secondaryAuxSpace.pop();
	}
	return sizeOfTree;
}

unsigned int sizeOfTreePostOrderOneStackIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	unsigned int sizeOfTree = 0;
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
				sizeOfTree += 1;
				currentNode = NULL;
			}
		}
	}
	return sizeOfTree;
}

unsigned int sizeOfTreeInOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode = ptr;
	unsigned int sizeOfTree = 0;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			sizeOfTree += 1;
			currentNode = currentNode->right;
		}
	}
	return sizeOfTree;
}

unsigned int sizeOfTreeMorrisPreOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tNode *currentNode = ptr;
	tNode *tempNode;
	unsigned int sizeOfTree = 0;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == currentNode){
				tempNode->right = NULL;
				currentNode = currentNode->right;
			}else{
				sizeOfTree += 1;
				currentNode = currentNode->left;
			}
		}else{
			sizeOfTree += 1;
			currentNode = currentNode->right;
		}
	}
	return sizeOfTree;
}

unsigned int sizeOfTreeThreadedPostOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
}

unsigned int sizeOfTreeMorrisInOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tNode *currentNode = ptr;
	tNode *tempNode;
	unsigned int sizeOfTree = 0;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right != currentNode){
				tempNode = tempNode->right;
			}
			if(tempNode->right == currentNode){
				tempNode->right = NULL;
				sizeOfTree+= 1;
				currentNode = currentNode->right;
			}else{
				currentNode = currentNode->left;
			}
		}else{
			sizeOfTree += 1;
			currentNode = currentNode->right;
		}
	}
	return sizeOfTree;
}

unsigned int sizeOfTreeLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	queue<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode;
	unsigned int sizeOfTree = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		sizeOfTree += 1;
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
	return sizeOfTree;
}

#endif /* SIZEOFTREE_H_ */

/************************************************* End code *******************************************************/
