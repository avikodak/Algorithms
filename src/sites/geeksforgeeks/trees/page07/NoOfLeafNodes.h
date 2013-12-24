/***************************************************************************************************************** 
 *  File Name   		: NoOfLeafNodes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\NoOfLeafNodes.h
 *  Created on			: Dec 13, 2013 :: 2:14:18 AM
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

#ifndef NOOFLEAFNODES_H_
#define NOOFLEAFNODES_H_

unsigned int noOfLeafNodes(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return 1;
	}
	return noOfLeafNodes(ptr->left) + noOfLeafNodes(ptr->right);
}

unsigned int preOrderIterativeLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	currentNode;
	unsigned int leafCount = 0;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		if(currentNode->left == NULL && currentNode->right == NULL){
			leafCount += 1;
			continue;
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
	return leafCount;
}

unsigned int postOrderIterativeTwoStacksLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> firstAuxSpace,secondAuxSpace;
	firstAuxSpace.push(ptr);
	tNode *currentNode;
	while(!firstAuxSpace.empty()){
		currentNode = firstAuxSpace.top();
		firstAuxSpace.pop();
		secondAuxSpace.push(currentNode);
		if(currentNode->left != NULL){
			firstAuxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			firstAuxSpace.push(currentNode->right);
		}
	}
	unsigned int noOfLeaves = 0;
	while(!secondAuxSpace.empty()){
		currentNode = secondAuxSpace.top();
		secondAuxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			noOfLeaves++;
		}
	}
	return noOfLeaves;
}

unsigned int postOrderIterativeLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*tempNode;
	unsigned int noOfLeaves = 0;
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
				auxSpace.push(currentNode);
				currentNode = tempNode;
			}else{
				if(currentNode->left == NULL && currentNode->right == NULL){
					noOfLeaves+=1;
				}
				currentNode = NULL;
			}
		}
	}
	return noOfLeaves;
}

unsigned int inOrderIterativeLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int leafCount = 0;
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->left != NULL && currentNode->right != NULL){
				leafCount += 1;
			}
			currentNode = currentNode->right;
		}
	}
	return leafCount;
}

unsigned int preOrderMorrisTraversalLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tNode *currentNode = ptr,*tempNode;
	unsigned int leafCount = 0;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			tempNode = currentNode->left;
			while(tempNode->right != NULL && tempNode->right !=  currentNode){

			}
			if(tempNode->right == NULL){

			}else{

			}
		}else{
			currentNode = currentNode->right;
		}
	}
	return leafCount;
}

unsigned int inOrderMorrisTraversalLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tNode *currentNode = ptr,*tempNode;
	while(currentNode != NULL){

	}
}

unsigned int hashmapLeafCount(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tHashMap *hashMapTree = getHashmapFormOfTree(ptr,1);
	hash_map<unsigned int,tNode *> indexNodeMap;
	unsigned int leafCount = 0;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	unsigned int currentNodeIndex;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeIndex = itToIndexNodeMap->first;
		if(indexNodeMap.find(2*currentNodeIndex) == indexNodeMap.end() && indexNodeMap.find(2*currentNodeIndex + 1) == indexNodeMap.end()){
			leafCount += 1;
		}
	}
	return leafCount;
}
#endif /* NOOFLEAFNODES_H_ */

/************************************************* End code *******************************************************/
