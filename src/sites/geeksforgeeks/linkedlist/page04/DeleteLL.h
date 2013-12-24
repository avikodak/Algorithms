/***************************************************************************************************************** 
 *  File Name   		: DeleteLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\DeleteLL.h
 *  Created on			: Dec 17, 2013 :: 11:48:13 PM
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
#include <programming/utils/treeutils.h>

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef DELETELL_H_
#define DELETELL_H_

void deleteLL(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->next == NULL){
		return;
	}
	deleteLL(ptr->next);
	free(ptr);

}

void deleteLLDriver(llNode **ptr){
	if((*ptr) == NULL){
		return;
	}
	deleteLL(ptr);
	(*ptr) = NULL;
}

void deleteLLIterative(llNode **ptr){
	if((*ptr) == NULL){
		return;
	}
	stack<llNode *> auxSpace;
	llNode *traversalPtr = ptr,*tempNode;
	while(!auxSpace.empty()){
		auxSpace.push(traversalPtr);
		traversalPtr = traversalPtr->next;
	}
	auxSpace.pop();
	while(!auxSpace.empty()){
		tempNode = auxSpace.top()->next;
		auxSpace.pop();
		free(tempNode);
	}
	tempNode = (*ptr);
	(*ptr) = NULL;
	free(tempNode);
}

void deleteLLHashmap(llNode **ptr){
	if((*ptr) == NULL){
		return;
	}
	vector<llNode *> nodes;
	llNode *tempNode;
	llNode *traversalPtr = (*ptr);
	while(traversalPtr != NULL){
		nodes.push_back(traversalPtr);
		traversalPtr = traversalPtr->next;
	}
	for(unsigned int counter = nodes.size()-1;counter >= 0;counter--){
		tempNode = nodes[counter];
		free(tempNode);
	}
	(*ptr) = NULL;
}
#endif /* DELETELL_H_ */
/************************************************* End code *******************************************************/
