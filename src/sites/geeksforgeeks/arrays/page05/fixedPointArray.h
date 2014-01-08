/***************************************************************************************************************** 
 *  File Name   		: fixedPointArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\fixedPointArray.h
 *  Created on			: Jan 7, 2014 :: 12:19:20 PM
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

#ifndef FIXEDPOINTARRAY_H_
#define FIXEDPOINTARRAY_H_

unsigned int fixedPointArrayNaive(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == counter){
			return counter;
		}
	}
	return UINT_MAX;
}

unsigned int fixedPointArrayBinarySearch(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == middleIndex){
		return middleIndex;
	}else{
		if(userInput[middleIndex] > middleIndex){
			return fixedPointArrayBinarySearch(userInput,startIndex,middleIndex-1);
		}else{
			return fixedPointArrayBinarySearch(userInput,middleIndex+1,endIndex);
		}
	}
}
#endif /* FIXEDPOINTARRAY_H_ */

/************************************************* End code *******************************************************/
