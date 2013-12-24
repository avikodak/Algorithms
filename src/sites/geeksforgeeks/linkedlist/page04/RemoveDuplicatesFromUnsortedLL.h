/***************************************************************************************************************** 
 *  File Name   		: RemoveDuplicatesFromUnsortedLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\RemoveDuplicatesFromUnsortedLL.h
 *  Created on			: Dec 18, 2013 :: 11:41:28 PM
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

#ifndef REMOVEDUPLICATESFROMUNSORTEDLL_H_
#define REMOVEDUPLICATESFROMUNSORTEDLL_H_

void removeDuplicatesFromUnsortedON2(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *outerCrawler = ptr,*innerCrawler,*tempNode;
	while(outerCrawler != NULL){
		innerCrawler = outerCrawler;
		while(innerCrawler->next != NULL){
			if(outerCrawler->value == innerCrawler->next->value){
				tempNode = innerCrawler->next;
				innerCrawler->next = innerCrawler->next->next;
				free(tempNode);
			}else{
				innerCrawler = innerCrawler->next;
			}
		}
		outerCrawler = outerCrawler->next;
	}
}

void removeDuplicatesFromUnsortedHashmap(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	llNode *crawler = ptr,*tempNode;
	while(crawler !=  NULL){
		if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()){
			frequencyMap[crawler->value]++;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(crawler->value,1));
		}
	}
	crawler = ptr;
	frequencyMap[crawler->value] -= 1;
	while(crawler->next != NULL){
		if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()){
			if(itToFrequencyMap->second > 1){
				crawler->value = crawler->next->value;
				crawler->next = crawler->next->next;
				tempNode = crawler->next;
				free(tempNode);
			}
			frequencyMap[itToFrequencyMap->first] -= 1;
		}
	}
}

void removeDuplicatesFromUnsortedBySorting(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *outerCrawler = ptr,*innerCrawler;
	int minValue,temp;
	while(outerCrawler != NULL){
		innerCrawler = outerCrawler->next;
		minValue = outerCrawler->value;
		while(innerCrawler != NULL){
			if(minValue > innerCrawler->value){
				minValue = innerCrawler->value;
			}
			innerCrawler = innerCrawler->next;
		}
		temp = outerCrawler->value;
		outerCrawler->value = innerCrawler->value;
		innerCrawler->value = temp;
		outerCrawler = outerCrawler->next;
	}
	removeDuplicatesFromSortedLL(ptr);
	return;
}

void removeDuplicatesFromUnsortedBST(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNodeAuxVal *aBST,*keyNode;
	createFrequencyBSTForLL(&aBST,aBST,ptr);
	llNode *crawler = ptr,*tempNode;
	keyNode = searchForNodeABSTIterative(aBST,crawler->value);
	keyNode->auxValue -= 1;
	while(crawler->next != NULL){
		keyNode = searchForNodeABSTIterative(aBST,crawler->next->value);
		if(keyNode->auxValue > 1){
			tempNode = crawler->next;
			crawler->next = crawler->next->next;
			free(tempNode);
		}else{
			crawler = crawler->next;
		}
		keyNode->auxValue -= 1;
	}
}

void removeDuplicatesFromUnsortedNewList(llNode **ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler,*newList = NULL,*newListCrawler = NULL;
	bool isFound;
	crawler = (*ptr);
	while(crawler != NULL){
		if(newList == NULL){
			newList = createNewLLNode(crawler->value);
		}else{
			newListCrawler = newList;
			isFound = false;
			while(newListCrawler->next != NULL){
				if(newListCrawler->value == crawler->value){
					isFound = true;
					break;
				}
				newListCrawler = newListCrawler->next;
			}
			if(!isFound){
				newListCrawler->next = createNewLLNode(crawler->value);
			}
		}
		crawler = crawler->next;
	}
	(*ptr) = newList;
	return;
}

#endif /* REMOVEDUPLICATESFROMUNSORTEDLL_H_ */

/************************************************* End code *******************************************************/
