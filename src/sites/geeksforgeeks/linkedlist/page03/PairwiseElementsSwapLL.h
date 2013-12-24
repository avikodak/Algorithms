/***************************************************************************************************************** 
 *  File Name   		: PairwiseElementsSwapLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\PairwiseElementsSwapLL.h
 *  Created on			: Dec 20, 2013 :: 11:01:01 PM
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

#ifndef PAIRWISEELEMENTSSWAPLL_H_
#define PAIRWISEELEMENTSSWAPLL_H_

void pairwiseElementsSwapAuxspace(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<int> oddUserInputs,evenUserInputs;
	llNode *crawler = ptr;
	bool oddElement = true;
	while(crawler != NULL){
		if(oddElement){
			oddUserInputs.push(crawler->value);
		}else{
			evenUserInputs.push(crawler->value);
		}
		crawler = crawler->next;
		oddElement = !oddElement;
	}

	oddElement = true;
	crawler = ptr;
	while(crawler != NULL){
		if(oddElement){
			crawler->value = evenUserInputs.front();
			evenUserInputs.pop();
		}else{
			crawler->value = oddUserInputs.front();
			oddUserInputs.pop();
		}
		oddElement = !oddElement;
		crawler = crawler->next;
	}
}

void pairwiseElementValueSwapIterative(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr;
	int tempForSwap;
	while(crawler != NULL && crawler->next != NULL){
		tempForSwap = crawler->value;
		crawler->value = crawler->next->value;
		crawler->next->value = tempForSwap;
		crawler = crawler->next->next;
	}
}

void pairwiseElementValueSwap(llNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	int tempForSwap = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = tempForSwap;
	pairwiseElementValueSwap(ptr->next->next);
}

void pairwiseElementValueSwapHashmap(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	hash_map<unsigned int,llNode *> indexValueMap;
	hash_map<unsigned int,llNode *>::iterator itToIndexValueMap,tempIt;
	llNode *crawler = ptr;
	int temp;
	unsigned int counter = 0;
	while(crawler != NULL){
		indexValueMap.insert(pair<unsigned int,llNode *>(counter++,crawler));
		crawler = crawler->next;
	}
	for(itToIndexValueMap = indexValueMap.begin();itToIndexValueMap != indexValueMap.end();itToIndexValueMap++){
		if(itToIndexValueMap->first % 2 == 1){
			tempIt = indexValueMap.find(itToIndexValueMap->first + 1);
			if(tempIt != indexValueMap.end()){
				temp = itToIndexValueMap->second->value;
				itToIndexValueMap->second->value = tempIt->second->value;
				tempIt->second->value = temp;
			}
		}
	}
}

void pairwiseElementSwapPtrChangeIterative(llNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	llNode *crawler = ptr,*parent = NULL,*temp;
	while(crawler != NULL && crawler->next != NULL){
		if(parent == NULL){
			temp = crawler->next;
			crawler->next = temp->next;
			temp->next = crawler;
			parent = crawler;
		}else{
			temp = crawler->next;
			crawler->next = temp->next;
			temp->next = crawler;
			parent->next = temp;
			parent = crawler;
			crawler = crawler->next;
		}
	}
}

void pairwiseElementSwapPtrChange(llNode *ptr,llNode *parent){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	llNode *temp;
	if(parent == NULL){

	}else{

	}
}
#endif /* PAIRWISEELEMENTSSWAPLL_H_ */

/************************************************* End code *******************************************************/
