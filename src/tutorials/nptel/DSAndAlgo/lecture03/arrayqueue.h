/***************************************************************************************************************** 
 *  File Name   		: arrayqueue.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture03\arrayqueue.h
 *  Created on			: Dec 29, 2013 :: 7:07:17 PM
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
#define SIZE_OF_QUEUE 30
/************************************************* Main code  ******************************************************/

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

int queue[SIZE_OF_QUEUE];
unsigned int front = -1;
unsigned int rear = 0;

bool isQueueEmpty(){

}

bool isQueueFull(){

}

void enqueue(int userInput){
	if(isQueueFull()){
		printf("Queue is full\n");
		return;
	}
	queue[rear] = userInput;
	rear = (rear+1)%SIZE_OF_QUEUE;
}

void deque(){
	if(isQueueEmpty()){
		printf("Queue is empty\n");
		return;
	}
	queue[front++] = 0;
}

unsigned int sizeOfQueue(){
	return SIZE_OF_QUEUE - front + rear;
}

int front(){
	if(isQueueEmpty()){
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return queue[front];
}
#endif /* ARRAYQUEUE_H_ */
/************************************************* End code *******************************************************/
