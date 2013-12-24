/***************************************************************************************************************** 
 *  File Name   		: MoveLastElementToFirst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\MoveLastElementToFirst.h
 *  Created on			: Dec 21, 2013 :: 12:42:16 AM
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

#ifndef MOVELASTELEMENTTOFIRST_H_
#define MOVELASTELEMENTTOFIRST_H_

void moveLastElementToFirstIterative(llNode **ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	llNode *crawler = *ptr;
	while(crawler->next->next != NULL){
		crawler = crawler->next;
	}
	crawler->next->next = (*ptr);
	(*ptr) = crawler->next;
	crawler->next = NULL;
}

void moveLastElementToFirst(llNode *ptr,llNode **head){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	if(ptr->next->next == NULL){
		ptr->next->next = (*head);
		(*head) = ptr->next;
		ptr->next = NULL;
		return;
	}
	moveLastElementToFirst(ptr->next,head);
}

void moveLastElementToFirstDeque(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	deque<int> auxSpace;
	llNode *crawler = ptr;
	while(crawler != NULL){
		auxSpace.push_back(crawler->value);
		crawler = crawler->next;
	}
	crawler = ptr;
	crawler->value = auxSpace.back();
	auxSpace.pop_back();
	crawler = crawler->next;
	while(!auxSpace.empty()){
		crawler->value = auxSpace.front();
		auxSpace.pop_front();
		crawler = crawler->next;
	}
}
#endif /* MOVELASTELEMENTTOFIRST_H_ */

/************************************************* End code *******************************************************/
