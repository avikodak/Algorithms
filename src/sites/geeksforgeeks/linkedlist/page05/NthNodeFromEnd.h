/***************************************************************************************************************** 
 *  File Name   		: NthNodeFromEnd.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page05\NthNodeFromEnd.h
 *  Created on			: Dec 17, 2013 :: 11:39:02 PM
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

/************************************************* Main code ******************************************************/

#ifndef NTHNODEFROMEND_H_
#define NTHNODEFROMEND_H_

llNode *getNthNodeFromEndIterative(llNode *ptr,unsigned int nValue){
	if(ptr == NULL){
		return NULL;
	}
	unsigned int length = 0;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		length++;
		traversalPtr = traversalPtr->next;
	}
	if(nValue > length){
		return NULL;
	}
	length = length - nValue;
	traversalPtr = ptr;
	while(length--){
		traversalPtr = traversalPtr->next;
	}
	return traversalPtr;
}

llNode *getNthNodeFromEndAuxspace(llNode *ptr,unsigned int nValue){
	if(ptr == NULL){
		return NULL;
	}
	stack<llNode *> auxSpace;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		auxSpace.push(traversalPtr);
		traversalPtr = traversalPtr->next;
	}
	while(!auxSpace.empty()){
		if(nValue == 0){
			return auxSpace.top();
		}
		nValue -= 1;
		auxSpace.pop();
	}
	return NULL;
}

llNode *getNthNodeFromEnd(llNode *ptr,unsigned int &nValue){
	if(ptr == NULL){
		return NULL;
	}
	llNode *result = getNthNodeFromEnd(ptr->next,nValue);
	if(result != NULL){
		return result;
	}
	nValue -= 1;
	return nValue == 0?ptr:NULL;
}

llNode *getNthNodeFromEndHashmap(llNode *ptr,unsigned int nValue){
	if(ptr == NULL){
		return NULL;
	}
	unsigned int index = 0;
	hash_map<unsigned int,llNode *> indexNodeMap;
	hash_map<unsigned int,llNode *>::iterator itToIndexNodeMap;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		indexNodeMap.insert(pair<unsigned int,llNode *>(index,traversalPtr));
		traversalPtr = traversalPtr->next;
		index++;
	}
	index -= 1;
	itToIndexNodeMap = indexNodeMap.find(nValue);
	return itToIndexNodeMap == indexNodeMap.end()?NULL:itToIndexNodeMap->second;
}
#endif /* NTHNODEFROMEND_H_ */

/************************************************* End code *******************************************************/
