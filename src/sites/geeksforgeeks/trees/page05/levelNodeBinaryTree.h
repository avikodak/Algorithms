/***************************************************************************************************************** 
 *  File Name   		: levelNodeBinaryTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\levelNodeBinaryTree.h
 *  Created on			: Jan 4, 2014 :: 11:24:06 AM
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

#ifndef LEVELNODEBINARYTREE_H_
#define LEVELNODEBINARYTREE_H_

unsigned int getLevelNodeBinaryTreePreorder(tNode *ptr,unsigned int level,int nodeValue){
	if(ptr == NULL){
		return UINT_MAX;
	}
	if(ptr->value == nodeValue){
		return level;
	}
	unsigned int levelLeft = getLevelNodeBinaryTree(ptr->left,level+1,nodeValue);
	if(levelLeft != UINT_MAX){
		return levelLeft;
	}
	return getLevelNodeBinaryTree(ptr->right,level+1,nodeValue);
}

unsigned int getLevelNodeBinaryTreePreorderIterative(tNode *ptr,int nodeValue){
	if(ptr == NULL){
		return UINT_MAX;
	}
	stack<tNode *> auxSpace;
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	tNode *currentNode;
	auxSpace.push(ptr);
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
		if(currentNode->value == nodeValue){
			return itToNodeLevelMap->second;
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
			nodeLevelMap.insert((uint32_t)currentNode->right,itToNodeLevelMap->second + 1);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			nodeLevelMap.insert((uint32_t)currentNode->left,itToNodeLevelMap->second + 1);
		}
	}
	return UINT_MAX;
}

unsigned int getLevelNodeBinaryTreeParentPtr(tPNode *ptr,int nodeValue){
	if(ptr == NULL){
		return UINT_MAX;
	}
	if(ptr->value == nodeValue){
		unsigned int levelCounter = 0;
		while(ptr->parent != NULL){
			levelCounter += 1;
			ptr = ptr->parent;
		}
		return levelCounter;
	}
	unsigned int left;
	if((left = getLevelNodeBinaryTreeParentPtr(ptr->left,nodeValue)) != UINT_MAX){
		return left;
	}
	return getLevelNodeBinaryTreeParentPtr(ptr->right,nodeValue);
}

unsigned int getLevelNodeBinaryTreeLevelOrder(tNode *ptr,int nodeValue){
	if(ptr == NULL){
		return UINT_MAX;
	}
	tNode *currentNode,*lastNodeInLevel = ptr;
	queue<tNode *> auxSpace;
	auxSpace.push(ptr);
	unsigned int levelCounter = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(currentNode->value ==nodeValue){
			return levelCounter;
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			lastNodeInLevel = currentNode->left;
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
			lastNodeInLevel = currentNode->right;
		}
		if(lastNodeInLevel == currentNode){
			levelCounter += 1;
		}
	}
}

unsigned int getLevelNodeBinaryTreeHashmap(tNode *ptr,int nodeValue){
	if(ptr == NULL){
		return 0;
	}

}
#endif /* LEVELNODEBINARYTREE_H_ */

/************************************************* End code *******************************************************/
