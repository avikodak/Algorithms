/***************************************************************************************************************** 
 *  File Name   		: llstack.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture02\llstack.h
 *  Created on			: Dec 29, 2013 :: 5:57:35 PM
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

#ifndef LLSTACK_H_
#define LLSTACK_H_

void pushdynamicStack(llNode **ptr,int userInput){
	llNode *newNode = (llNode *)malloc(sizeof(llNode));
	newNode->value = userInput;
	newNode->next = (*ptr);
	(*ptr) = newNode;
}

void popdynamicStack(llNode **ptr){
	if((*ptr) == NULL){
		printf("stack is empty\n");
		return;
	}else{
		llNode *nodeToBeDeleted = (*ptr);
		(*ptr) = (*ptr)->next;
		free(nodeToBeDeleted);
	}
}

int topdynamicStack(llNode *ptr){
	return ptr->value;
}

unsigned int sizedynamicStack(llNode *ptr){
	return ptr == NULL?0:1+sizedynamicStack(ptr->next);
}

bool emptydynamicStack(llNode *ptr){
	return ptr == NULL?true:false;
}
#endif /* LLSTACK_H_ */

/************************************************* End code *******************************************************/
