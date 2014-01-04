/***************************************************************************************************************** 
 *  File Name   		: llqueue.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture03\llqueue.h
 *  Created on			: Dec 29, 2013 :: 7:07:33 PM
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

#ifndef LLQUEUE_H_
#define LLQUEUE_H_

void enqueuedynamicQueue(llNode **ptr,int userInput){
	llNode *newNode = (llNode *)malloc(sizeof(llNode));
	newNode->value = userInput;
	newNode->next = NULL;
	if(*ptr == NULL){
		(*ptr) = newNode;
	}else{
		llNode *crawler = (*ptr);
		while(crawler->next != NULL){
			crawler = crawler->next;
		}
		crawler->next = newNode;
	}
}

void dequeuedynamicQueue(llNode **ptr){
	if(*ptr == NULL){
		printf("Queue is empty\n");
		return;
	}
	llNode *nodeToBeDeleted = (*ptr);
	(*ptr) = (*ptr)->next;
	free(nodeToBeDeleted);
}

int frontdynamicQueue(llNode *ptr){
	if(ptr == NULL){
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return ptr->value;
}

unsigned int sizeOfdynamicQueue(llNode *ptr){
	return ptr == NULL?0:1+sizeOfdynamicQueue(ptr->next);
}

bool isQueueempty(llNode *ptr){
	return ptr == NULL?true:false;
}

#endif /* LLQUEUE_H_ */

/************************************************* End code *******************************************************/
