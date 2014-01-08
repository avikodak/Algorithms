/***************************************************************************************************************** 
 *  File Name   		: IterativeQuickSort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\IterativeQuickSort.h
 *  Created on			: Jan 8, 2014 :: 2:24:18 PM
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

#ifndef ITERATIVEQUICKSORT_H_
#define ITERATIVEQUICKSORT_H_

unsigned int partitionIterativeQuickSort(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	int key = userInput[endIndex],temp;
	while(startIndex < endIndex){
		while(userInput[startIndex] > key){
			startIndex++;
		}
		while(userInput[endIndex] < key && startIndex < endIndex){
			endIndex--;
		}
		if(startIndex < endIndex){
			temp = userInput[startIndex];
			userInput[startIndex] = userInput[endIndex];
			userInput[endIndex] = temp;
		}
	}
	return endIndex;
}

void quicksortIterative(vector<int> userInput){
	if(startIndex > endIndex){
		return;
	}
	stack<unsigned int> indexes;
	indexes.push(0);
	indexes.push(userInput.size()-1);
	unsigned int startIndex,endIndex,partitionIndex;
	while(!indexes.empty()){
		startIndex = indexes.top();
		indexes.pop();
		endIndex = indexes.top();
		indexes.pop();
		if(startIndex >= endIndex){
			continue;
		}
		partitionIndex = partitionIterativeQuickSort(userInput,startIndex,endIndex);
		indexes.push(startIndex);
		indexes.push(partitionIndex);
		indexes.push(partitionIndex);
		indexes.push(endIndex);
	}
}

#endif /* ITERATIVEQUICKSORT_H_ */

/************************************************* End code *******************************************************/
