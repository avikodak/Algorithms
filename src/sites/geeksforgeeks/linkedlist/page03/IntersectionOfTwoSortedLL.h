/***************************************************************************************************************** 
 *  File Name   		: IntersectionOfTwoSortedLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\IntersectionOfTwoSortedLL.h
 *  Created on			: Dec 20, 2013 :: 11:36:52 PM
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

#ifndef INTERSECTIONOFTWOSORTEDLL_H_
#define INTERSECTIONOFTWOSORTEDLL_H_

llNode *intersectionOfTwoSortedLLIterative(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL || secondPtr == NULL){
		return NULL;
	}
	llNode *newIntersectionLL,*intersectionCrawler;
	llNode *firstPtrCrawler = firstPtr,*secondPtrCrawler = secondPtr;
	while(firstPtrCrawler != NULL && secondPtrCrawler != NULL){
		if(firstPtrCrawler->value == secondPtrCrawler->value){
			if(newIntersectionLL == NULL){
				newIntersectionLL = createNewLLNode(firstPtrCrawler->value);
				intersectionCrawler = newIntersectionLL;
			}else{
				intersectionCrawler->next = createNewLLNode(firstPtrCrawler->value);
				intersectionCrawler = intersectionCrawler->next;
			}
			firstPtrCrawler = firstPtrCrawler->next;
			secondPtrCrawler = secondPtrCrawler->next;
		}else{
			if(firstPtrCrawler->value < secondPtrCrawler->value){
				firstPtrCrawler = firstPtrCrawler->next;
			}else{
				secondPtrCrawler = secondPtrCrawler->next;
			}
		}
	}
}

void intersectionOfTwoSortedLL(llNode *firstPtr,llNode *secondPtr,llNode **headPtr,llNode *crawler){
	if(firstPtr == NULL  || secondPtr == NULL){
		return;
	}
	if(firstPtr->value == secondPtr->value){
		if(*headPtr == NULL){
			(*headPtr) = createNewLLNode(firstPtr->value);
			intersectionOfTwoSortedLL(firstPtr->next,secondPtr->next,headPtr,*headPtr);
		}else{
			crawler->next = createNewLLNode(firstPtr->value);
			intersectionOfTwoSortedLL(firstPtr->next,secondPtr->next,headPtr,crawler->next);
		}

	}else{
		if(firstPtr->value < secondPtr->value){
			intersectionOfTwoSortedLL(firstPtr->next,secondPtr,headPtr,crawler);
		}else{
			intersectionOfTwoSortedLL(firstPtr,secondPtr->next,headPtr,crawler);
		}
	}
}

llNode *intersectionOfTwoSortedLLHashmap(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL || secondPtr == NULL){
		return NULL;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	llNode *firstLLCrawler = firstPtr,*secondLLCrawler = secondPtr,*newList,*newListCrawler;
	while(firstLLCrawler == NULL){
		if((itToFrequencyMap = frequencyMap.find(firstLLCrawler->value)) != frequencyMap.end()){
			frequencyMap[firstLLCrawler->value] += 1;
		}else{
			frequencyMap.find(pair<int,unsigned int>(firstLLCrawler->value,1));
		}
		firstLLCrawler = firstLLCrawler->next;
	}

	while(secondLLCrawler == NULL){
		if((itToFrequencyMap = frequencyMap.find(secondLLCrawler->value)) != frequencyMap.end()){
			if(newList == NULL){
				newList = createNewLLNode(secondLLCrawler->value);
				newListCrawler = newList;
			}else{
				newListCrawler->next = createNewLLNode(secondLLCrawler->value);
				newListCrawler = newListCrawler->next;
			}
			if(frequencyMap[secondLLCrawler->value] == 1){
				frequencyMap.erase(secondLLCrawler->value);
			}else{
				frequencyMap[secondLLCrawler->value] -= 1;
			}
		}
	}
	return newList;
}

llNode *intersectionOfTwoSortedLLBST(llNode *firstPtr,llNode *secondPtr){
	if(firstPtr == NULL || secondPtr == NULL){
		return NULL;
	}
	tNodeAuxVal *bstTree = NULL,*nodeToKey;
	createFrequencyBSTForLL(&bstTree,bstTree,firstPtr);
	llNode *intersectionList = NULL,*intersectionCrawler,*crawler = secondPtr;
	while(crawler != NULL){
		nodeToKey = searchForNodeABST(bstTree,crawler->value);
		if(nodeToKey != NULL){
			if(nodeToKey->auxValue > 0){
				if(intersectionList == NULL){
					intersectionList = createNewLLNode(crawler->value);
					intersectionCrawler = intersectionList;
				}else{
					intersectionCrawler->next = createNewLLNode(crawler->value);
					intersectionCrawler = intersectionCrawler->next;
				}
				nodeToKey->auxValue -= 1;
			}

		}
		crawler = crawler->next;
	}
	return intersectionList;
}
#endif /* INTERSECTIONOFTWOSORTEDLL_H_ */
/************************************************* End code *******************************************************/
