/***************************************************************************************************************** 
 *  File Name   		: CheckPalindromeSinglyLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\CheckPalindromeSinglyLL.h
 *  Created on			: Dec 18, 2013 :: 1:18:39 AM
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

#ifndef CHECKPALINDROMESINGLYLL_H_
#define CHECKPALINDROMESINGLYLL_H_

bool checkPalindromeSinglyLLRecursive(llNode *ptr,llNode **ptrRef){
	if(ptr == NULL){
		return true;
	}
	if(!checkPalindromeSinglyLLRecursive(ptr->next,ptrRef)){
		return false;
	}
	if((*ptrRef)->value != ptr->value){
		return false;
	}else{
		(*ptrRef) = (*ptrRef)->next;
		return true;
	}
}

bool checkPalindromeSingleLLReverse(llNode *ptr){
	if(ptr == NULL){
		return true;
	}
	llNode *revHead; // Reverse ll in new ll
	while(revHead != NULL && ptr != NULL){
		if(revHead->value != ptr->value){
			return false;
		}
	}
	return true;
}

bool checkPalindromeDLL(dllNode *ptr){
	if(ptr == NULL){
		return true;
	}
	dllNode *tailNode = ptr;
	while(tailNode->next != NULL){
		tailNode = tailNode->next;
	}
	while(ptr != tailNode && ptr != NULL && tailNode != NULL){
		if(ptr->value != tailNode->value){
			return false;
		}
	}
	return true;
}

bool checkPalindromeSinglyLL(llNode *ptr){
	if(ptr == NULL){
		return true;
	}
	stack<llNode *> auxSpace;
	llNode *currentNode = ptr;
	while(currentNode != NULL){
		auxSpace.push(currentNode);
		currentNode = currentNode->next;
	}
	currentNode = ptr;
	while(!auxSpace.empty() && currentNode != NULL){
		if(auxSpace.top()->value != currentNode->value){
			return false;
		}
		auxSpace.pop();
		currentNode = currentNode->next;
	}
	return true;
}

#endif /* CHECKPALINDROMESINGLYLL_H_ */

/************************************************* End code *******************************************************/
