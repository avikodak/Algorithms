/***************************************************************************************************************** 
 *  File Name   		: IdenticalLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\IdenticalLL.h
 *  Created on			: Dec 20, 2013 :: 10:46:54 PM
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

#ifndef IDENTICALLL_H_
#define IDENTICALLL_H_

bool identicalLinkedList(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return true;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		return false;
	}
	if(firstPtr->value != secondPtr->value){
		return false;
	}
	return identicalLinkedList(firstPtr->next,secondPtr->next);
}

bool identicalLinkedListIterative(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return true;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		return false;
	}
	llNode *firstPtrCrawler = firstPtr,*secondPtrCrawler = secondPtr;
	while(firstPtrCrawler != NULL && secondPtrCrawler != NULL){
		if(firstPtrCrawler->value != secondPtrCrawler->value){
			return false;
		}
		firstPtrCrawler = firstPtrCrawler->next;
		secondPtrCrawler = secondPtrCrawler->next;
	}
	if(firstPtrCrawler != NULL || secondPtrCrawler == NULL){
		return false;
	}
	return true;
}

bool identicalLinkedListHashmap(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return true;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		return false;
	}
	hash_map<unsigned int,llNode *> indexNodeMap;
	hash_map<unsigned int,llNode *>::iterator itToIndexNodeMap;
	unsigned int counter = 0;
	llNode *firstPtrCrawler = firstPtr,*secondPtrCrawler = secondPtr;
	while(firstPtrCrawler != NULL){
		indexNodeMap.insert(pair<unsigned int,llNode *>(counter++,firstPtrCrawler));
		firstPtrCrawler = firstPtrCrawler->next;
	}
	counter = 0;
	while(secondPtrCrawler != NULL){
		itToIndexNodeMap = indexNodeMap.find(counter++);
		if(itToIndexNodeMap == indexNodeMap.end()){
			return false;
		}
		if(itToIndexNodeMap->second->value != secondPtrCrawler->value){
			return false;
		}
		secondPtrCrawler = secondPtrCrawler->next;
	}
	return true;
}

#endif /* IDENTICALLL_H_ */
/************************************************* End code *******************************************************/
