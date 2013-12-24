/***************************************************************************************************************** 
 *  File Name   		: MiddleOfLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page05\MiddleOfLL.h
 *  Created on			: Dec 17, 2013 :: 11:31:44 PM
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

#ifndef MIDDLEOFLL_H_
#define MIDDLEOFLL_H_

llNode *getMiddleNodeOfLLIterative(llNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNode *fastPtr,*slowPtr;
	fastPtr = slowPtr = ptr;
	while(slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr;
}

llNode *getMiddleNodeOfLLByLengthIterative(llNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	unsigned int lengthOfLL = 0;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		traversalPtr = traversalPtr->next;
		lengthOfLL++;
	}
	unsigned int requiredLength = lengthOfLL/2;
	traversalPtr = ptr;
	while(requiredLength--){
		traversalPtr = traversalPtr->next;
	}
	return traversalPtr;
}

llNode *getMiddleNodeOfLLHashmap(llNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	hash_map<unsigned int,llNode *> indexNodeMap;
	hash_map<unsigned int,llNode *>::iterator itToIndexNodeMap;
	unsigned int index = 0;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		indexNodeMap.insert(pair<unsigned int,llNode *>(index++,traversalPtr));
		traversalPtr = traversalPtr->next;
	}
	itToIndexNodeMap = indexNodeMap.find((index-1)/2);
	return itToIndexNodeMap->second;
}

llNode *getMiddleNodeOfLL(llNode *ptr,unsigned int runningIndex,unsigned int &middleIndex){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->next == NULL){
		middleIndex = (runningIndex)/2;
	}
	llNode *returnPtr = getMiddleNodeOfLL(ptr->next,runningIndex+1,middleIndex);
	if(returnPtr != NULL){
		return returnPtr;
	}
	return middleIndex == runningIndex?ptr:NULL;
}


#endif /* MIDDLEOFLL_H_ */

/************************************************* End code ********************************************************/
