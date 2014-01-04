/***************************************************************************************************************** 
 *  File Name   		: largestSumContigousSubarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\largestSumContigousSubarray.h
 *  Created on			: Jan 3, 2014 :: 1:53:06 PM
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

#ifndef LARGESTSUMCONTIGOUSSUBARRAY_H_
#define LARGESTSUMCONTIGOUSSUBARRAY_H_

int largestSumContigousSubArrayON3(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCounter,innerCounter,counter,startIndex,endIndex;
	int currentSum,sumMax = INT_MIN;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			currentSum = 0;
			for(counter = outerCounter;counter <= innerCounter;counter++){
				currentSum += userInput[counter];
			}
			if(sumMax < currentSum){
				sumMax = currentSum;
				startIndex = outerCounter;
				endIndex = innerCounter;
			}
		}
	}
	return sumMax;
}

int largestSumContigousSubArrayON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler;
	unsigned int startIndex,endIndex;
	int currentSum,sumMax = INT_MIN;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		currentSum = 0;
		for(innerCrawler=outerCrawler;outerCrawler < userInput.size();innerCrawler++){
			currentSum += userInput[innerCrawler];
			if(sumMax < currentSum){
				sumMax = currentSum;
				startIndex = outerCrawler;
				endIndex = innerCrawler;
			}
		}
	}
	return INT_MIN;
}

/*
 * doesn't handle the case when the array has all negative numbers
 */
int largestSumContigousSubArrayKadane(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned startIndex = UINT_MAX,endIndex;
	int sumMax = INT_MIN,currentSum=0;
	for(unsigned int counter = 0;counter<userInput.size();counter++){
		currentSum += userInput[counter];
		if(currentSum < 0){
			currentSum = 0;
		}else{
			if(currentSum > sumMax){
				sumMax = currentSum;
				endIndex = counter;
			}
		}
	}
}

int largestSumContigousSubArrayON(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int sumMax = INT_MIN,currentSum =0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		currentSum += userInput[counter];
		if(currentSum < 0){
			currentSum = max(userInput[counter],currentSum+userInput[counter]);
		}else{
			if(sumMax < currentSum){
				sumMax = currentSum;
			}
		}
	}
	return sumMax;
}

#endif /* LARGESTSUMCONTIGOUSSUBARRAY_H_ */

/************************************************* End code *******************************************************/
