/***************************************************************************************************************** 
 *  File Name   		: PrintNodesAtDistanceK.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\PrintNodesAtDistanceK.h
 *  Created on			: Dec 24, 2013 :: 11:24:54 AM
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

#ifndef PRINTNODESATDISTANCEK_H_
#define PRINTNODESATDISTANCEK_H_

void printNodesAtDistanceK(tNode *ptr,unsigned int currentLevel,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	if(currentLevel == targetLevel){
		printf("%d\t",ptr->value);
	}
	printNodesAtDistanceK(ptr->left,currentLevel+1,targetLevel);
	printNodesAtDistanceK(ptr->right,currentLevel+1,targetLevel);
}

void printNodesAtDistanceKLevelOrder(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	queue<tNode *> currentLevel,nextLevel;
	tNode *currentNode;
	unsigned int runningLevelCounter=1;
	currentLevel.push(ptr);
	while(!currentLevel.empty()&&!nextLevel.empty() && runningLevelCounter <= targetLevel){
		if(!currentLevel.empty()){
			while(!currentLevel.empty()){
				currentNode = currentLevel.front();
				currentLevel.pop();
				if(runningLevelCounter == targetLevel){
					printf("%d\t",currentNode->value);
				}
				if(currentNode->left != NULL){
					nextLevel.push(currentNode->left);
				}
				if(currentNode->right != NULL){
					nextLevel.push(currentNode->right);
				}
			}
		}else{
			runningLevelCounter++;
			while(!nextLevel.empty()){
				currentLevel.push(nextLevel.front());
				nextLevel.pop();
			}
		}
	}
}

void printNodesAtDistanceKHashmap(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	tHashmap *hashmapTree = getHashmapFormOfTree(ptr);
	hash_map<unsigned int,tNode *> indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	unsigned int lowerLimit = pow(2,targetLevel),upperLimit = pow(2,targetLevel+1) - 1;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(itToIndexNodeMap->first >= lowerLimit && itToIndexNodeMap->first <= upperLimit){
			printf("%d\t",itToIndexNodeMap->second->value);
		}
	}
}

void printNodesAtDistanceKPreOrderIterative(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	stack<tNode *> auxSpace;
	tNode *currentNode;
	unsigned int currentNodeLevel;
	auxSpace.push(ptr);
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,0));

	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
		currentNodeLevel = itToNodeLevelMap->second;
		if(currentNodeLevel == targetLevel){
			printf("%d\t",currentNode->value);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,currentNodeLevel+1));
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,currentNodeLevel+1));
		}
	}
}

void printNodesAtDistanceKInOrderIterative(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	tNode *currentNode = ptr;
	stack<tNode *> auxSpace;
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty()){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
			if(currentNode->left != NULL){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,itToNodeLevelMap->second + 1));
			}
			if(currentNode->right != NULL){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,itToNodeLevelMap->second + 1));
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
			if(itToNodeLevelMap->second == targetLevel){
				printf("%d\t",currentNode->value);
			}
			currentNode = currentNode->right;
		}
	}
}

void printNodesAtDistanceKPostOrderTwoStacksIterative(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	tNode *currentNode;
	unsigned int currentNodeLevel;
	primaryAuxSpace.push(ptr);
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,0));
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpace.push(currentNode);
		currentNodeLevel = nodeLevelMap.find((uint32_t)currentNode)->second;
		if(currentNode->left != NULL){
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,currentNodeLevel+1));
		}
		if(currentNode->right != NULL){
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,currentNodeLevel+1));
		}
	}
	while(!secondaryAuxSpace.empty()){
		currentNode = secondaryAuxSpace.top();
		secondaryAuxSpace.pop();
		currentNodeLevel = nodeLevelMap.find((uint32_t)currentNode)->second;
		if(currentNodeLevel == targetLevel){
			printf("%d\t",currentNode->value);
		}
	}
}

void printNodesAtDistanceKPostOrderIterative(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*temp;
	unsigned int currentNodeIndex;
	nodeLevelMap.insert(pair<uint32_t,unsigned int>(ptr,0));
	while(!auxSpace.empty()){
		if(currentNode != NULL){
			currentNodeIndex = nodeLevelMap.find((uint32_t)currentNode)->second;
			if(currentNode->right != NULL){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,currentNodeIndex + 1));
			}
			if(currentNode->left != NULL){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,currentNodeIndex + 1));
			}
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
				currentNodeIndex = nodeLevelMap.find((uint32_t)currentNode)->second;
				if(currentNodeIndex == targetLevel){
					printf("%d\t",currentNode->value);
				}
				currentNode = NULL;
			}
		}
	}
}


#endif /* PRINTNODESATDISTANCEK_H_ */

/************************************************* End code *******************************************************/
