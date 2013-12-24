/***************************************************************************************************************** 
 *  File Name   		: NthNodeInLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page05\NthNodeInLL.h
 *  Created on			: Dec 17, 2013 :: 10:54:03 PM
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

#ifndef NTHNODEINLL_H_
#define NTHNODEINLL_H_

llNode *getNthNodeLL(llNode *ptr,unsigned int nValue){
	if(ptr == NULL){
		return NULL;
	}
	if(nValue == 0){
		return ptr;
	}
	return getNthNodeLL(ptr->next,nValue-1);
}

llNode *getNthNodeLLIterative(llNode *ptr,unsigned int nValue){
	if(ptr == NULL){
		return NULL;
	}
	llNode *traversalNode = ptr;
	while(nValue-- > 0 && traversalNode != NULL){
		traversalNode = traversalNode->next;
	}
	if(traversalNode != NULL){
		return traversalNode;
	}
	return NULL;
}

llNode *getNthNodeLLHashmap(llNode *ptr,unsigned int nValue){
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
	if((itToIndexNodeMap = indexNodeMap.find(nValue)) != indexNodeMap.end()){
		return itToIndexNodeMap->second->value;
	}
	return NULL;
}
#endif /* NTHNODEINLL_H_ */
/************************************************* End code *******************************************************/
