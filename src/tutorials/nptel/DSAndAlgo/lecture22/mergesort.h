/***************************************************************************************************************** 
 *  File Name   		: mergesort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture22\mergesort.h
 *  Created on			: Jan 15, 2014 :: 2:01:45 AM
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

#ifndef MERGESORT_H_
#define MERGESORT_H_

void mergeStep(vector<int> userInput,unsigned int startIndex,unsigned int middleIndex,unsigned int endIndex){
	if(startIndex > middleIndex && middleIndex+1 > endIndex){
		return;
	}
	vector<int> auxSpace(userInput.size());
	unsigned int firstArrayStartIndex = startIndex,secondArrayStartIndex = middleIndex+1;
	while(firstArrayStartIndex <= middleIndex && secondArrayStartIndex <= endIndex){
		if(userInput[firstArrayStartIndex] < userInput[secondArrayStartIndex]){
			auxSpace[firstArrayStartIndex] = userInput[firstArrayStartIndex];
			firstArrayStartIndex++;
		}else{
			auxSpace[secondArrayStartIndex] = userInput[secondArrayStartIndex];
			secondArrayStartIndex++;
		}
	}
	while(firstArrayStartIndex <= middleIndex){
		auxSpace[firstArrayStartIndex] = userInput[firstArrayStartIndex];
	}
	while(secondArrayStartIndex <= endIndex){
		auxSpace[secondArrayStartIndex] = userInput[secondArrayStartIndex];
	}
	for(unsigned int counter = startIndex;counter <= endIndex;counter++){
		userInput[counter] = auxSpace[counter];
	}
}

void mergeSort(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex || endIndex - startIndex == 0){
		return;
	}
	if(endIndex - startIndex == 1){
		swap(userInput[startIndex],userInput[endIndex]);
		return;
	}
	unsigned int middleIndex  = (startIndex + endIndex)/2;
	mergeSort(userInput,startIndex,middleIndex);
	mergeSort(userInput,middleIndex+1,endIndex);
	mergeStep(userInput,startIndex,middleIndex,endIndex);
}

#endif /* MERGESORT_H_ */

/************************************************* End code *******************************************************/
