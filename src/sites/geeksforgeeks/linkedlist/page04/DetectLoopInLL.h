/***************************************************************************************************************** 
 *  File Name   		: DetectLoopInLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\DetectLoopInLL.h
 *  Created on			: Dec 18, 2013 :: 1:17:36 AM
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

#ifndef DETECTLOOPINLL_H_
#define DETECTLOOPINLL_H_

bool detectLoopInLLHashmapIterative(llNode *ptr){
	if(ptr == NULL){
		return false;
	}
	hash_map<uint32_t,bool> visitedFlagMap;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		if(traversalPtr->next == NULL){
			return false;
		}
		if(visitedFlagMap.find((uint32_t)traversalPtr->next) != visitedFlagMap.end()){
			return true;
		}
		visitedFlagMap.insert(pair<uint32_t,bool>((uint32_t)traversalPtr,true));
	}
	return false;
}

bool detectLoopAuxspaceIterative(llNodeWithFlag *ptr){
	if(ptr == NULL){
		return false;
	}
	llNodeWithFlag *traversalPtr = ptr;
	while(traversalPtr != NULL){
		if(traversalPtr->next == NULL){
			return false;
		}
		if(traversalPtr->next->flag){
			return true;
		}
		traversalPtr->flag = true;
	}
	return false;
}

bool detectLoopAuxspace(llNodeWithFlag *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return false;
	}
	if(ptr->next->flag){
		return true;
	}
	ptr->flag = true;
	return detectLoopAuxspaceRecursive(ptr->next);
}

bool detectLoopTwoPtrsIterative(llNodeWithFlag *ptr){
	if(ptr == NULL){
		return false;
	}
	llNode *slowPtr = ptr,*fastPtr = ptr;
	while(slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL){
		if(slowPtr == fastPtr){
			return true;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return false;
}
#endif /* DETECTLOOPINLL_H_ */

/************************************************* End code *******************************************************/
