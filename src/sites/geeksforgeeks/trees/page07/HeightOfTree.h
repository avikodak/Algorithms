/***************************************************************************************************************** 
 *  File Name   		: HeightOfTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\HeightOfTree.h
 *  Created on			: Dec 13, 2013 :: 1:39:24 AM
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

#ifndef HEIGHTOFTREE_H_
#define HEIGHTOFTREE_H_

unsigned int heightOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1 + max(heightOfTree(ptr->left),heightOfTree(ptr->right));
}

void maxIndexOfTreePreOrder(tNode *ptr,unsigned int currentIndex,unsigned int &maxIndex){
	if(ptr == NULL){
		return;
	}
	if(maxIndex < currentIndex){
		maxIndex = currentIndex;
	}
	maxIndexOfTreePreOrder(ptr->left,2*currentIndex,maxIndex);
	maxIndexOfTreePreOrder(ptr->right,2*currentIndex+1,maxIndex);
}

unsigned int heightOfTreePreOrderDriver(tNode *ptr){
	unsigned int maxIndex = 1;
	unsigned int currentIndex = 1;
	maxIndexOfTreePreOrder(ptr,currentIndex,maxIndex);
	return (unsigned int)log2(maxIndex);
}

void maxIndexOfTreeInOrder(tNode *ptr,unsigned int currentIndex,unsigned int &maxIndex){
	if(ptr == NULL){
		return;
	}
	maxIndexOfTreeInOrder(ptr->left,2*currentIndex,maxIndex);
	if(maxIndex < currentIndex){
		maxIndex = currentIndex;
	}
	maxIndexOfTreeInOrder(ptr->right,2*currentIndex+1,maxIndex);
}

unsigned int heightOfTreeInOrderDriver(tNode *ptr){
	unsigned int maxIndex = 1;
	unsigned int currentIndex = 1;
	maxIndexOfTreeInOrder(ptr,currentIndex,maxIndex);
	return (unsigned int)log2(maxIndex);
}

void maxIndexOfTreePostOrder(tNode *ptr,unsigned int currentIndex,unsigned int &maxIndex){
	if(ptr == NULL){
		return;
	}
	maxIndexOfTreePostOrder(ptr->left,2*currentIndex,maxIndex);
	maxIndexOfTreePostOrder(ptr->right,2*currentIndex+1,maxIndex);
	if(maxIndex < currentIndex){
		maxIndex = currentIndex;
	}
}

unsigned int heightOfTreePostOrderDriver(tNode *ptr){
	unsigned int maxIndex = 1;
	unsigned int currentIndex = 1;
	maxIndexOfTreePostOrder(ptr,currentIndex,maxIndex);
	return (unsigned int)log2(maxIndex);
}

unsigned int heightPreOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int maxIndex =0;
	stack<tNode *> auxSpace;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	auxSpace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	tNode *currentNode;
	unsigned int currentNodeIndex;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		currentNodeIndex = nodeIndexMap.find((uint32_t)(currentNode));
		if(maxIndex < currentNodeIndex){
			maxIndex = currentNodeIndex;
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*currentNodeIndex+1));
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*currentNodeIndex));
		}
	}
	return (unsigned int)log2(maxIndex);
}

unsigned int heightPostOrderIterativeTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int maxIndex = 0;
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	tNode *currentNode;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	primaryAuxSpace.push(ptr);
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		secondaryAuxSpace.push(currentNode);
		if(currentNode->left == NULL && currentNode->right == NULL){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,1));
		}else{
			if(currentNode->left != NULL){
				primaryAuxSpace.push(currentNode->left);
			}
			if(currentNode->right != NULL){
				primaryAuxSpace.push(currentNode->right);
			}
		}
	}
	unsigned int height = 0;
	unsigned int leftHeight = 0;
	unsigned int rightHeight = 0;
	while(!secondaryAuxSpace.empty()){
		currentNode = secondaryAuxSpace.top();
		if(nodeIndexMap.find((uint32_t)currentNode) == nodeIndexMap.end()){
			leftHeight = 0,rightHeight=0;
			if(currentNode->left != NULL){
				leftHeight = nodeIndexMap.find((uint32_t)currentNode->left)->second;
			}
			if(currentNode->right != NULL){
				rightHeight = nodeIndexMap.find((uint32_t)currentNode->right)->second;
			}
			if(height < max(leftHeight,rightHeight)){
				height = max(leftHeight,rightHeight);
			}
			nodeIndexMap.insert((uint32_t)currentNode,max(leftHeight,rightHeight));
		}
	}
	return height;
}

unsigned int heightPostOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int height = 0,leftHeight,rightHeight;
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

		}
	}
}

unsigned int heightInOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int height = 0;

}

unsigned int heightPreOrderMorrisIterative(tNode *ptr){

}

unsigned int heightInOrderMorrisIterative(tNode *ptr){

}

unsigned int heightLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	queue<tNode *> currentLevel,nextLevel;
	unsigned int height = 1;
	tNode *currentNode;
	while(!currentLevel.empty() && !nextLevel.empty()){
		if(currentLevel.empty()){
			currentNode = currentLevel.front();
			currentLevel.pop();
			if(currentNode->left != NULL){
				currentLevel.push(currentNode->left);
			}
			if(currentNode->right != NULL){
				currentLevel.push(currentNode->right);
			}
		}else{
			height++;
			while(!nextLevel.empty()){
				currentLevel.push(nextLevel.front());
				nextLevel.pop();
			}
		}
	}
	return height;
}
#endif /* HEIGHTOFTREE_H_ */
/************************************************* End code *******************************************************/
