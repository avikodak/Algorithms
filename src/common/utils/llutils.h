/***************************************************************************************************************** 
 *  File Name   		: llutils.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\common\utils\llutils.h
 *  Created on			: Dec 13, 2013 :: 2:24:49 AM
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
#include <programming/ds/linkedlist.h>


/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef LLUTILS_H_
#define LLUTILS_H_

/********************************************** Linked list utils  *************************************************/

llNode *createNewLLNode(int userInput){
	llNode *newNode = (llNode *)malloc(sizeof(llNode));
	newNode->value = userInput;
	newNode->next = NULL;
	return newNode;
}

llNodeWithArbitPtr *createNewLLArbitNode(int userInput){
	llNodeWithArbitPtr *newNode = (llNodeWithArbitPtr *)malloc(sizeof(llNodeWithArbitPtr));
	newNode->value = userInput;
	newNode->next = NULL;
	newNode->arbitraryPtr = NULL;
	return newNode;
}

void createLL(llNode **ptr,llNode *traversalPtr,vector<int> userInput,unsigned int index){
	if(index >= userInput.size()){
		return;
	}
	if(*ptr == NULL){
		(*ptr) = createNewLLNode(userInput[index]);
		createLL(ptr,(*ptr),userInput,index+1);
	}else{
		traversalPtr->next = createNewLLNode(userInput[index]);
		createLL(ptr,traversalPtr->next,userInput,index+1);
	}
}

void createLLIterativeAppendEnd(llNode **ptr,vector<int> userInput){
	if((*ptr) != NULL){
		printf("Linked list is not empty");
		return;
	}
	(*ptr) = createNewLLNode(userInput[0]);
	llNode *traversalPtr = *ptr;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		traversalPtr->next = createNewLLNode(userInput[counter]);
		traversalPtr = traversalPtr->next;
	}
}

void createLLIterative(llNode **ptr,vector<int> userInput){
	if((*ptr) != NULL){
		printf("Linked list is not empty");
		return;
	}
	(*ptr) = createNewLLNode(userInput[0]);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		llNode *newNode = createNewLLNode(userInput[counter]);
		newNode->next = (*ptr);
		(*ptr) = newNode;
	}
}

void insertNodeLL(llNode **ptr,int userInput){
	if(*ptr == NULL){
		(*ptr) = createNewLLNode(userInput);
	}else{
		llNode *newNode = createNewLLNode(userInput);
		newNode->next = (*ptr);
		(*ptr) = newNode;
	}
}

/******************************************* Linked list traversals *************************************************/
void printLinkedList(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	printf("%d->",ptr->value);
	printLinkedList(ptr->next);
}

unsigned int lengthOfLinkedList(llNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1+lengthOfLinkedList(ptr->next);
}

/******************************************** Sorting linked list ***************************************************/
void bubbleSortLL(llNode *ptr){

}

void mergeSortLL(llNode *ptr){

}

void quickSortLL(llNode *ptr){

}

/*************************************** Linked list as hashmap utils ***********************************************/
llHashmap *getHashmapOfLL(llNode *ptr){

}

#endif /* LLUTILS_H_ */

/************************************************* End code *******************************************************/
