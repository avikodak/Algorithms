/***************************************************************************************************************** 
 *  File Name   		: deletefromheap.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture22\deletefromheap.h
 *  Created on			: Jan 15, 2014 :: 12:59:36 AM
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

#ifndef DELETEFROMHEAP_H_
#define DELETEFROMHEAP_H_

unsigned int minIndexChildren(vector<int> userInput,unsigned int index){
	unsigned int leftChildIndex = 2*index + 1,rightChildIndex = 2*index + 2;
	if(leftChildIndex <= userInput.size() && rightChildIndex <= userInput.size()){
		return userInput[leftChildIndex] < userInput[rightChildIndex]?leftChildIndex:rightChildIndex;
	}else{
		if(leftChildIndex <= userInput.size()){
			return leftChildIndex;
		}
		if(rightChildIndex <= userInput.size()){
			return rightChildIndex;
		}
	}
	return index;
}

void heapify(vector<int> userInput,unsigned int index,unsigned int maxIndex = UINT_MAX){
	if(maxIndex == UINT_MAX){
		maxIndex = userInput.size();
	}
	if(index > maxIndex){
		return;
	}
	unsigned int minIndex;
	while(index < maxIndex){
		minIndex = minIndexChildren(userInput,index);
		if(minIndex != index){
			swap(userInput[minIndex],userInput[index]);
		}else{
			break;
		}
		index = minIndex;
	}
}

int deleteMinFromHeap(vector<int> userInput,unsigned int maxIndex = UINT_MAX){
	if(maxIndex == UINT_MAX){
		maxIndex = userInput.size();
	}
	if(maxIndex == 0){
		return INT_MIN;
	}
	int minValue;
	minValue = userInput[0];
	if(maxIndex == 1){
		userInput.clear();
		return minValue;
	}
	userInput[0] = userInput[userInput.size()-1];
	userInput.erase(userInput.begin()+userInput.size()-1);
	heapify(userInput,0,maxIndex);
	return minValue;
}

void convertIntoHeap(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	for(unsigned int counter = userInput.size()-1;counter >= 0;counter--){
		heapify(userInput,counter);
	}
}

void heapSort(vector<int> userInput){
	convertIntoHeap(userInput);
	int minValue;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		minValue = deleteMinFromHeap(userInput,userInput.size()-1-counter);
		userInput[userInput.size()-1-counter] = minValue;
	}
	reverse(userInput.begin(),userInput.end());
}
#endif /* DELETEFROMHEAP_H_ */

/************************************************* End code *******************************************************/
