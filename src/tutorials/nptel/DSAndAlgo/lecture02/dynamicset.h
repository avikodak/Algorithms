/***************************************************************************************************************** 
 *  File Name   		: dynamicset.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture02\dynamicset.h
 *  Created on			: Dec 29, 2013 :: 5:10:27 PM
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

#ifndef DYNAMICSET_H_
#define DYNAMICSET_H_

void addToDynamicSet(llNode **ptr,int userInput){
	if(*ptr == NULL){
		(*ptr) = (llNode *)malloc(sizeof(llNode));
		(*ptr)->value = userInput;
		(*ptr)->next = NULL;
	}else{
		bool elementExists = false;
		llNode *crawler = *ptr;
		while(crawler != NULL){
			if(crawler->value == userInput){
				elementExists = true;
			}
		}
		if(!elementExists){
			llNode *newNode = (llNode *)malloc(sizeof(llNode));
			newNode->value = userInput;
			newNode->next = (*ptr);
			(*ptr) = newNode;
		}
	}
}

void deleteFromDynamicSet(llNode **ptr,int userInput){
	if(*ptr == NULL){
		printf("Dynamic set is empty");
		return;
	}else{
		llNode *nodeToBeDeleted;
		if((*ptr)->value == userInput){
			if((*ptr)->next != NULL){
				nodeToBeDeleted = (*ptr);
				free(nodeToBeDeleted);
				(*ptr) = (*ptr)->next;
			}else{
				nodeToBeDeleted = (*ptr);
				free(nodeToBeDeleted);
				(*ptr) = NULL;
			}
		}else{
			llNode *crawler = *ptr;
			while(crawler->next != NULL && crawler->next->value != userInput){
				crawler = crawler->next;
			}
			if(crawler->next != NULL){
				nodeToBeDeleted = crawler->next;
				crawler->next = crawler->next->next;
				free(nodeToBeDeleted);
			}
		}
	}
}

#endif /* DYNAMICSET_H_ */
/************************************************* End code *******************************************************/
