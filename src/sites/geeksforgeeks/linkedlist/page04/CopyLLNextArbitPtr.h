/***************************************************************************************************************** 
 *  File Name   		: CopyLLNextArbitPtr.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\CopyLLNextArbitPtr.h
 *  Created on			: Dec 18, 2013 :: 11:40:10 PM
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

#ifndef COPYLLNEXTARBITPTR_H_
#define COPYLLNEXTARBITPTR_H_

llNodeWithArbitPtr *copyLLNextArbitptrNaive(llNodeWithArbitPtr *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNodeWithArbitPtr *newList = NULL,*newListCrawler,*crawler = ptr,*innerCrawler;
	while(crawler != NULL){
		if(newList == NULL){
			newList = createNewLLArbitNode(crawler->value);
			newListCrawler = newList;
		}else{
			newListCrawler->next = createNewLLArbitNode(crawler->value);
			newListCrawler = newListCrawler->next;
		}
		crawler = crawler->next;
	}

	unsigned int distanceForArbitPtr;
	crawler = ptr;
	newListCrawler = newList;
	while(newListCrawler != NULL){
		if(crawler->arbitraryPtr != NULL){
			distanceForArbitPtr = 0;
			innerCrawler = ptr;
			while(innerCrawler != crawler->arbitraryPtr){
				distanceForArbitPtr+=1;
				innerCrawler = innerCrawler->next;
			}
			innerCrawler = newList;
			while(distanceForArbitPtr--){
				innerCrawler = innerCrawler->next;
			}
			newListCrawler->arbitraryPtr = innerCrawler;
		}else{
			newListCrawler->arbitraryPtr = NULL;
		}
		newListCrawler = newListCrawler->next;
		crawler = crawler->next;
	}
}

llNodeWithArbitPtr *copyLLNextArbitPtrChangePtr(llNodeWithArbitPtr *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNodeWithArbitPtr *newList,*newNode,*crawler = ptr,*newListCrawler,*temp;
	while(crawler != NULL){
		if(newList == NULL){
			newList = createNewLLArbitNode(crawler->value);
			newListCrawler = newList;
		}else{
			newListCrawler->next = createNewLLArbitNode(crawler->value);
			newListCrawler  = newListCrawler->next;
		}
		crawler = crawler->next;
	}
	newListCrawler = newList;
	crawler = ptr;
	hash_map<uint32_t,llNodeWithArbitPtr *> mapOfNodeAndNextPtrs;
	while(crawler != NULL){
		mapOfNodeAndNextPtrs.insert(pair<uint32_t,llNodeWithArbitPtr *>((uint32_t)crawler,crawler->next));
		temp = crawler->next;
		crawler = newListCrawler;
		crawler = temp;
		temp = newListCrawler->next;
		newListCrawler->next = NULL;
		newListCrawler = temp;
	}

	newListCrawler = newList;
	crawler = ptr;
	while(newListCrawler != NULL){
		newListCrawler->arbitraryPtr = crawler->arbitraryPtr->next;
		crawler = mapOfNodeAndNextPtrs.find((uint32_t)crawler);
		newListCrawler->next = crawler->next;
		newListCrawler = newListCrawler->next;
	}

	crawler = ptr;
	while(crawler != NULL){
		crawler->next = mapOfNodeAndNextPtrs.find((uint32_t)crawler);
		crawler = crawler->next;
	}
	return newList;
}

llNodeWithArbitPtr *copyLLNextArbitptrMidInsert(llNodeWithArbitPtr *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNodeWithArbitPtr *crawler = ptr;
	llNodeWithArbitPtr *newNode,*newList = NULL,*newListCrawler;
	while(crawler != NULL){
		newNode = createNewLLArbitNode(crawler->value);
		newNode->next = crawler->next;
		crawler->next = newNode;
		crawler = crawler->next->next;
	}
	crawler = ptr;
	while(crawler != NULL){
		crawler->next->arbitraryPtr = crawler->arbitraryPtr->next;
		crawler = crawler->next->next;
	}

	while(crawler != NULL){
		if(newList == NULL){
			newList = crawler->next;
			newListCrawler = newList;
			crawler->next = crawler->next->next;
		}else{
			newListCrawler->next = crawler->next;
			crawler->next = crawler->next->next;
			newListCrawler = newListCrawler->next;
		}
		crawler = crawler->next;
	}
	return newList;
}

llNodeWithArbitPtr *copyLLNextArbitptrHashmap(llNodeWithArbitPtr *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNodeWithArbitPtr *crawler = ptr,*newList,*newListCrawler;
	hash_map<uint32_t,unsigned int> mapOfNodeIndex;
	hash_map<uint32_t,unsigned int>::iterator itToMapNodeIndex;
	hash_map<unsigned int,uint32_t> mapOfIndexNodeNew;
	hash_map<unsigned int,uint32_t>::iterator itToMapIndexNodeNew;
	unsigned int counter = 0;
	while(crawler != NULL){
		mapOfNodeIndex.insert(pair<uint32_t,unsigned int>((uint32_t)crawler,counter));
		if(newList == NULL){
			newList = createNewLLArbitNode(crawler->value);
			newListCrawler = newList;
			mapOfIndexNodeNew.insert(pair<unsigned int,uint32_t>(counter,newList));
		}else{
			newListCrawler->next = createNewLLArbitNode(crawler->value);
			mapOfIndexNodeNew.insert(pair<unsigned int,uint32_t>(counter,newListCrawler->next));
			newListCrawler = newListCrawler->next;
		}
		crawler = crawler->next;
		counter += 1;
	}


	return newList;
}


#endif /* COPYLLNEXTARBITPTR_H_ */
/************************************************* End code *******************************************************/
