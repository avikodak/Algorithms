/***************************************************************************************************************** 
 *  File Name   		: MergeTwoSortedLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\MergeTwoSortedLL.h
 *  Created on			: Dec 23, 2013 :: 1:29:19 AM
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

#ifndef MERGETWOSORTEDLL_H_
#define MERGETWOSORTEDLL_H_

llNode *mergeTwoSortedLL(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return NULL;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		if(firstPtr == NULL){
			return secondPtr;
		}else{
			return firstPtr;
		}
	}
	llNode *resultList,*resultListCrawler;
	int value;
	while(firstPtr != NULL && secondPtr != NULL){
		if(firstPtr->value < secondPtr){
			value = firstPtr->value;
			firstPtr = firstPtr->next;
		}else{
			value = secondPtr->value;
			secondPtr = secondPtr->next;
		}
		if(resultList == NULL){
			resultList = createNewLLNode(value);
			resultListCrawler = resultList;
		}else{
			resultListCrawler->next = createNewLLNode(value);
			resultListCrawler = resultListCrawler->next;
		}
	}

	while(firstPtr != NULL){
		if(resultList == NULL){
			resultList = createNewLLNode(firstPtr->value);
			resultListCrawler = resultList;
		}else{
			resultListCrawler->next = createNewLLNode(firstPtr->value);
			resultListCrawler = resultListCrawler->next;
		}
	}

	while(secondPtr != NULL){
		if(resultList == NULL){
			resultList = createNewLLNode(secondPtr->value);
			resultListCrawler = resultList;
		}else{
			resultListCrawler->next = createNewLLNode(secondPtr->value);
			resultListCrawler = resultListCrawler->next;
		}
	}

	return resultList;
}

llNode *mergeTwoSortedLL(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return NULL;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		if(firstPtr != NULL){
			return firstPtr;
		}else{
			return secondPtr;
		}
	}
	vector<int> auxSpace;
	llNode *crawler,*newList;
	crawler = firstPtr;
	while(crawler != NULL){
		auxSpace.push_back(crawler->value);
		crawler = crawler->next;
	}
	crawler = secondPtr;
	while(crawler != NULL){
		auxSpace.push_back(crawler->value);
		crawler = crawler->next;
	}
	sort(auxSpace.begin(),auxSpace.end());
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		if(newList == NULL){
			newList = createNewLLNode(auxSpace[counter]);
			crawler = newList;
		}else{
			crawler->next = createNewLLNode(auxSpace[counter]);
			crawler = crawler->next;
		}
	}
	return newList;
}

llNode *mergeTwoSortedLL(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return NULL;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		if(firstPtr != NULL){
			return firstPtr;
		}else{
			return secondPtr;
		}
	}
	llNode *newList;
	if(firstPtr->value < secondPtr->value){
		newList = createNewLLNode(firstPtr->value);
		newList->next = mergeTwoSortedLL(firstPtr->next,secondPtr->next);
	}else{
		newList = createNewLLNode(secondPtr->value);
		newList->next = mergeTwoSortedLL(firstPtr->next,secondPtr->next);
	}
}

#endif /* MERGETWOSORTEDLL_H_ */

/************************************************* End code *******************************************************/
