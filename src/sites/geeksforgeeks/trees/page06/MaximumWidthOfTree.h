/***************************************************************************************************************** 
 *  File Name   		: MaximumWidthOfTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\MaximumWidthOfTree.h
 *  Created on			: Dec 24, 2013 :: 12:04:36 AM
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

#ifndef MAXIMUMWIDTHOFTREE_H_
#define MAXIMUMWIDTHOFTREE_H_

void maximumWidthOfTreePreOrder(tNode *ptr,unsigned int level,vector<unsigned int> &nodeCounter){
	if(ptr == NULL){
		return;
	}
	nodeCounter[level] += 1;
	maximumWidthOfTreePreOrder(ptr->left,level+1,nodeCounter);
	maximumWidthOfTreePreOrder(ptr->right,level+1,nodeCounter);
}

unsigned int maximumWidthTreePreOrderDriver(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	vector<unsigned int> frequencyLevelMap;
	maximumWidthOfTreePreOrder(ptr,0,frequencyLevelMap);
	unsigned int maxWidth = 0;
	for(unsigned int counter = 0;counter < frequencyLevelMap.size();counter++){
		if(maxWidth < frequencyLevelMap[counter]){
			maxWidth = frequencyLevelMap[counter];
		}
	}
	return maxWidth;
}

unsigned int maximumWidthTreeLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	vector<unsigned int> frequencyLevelMap;
	queue<tNode *> currentLevel,nextLevel;
	currentLevel.push(ptr);
	unsigned int levelCounter = 0;
	while(!currentLevel.empty() && !nextLevel.empty()){
		if(currentLevel.empty()){
			while(!currentLevel.empty()){
				frequencyLevelMap[levelCounter] += 1;
				nextLevel.push(currentLevel.front());
				currentLevel.pop();
			}
		}else{
			levelCounter++;
			while(!nextLevel.empty()){
				currentLevel.push(nextLevel.front());
				nextLevel.pop();
			}
		}
	}
	unsigned int maxWidth = 0;
	for(unsigned int counter = 0;counter < frequencyLevelMap.size();counter++){
		if(maxWidth > frequencyLevelMap[counter]){
			maxWidth = frequencyLevelMap[counter];
		}
	}
	return maxWidth;
}

unsigned int maximumWidthTreeHashmap(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	hash_map<unsigned int,unsigned int> frequencyLevelMap;
	hash_map<unsigned int,unsigned int>::iterator itToFrequencyLevelMap;
	tHashmap hashMapFormTree = getHashmapFormOfTree(ptr,1);
	hash_map<unsigned int,tNode *> indexNodeMap = hashMapFormTree->indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	unsigned int currentNodeLevel;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeLevel = log2(itToIndexNodeMap->first);
		if(frequencyLevelMap.find(currentNodeLevel) == frequencyLevelMap.end()){
			frequencyLevelMap.insert(pair<unsigned int,unsigned int>(currentNodeLevel,1));
		}else{
			frequencyLevelMap[currentNodeLevel] += 1;
		}
	}
	unsigned int maxWidth = 0;
	for(itToFrequencyLevelMap = frequencyLevelMap.begin();itToFrequencyLevelMap = frequencyLevelMap.end();itToFrequencyLevelMap++){
		if(maxWidth > itToFrequencyLevelMap->second){
			maxWidth = itToFrequencyLevelMap->second;
		}
	}
	return maxWidth;
}

unsigned int maximumWidthTreePreOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
}
#endif /* MAXIMUMWIDTHOFTREE_H_ */

/************************************************* End code *******************************************************/
