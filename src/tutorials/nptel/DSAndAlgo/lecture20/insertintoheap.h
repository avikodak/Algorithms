/***************************************************************************************************************** 
 *  File Name   		: heap.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture21\heap.h
 *  Created on			: Jan 15, 2014 :: 12:39:53 AM
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

#ifndef INSERTINTOHEAP_H_
#define INSERTINTOHEAP_H_

int min(vector<int> heap){
	if(heap.size() == 0){
		return INT_MIN;
	}
	return heap[0];
}

void insertIntoHeap(vector<int> &userInput,int inputValue){
	unsigned int newValueIndex = userInput.size();
	userInput.push_back(inputValue);
	while(newValueIndex/2 >= 0 && userInput[newValueIndex] > inputValue){
		swap(userInput[newValueIndex],userInput[newValueIndex/2]);
	}
	userInput[newValueIndex] = inputValue;
}

#endif /* INSERTINTOHEAP_H_ */

/************************************************* End code *******************************************************/
