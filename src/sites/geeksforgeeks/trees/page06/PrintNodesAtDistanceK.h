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
	currentLevel.push(ptr);
	while(!currentLevel.empty()&&!nextLevel.empty()){
		if(!currentLevel.empty()){

		}else{

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

void printNodesAtDistanceKIterative(tNode *ptr,unsigned int targetLevel){
	if(ptr == NULL){
		return;
	}
}
#endif /* PRINTNODESATDISTANCEK_H_ */

/************************************************* End code *******************************************************/
