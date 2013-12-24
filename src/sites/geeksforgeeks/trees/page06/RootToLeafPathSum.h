/***************************************************************************************************************** 
 *  File Name   		: RootToLeafPathSum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\RootToLeafPathSum.h
 *  Created on			: Dec 23, 2013 :: 1:09:52 PM
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

#ifndef ROOTTOLEAFPATHSUM_H_
#define ROOTTOLEAFPATHSUM_H_

bool doesSumRootToLeafExists(tNode *ptr,unsigned int counter){
	if(ptr == NULL){
		return targetSum == 0?true:false;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return ptr->value - counter == 0?true:false;
	}
	if(counter <= 0){
		return false;
	}
	return doesSumRootToLeafExists(ptr->left,counter-ptr->value) || doesSumRootToLeafExists(ptr->right,counter - ptr->value);
}

bool doesSumRootToLeafExistsV2(tNode *ptr,int runningSum,int targetSum){
	if(ptr == NULL){
		return targetSum == 0?true:false;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return ptr->value + runningSum == targetSum?true:false;
	}
	return doesSumRootToLeafExistsV2(ptr->left,runningSum+ptr->value,targetSum) || doesSumRootToLeafExistsV2(ptr->right,runningSum+ptr->value,targetSum);
}

bool doesSumRootToLeafExistsHashmap(tNode *ptr,int targetSum){
	if(ptr == NULL){
		return targetSum == 0?true:false;
	}
	tHashmap *hashmapOfTree = getHashmapFormOfTree(ptr,1);
	hash_map<unsigned int,tNode *> indexNodeMap = hashmapOfTree->indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	unsigned int currentIndex;
	int sum;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentIndex = itToIndexNodeMap->first;
		if(indexNodeMap.find(2*currentIndex) == indexNodeMap.end() && indexNodeMap.find(2*currentIndex + 1) == indexNodeMap.end()){
			sum = indexNodeMap.find(0)->second->value;
			while(currentIndex > 0){
				sum += indexNodeMap.find(currentIndex)->second->value;
				currentIndex /= 2;
			}
			if(sum == targetSum){
				return true;
			}
		}
	}
	return false;
}

bool doesSumRootToLeafExistsParentPtr(tPNode *ptr,int targetSum){
	if(ptr == NULL){
		return targetSum == 0?true:false;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		int sum = 0;
		tPNode *currentNode = ptr;
		while(currentNode != NULL){
			sum += currentNode->value;
			currentNode = currentNode->parent;
		}
		return sum == targetSum?true:false;
	}
	return doesSumRootToLeafExistsParentPtr(ptr->left,targetSum) || doesSumRootToLeafExistsParentPtr(ptr->right,targetSum);
}

bool doesSumRootToLeafExistsPreOrderIterative(tPNode *ptr,int targetSum){
	if(ptr == NULL){
		return NULL;
	}
	stack<tPNode *> auxSpace;
	hash_map<uint32_t,int> nodeSumMap;
	hash_map<uint32_t,int>::iterator itToNodeSumMap;
	tPNode *currentNode;
	int currentSum;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		if(currentNode->parent == NULL){
			nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode,currentNode->value));
		}else{
			currentSum = nodeSumMap.find((uint32_t)currentNode->parent);
			nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode,currentSum + currentNode->value));
		}
		auxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			if(currentSum + currentNode->value == targetSum){
				return true;
			}
		}else{
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left != NULL){
				auxSpace.push(currentNode->left);
			}
		}
	}
	return false;
}
#endif /* ROOTTOLEAFPATHSUM_H_ */

/************************************************* End code *******************************************************/
