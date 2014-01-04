/***************************************************************************************************************** 
 *  File Name   		: deque.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture03\deque.h
 *  Created on			: Dec 29, 2013 :: 10:01:56 PM
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

#ifndef DEQUE_H_
#define DEQUE_H_

dllNode *createNewDllNode(int userInput){
	dllNode *newNode = (dllNode *)malloc(sizeof(dllNode));
	newNode->value = userInput;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void enqueueFrontDynamicDeque(dllNode **ptr,int userInput){
	dllNode *newNode = createNewDllNode(userInput);
	if(*ptr == NULL){
		(*ptr) = newNode;
	}else{
		newNode->next = (*ptr);
		(*ptr)->prev = newNode;
		(*ptr) = newNode;
	}
}

void enqueueBackDynamicDeque(dllNode **ptr,int userInput){
	dllNode *newNode = createNewDllNode(userInput);
	if(*ptr == NULL){
		(*ptr) = newNode;
	}else{
		dllNode *crawler = (*ptr);
		while(crawler->next != NULL){
			crawler = crawler->next;
		}
		crawler->next = newNode;
		newNode->prev = crawler;
	}
}

void dequeFrontDynamicDeque(dllNode **ptr){
	if(*ptr == NULL){
		printf("Deque is empty");
		return;
	}
	dllNode *nodeToBeDeleted = (*ptr);
	(*ptr) = (*ptr)->next;
	(*ptr)->prev = NULL;
	free(nodeToBeDeleted);
}

void dequeBackDynamicDeque(dllNode **ptr){
	if(*ptr == NULL){
		printf("Deque is empty");
		return;
	}
	dllNode *crawler = (*ptr);
	while(crawler->next != NULL){
		crawler = crawler->next;
	}
	crawler->prev->next = NULL;
	free(crawler);
}

int getFrontDynamicQueue(dllNode *ptr){
	if(ptr == NULL){
		printf("Queue is empty");
		return;
	}
	return ptr->value;
}

int getBackDynamicQueue(dllNode *ptr){
	if(ptr == NULL){
		printf("Queue is empty");
		return;
	}
	dllNode *crawler= ptr;
	while(crawler->next != NULL){
		crawler = crawler->next;
	}
	return crawler->value;
}

unsigned int sizeDynamicDeque(dllNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int size = 0;
	dllNode *crawler = ptr;
	while(crawler != NULL){
		crawler = crawler->next;
		size++;
	}
	return size;
}

bool isEmptyDeque(dllNode *ptr){
	return ptr == NULL?true:false;
}

#endif /* DEQUE_H_ */

/************************************************* End code *******************************************************/
