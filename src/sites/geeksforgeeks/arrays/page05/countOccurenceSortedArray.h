/***************************************************************************************************************** 
 *  File Name   		: countOccurenceSortedArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\countOccurenceSortedArray.h
 *  Created on			: Jan 7, 2014 :: 11:49:48 AM
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

#ifndef COUNTOCCURENCESORTEDARRAY_H_
#define COUNTOCCURENCESORTEDARRAY_H_

unsigned int countOccurenceSortedArrayLinearSearch(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			frequency += 1;
		}
	}
	return frequency;
}

unsigned int lowerbound(vector<int> userInput,unsigned int startIndex,unsigned int endIndex,int key){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex - 1 > startIndex){
			return middleIndex;
		}else{
			if(userInput[middleIndex-1] != key){
				return middleIndex;
			}else{
				return lowerbound(userInput,startIndex,middleIndex-1,key);
			}
		}
	}else{
		if(userInput[middleIndex] > key){
			return lowerbound(userInput,startIndex,middleIndex-1,key);
		}else{
			return lowerbound(userInput,middleIndex+1,endIndex,key);
		}
	}
}

unsigned int upperbound(vector<int> userInput,unsigned int startIndex,unsigned int endIndex,int key){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex + 1 < endIndex){
			return middleIndex;
		}else{
			if(userInput[middleIndex+1] != key){
				return middleIndex;
			}else{
				return upperbound(userInput,startIndex,middleIndex-1,key);
			}
		}
	}else{
		if(userInput[middleIndex] > key){
			return upperbound(userInput,startIndex,middleIndex-1,key);
		}else{
			return upperbound(userInput,middleIndex+1,endIndex,key);
		}
	}
}

unsigned int countOccurenceSortedArrayBinarySearch(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int lowerBoundIndex = lowerbound(userInput,0,userInput.size()-1,key);
	unsigned int upperBoundIndex = upperbound(userInput,0,userInput.size()-1,key);
	return upperBoundIndex - lowerBoundIndex + 1;
}

unsigned int countOccurenceCPPSTL(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int lowerIndex = lower_bound(userInput.begin(),userInput.end(),key);
	unsigned int upperIndex = upper_bound(userInput.begin(),userInput.end(),key);
	return upperIndex - lowerIndex + 1;
}

#endif /* COUNTOCCURENCESORTEDARRAY_H_ */

/************************************************* End code *******************************************************/
