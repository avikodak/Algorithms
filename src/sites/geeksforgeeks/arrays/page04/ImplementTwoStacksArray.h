/***************************************************************************************************************** 
 *  File Name   		: ImplementTwoStacksArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\ImplementTwoStacksArray.h
 *  Created on			: Jan 8, 2014 :: 1:10:04 PM
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
#define MAX_SIZE 20

/************************************************* Main code  ******************************************************/

#ifndef IMPLEMENTTWOSTACKSARRAY_H_
#define IMPLEMENTTWOSTACKSARRAY_H_

int stackOneTop=-1,stackTwoTop = MAX_SIZE;
int userInput[MAX_SIZE];

void push(int userInput,bool firstStack){
	if(abs(stackOneTop - stackTwoTop) == 1){
		printf("Stack is full\n");
		return;
	}
	if(firstStack){
		userInput[++stackOneTop] = userInput;
	}else{
		userInput[--stackTwoTop] = userInput;
	}
}

void pop(bool firstStack){
	if(firstStack){
		if(stackOneTop == -1){
			printf("Stack is empty\n");
			return;
		}
		userInput[stackOneTop--] = 0;
	}else{
		if(stackTwoTop == MAX_SIZE){
			printf("Stack is empty\n");
			return;
		}
		userInput[stackTwoTop++] = 0;
	}
}

bool empty(bool firstStack){
	if(firstStack){
		return stackOneTop == -1?true:false;
	}else{
		return stackTwoTop == INT_MAX?true:false;
	}
}

int front(bool firstStack){
	if(firstStack){
		if(empty(true)){
			printf("Stack is empty\n");
			return;
		}else{
			return userInput[stackOneTop];
		}
	}else{
		if(empty(false)){
			printf("Stack is empty\n");
			return;
		}else{
			return userInput[stackTwoTop];
		}
	}
}

unsigned int size(bool firstStack){
	if(firstStack){
		return stackOneTop + 1;
	}else{
		return MAX_SIZE - stackTwoTop;
	}
}

#endif /* IMPLEMENTTWOSTACKSARRAY_H_ */

/************************************************* End code *******************************************************/
