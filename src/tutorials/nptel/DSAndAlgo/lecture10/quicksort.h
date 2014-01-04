/***************************************************************************************************************** 
 *  File Name   		: quicksort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture10\quicksort.h
 *  Created on			: Dec 31, 2013 :: 12:49:24 PM
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

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

unsigned int divideQuickSortStep(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	int key = userInput[endIndex],tempForSwap;
	while(startIndex < endIndex){
		while(userInput[startIndex] >= key){
			startIndex++;
		}
		while(userInput[endIndex] <= key && startIndex < endIndex){ // actually there is no need to check startIndex < endIndex condition
			endIndex--;
		}
		if(startIndex < endIndex){
			tempForSwap = userInput[startIndex];
			userInput[startIndex] = userInput[endIndex];
			userInput[endIndex] = tempForSwap;
		}
	}
	return endIndex;
}

void quickSort(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return;
	}
	int dividingIndex = divideQuickSortStep(userInput,startIndex,endIndex);
	quickSort(userInput,startIndex,dividingIndex);
	quickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* QUICKSORT_H_ */
/************************************************* End code *******************************************************/
