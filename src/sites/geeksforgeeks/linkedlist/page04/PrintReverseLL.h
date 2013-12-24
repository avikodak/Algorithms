/***************************************************************************************************************** 
 *  File Name   		: PrintReverseLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\PrintReverseLL.h
 *  Created on			: Dec 18, 2013 :: 11:16:10 PM
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

#ifndef PRINTREVERSELL_H_
#define PRINTREVERSELL_H_

void printReverseLL(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	printReverseLL(ptr->next);
	printf("%d\t",ptr->value);
}

void printReverseLLAuxspace(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<llNode *> auxSpace;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		auxSpace.push(traversalPtr);
		traversalPtr = traversalPtr->next;
	}
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
}

void printReverseLLNaiveAlgorithm(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	unsigned int lengthOfLinkedList = 0,distance;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		lengthOfLinkedList++;
		traversalPtr = traversalPtr->next;
	}
	for(unsigned int counter = 0;counter < lengthOfLinkedList;counter++){
		distance = lengthOfLinkedList - counter - 1;
		traversalPtr = ptr;
		while(distance--){
			traversalPtr = traversalPtr->next;
		}
		printf("%d\t",traversalPtr->value);
	}
}

void printReverseLLHashmap(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	hash_map<unsigned int,llNode *> indexNodeMap;
	unsigned int counter = 0;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		indexNodeMap.insert(pair<unsigned int,llNode *>(counter++,traversalPtr));
	}
	counter--;
	hash_map<unsigned int,llNode *>::iterator itToIndexNodeMap;
	while(counter >= 0){
		itToIndexNodeMap = indexNodeMap.find(counter);
		printf("%d\t",itToIndexNodeMap->second->value);
	}
}
#endif /* PRINTREVERSELL_H_ */

/************************************************* End code *******************************************************/
