/***************************************************************************************************************** 
 *  File Name   		: ReverseLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\ReverseLL.h
 *  Created on			: Dec 18, 2013 :: 1:17:00 AM
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

#ifndef REVERSELL_H_
#define REVERSELL_H_

void reverseLL(llNode **head,llNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->next == NULL){
		(*head) = ptr;
		return;
	}
	reverseLL(ptr->next);
	ptr->next->next = ptr;
}

void reverseLLDriver(llNode **ptr){
	if(*ptr == NULL){
		return;
	}
	llNode *temp = (*ptr);
	reverseLL(ptr,*ptr);
	temp->next = NULL;
}

void reverseLLValues(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr;
	stack<int> auxSpace;
	while(crawler != NULL){
		auxSpace.push(crawler->value);
		crawler = crawler->next;
	}
	crawler = ptr;
	while(!auxSpace.empty()){
		crawler->value = auxSpace.top();
		auxSpace.pop();
	}
}

void reverseLLChangePtr(llNode **ptr){
	if(ptr == NULL){
		return;
	}
	llNode *revHead = NULL,*crawler = *ptr,*temp;
	while(crawler != NULL){
		temp = crawler;
		crawler = crawler->next;
		temp->next = revHead;
		revHead = temp;
	}
	(*ptr) = revHead;
}

llNode *reverseLLNewList(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *newList = NULL,*crawler = ptr,*newNode;

	while(crawler != NULL){
		newNode = createNewLLNode(crawler->value);
		newNode->next = newList;
		newList = newNode;
		crawler = crawler->next;
	}
	return newList;
}

void reverseLLValuesRecursive(llNode *crawler,llNode **headCrawler){
	if(crawler == NULL){
		return;
	}
	reverseLLValuesRecursive(crawler->next,headCrawler);
	int temp = crawler->value;
	crawler->value = (*headCrawler)->value;
	(*headCrawler)->value = temp;
	(*headCrawler) = (*headCrawler)->next;
}

void reverseLLStackAuxSpace(llNode **ptr){
	if(*ptr == NULL){
		return;
	}
	llNode *crawler = (*ptr);
	stack<llNode *> auxSpace;
	while(crawler != NULL){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}
	crawler = auxSpace.top();
	auxSpace.pop();
	while(!auxSpace.empty()){
		crawler->next = auxSpace.top();
		crawler = auxSpace.top();
		auxSpace.pop();
	}
	crawler->next = NULL;
}
#endif /* REVERSELL_H_ */

/************************************************* End code *******************************************************/
