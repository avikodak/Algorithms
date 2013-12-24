/***************************************************************************************************************** 
 *  File Name   		: IntersectionOfLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\IntersectionOfLL.h
 *  Created on			: Dec 18, 2013 :: 11:39:26 PM
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

#ifndef INTERSECTIONOFLL_H_
#define INTERSECTIONOFLL_H_

llNode *intersectionOfLL(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL || secondPtr == NULL){
		return NULL;
	}
	unsigned int firstLength = 0,secondLength = 0;
	llNode *firstTraversalPtr = firstPtr,*secondTraversalPtr = secondPtr;
	while(firstTraversalPtr != NULL){
		firstLength++;
		firstTraversalPtr = firstTraversalPtr->next;
	}
	while(secondTraversalPtr != NULL){
		secondLength++;
		secondTraversalPtr = secondTraversalPtr->next;
	}
	return NULL;
}

llNodeWithFlag *intersectionOfLLFlag(llNodeWithFlag *firstPtr,llNodeWithFlag *secondPtr){
	if(firstPtr == NULL || secondPtr == NULL){
		return NULL;
	}
	llNodeWithFlag *firstTraversalPtr = firstPtr,*secondTraversalPtr = secondPtr;
	while(firstTraversalPtr != NULL){
		firstTraversalPtr->flag = true;
		firstTraversalPtr = firstTraversalPtr->next;
	}
	while(secondTraversalPtr != NULL){
		if(secondTraversalPtr->flag){
			return secondTraversalPtr;
		}
		secondTraversalPtr = secondTraversalPtr->next;
	}
	return NULL;
}

llNode *intersectionOfLLHashmap(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL || secondPtr == NULL){
		return NULL;
	}
	hash_map<uint32_t,bool> auxHashmap;
	hash_map<uint32_t,bool>::iterator itToAuxHashmap;
	llNode *firstTraversalPtr = firstPtr,*secondTraversalPtr = secondPtr;
	while(firstTraversalPtr != NULL){
		auxHashmap.insert(pair<uint32_t,bool>)((uint32_t)firstTraversalPtr,true);
		firstTraversalPtr = firstTraversalPtr->next;
	}
	while(secondTraversalPtr != NULL){
		if((itToAuxHashmap = auxHashmap.find((uint32_t)secondTraversalPtr)) != auxHashmap.end()){
			return (llNode *)itToAuxHashmap->first;
		}
		secondTraversalPtr = secondTraversalPtr->next;
	}
	return NULL;
}

#endif /* INTERSECTIONOFLL_H_ */
/************************************************* End code *******************************************************/
