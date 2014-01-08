/***************************************************************************************************************** 
 *  File Name   		: twoSmallerElementsInArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\twoSmallerElementsInArray.h
 *  Created on			: Jan 5, 2014 :: 11:45:12 PM
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

#ifndef TWOSMALLERELEMENTSINARRAY_H_
#define TWOSMALLERELEMENTSINARRAY_H_

int *twoSmallestElementsInArrayON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return NULL;
	}
	unsigned int outerCounter,innerCounter;
	int twoSmallerValues[2] = {INT_MAX};
	bool isSmallest;

	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		isSmallest = true;
		for(innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				isSmallest = false;
			}
		}
		if(isSmallest){
			twoSmallerValues[0] = userInput[outerCounter];
			break;
		}
	}

	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if(userInput[outerCounter] == twoSmallerValues[0]){
			continue;
		}
		isSmallest = true;
		for(innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] == twoSmallerValues[0]){
				continue;
			}
			if(userInput[outerCounter] > userInput[innerCounter]){
				isSmallest = false;
			}
		}
		if(isSmallest){
			twoSmallerValues[1] = userInput[outerCounter];
			break;
		}
	}
	return twoSmallerValues;
}

int *twoSmallestElementsInArrayONLOGN(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return NULL;
	}
	sort(userInput.begin(),userInput.end());
	int twoSmallerValues[2];
	twoSmallerValues[0] = userInput[0];
	twoSmallerValues[1] = userInput[1];
	return twoSmallerValues;
}

int *twoSmallestElementInArrayON(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return NULL;
	}
	int twoSmallerValues[2] = {INT_MAX};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter]<twoSmallerValues[0]){
			twoSmallerValues[1] = twoSmallerValues[0];
			twoSmallerValues[0] = userInput[counter];
		}else{
			if(userInput[counter] < twoSmallerValues[1]){
				twoSmallerValues[1] = userInput[counter];
			}
		}
	}
	return twoSmallerValues;
}

int *twoSmallestElementInArrayO2N(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
			return NULL;
		}
	int twoSmallerValues[2] = {INT_MAX};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < twoSmallerValues[0]){
			twoSmallerValues[0] = userInput[counter];
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == twoSmallerValues[0]){
			continue;
		}
		if(userInput[counter] < twoSmallerValues[1]){
			twoSmallerValues[1] = userInput[counter];
		}
	}
	return twoSmallerValues;
}

int *twoSmallestElementsInArrayDivideAndConquer(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return NULL;
	}
	int twoSmallestElements[2];
	if(startIndex == endIndex){
		twoSmallestElements[0] = userInput[startIndex];
		twoSmallestElements[1] = INT_MAX;
		return twoSmallestElements;
	}
	if(startIndex - endIndex == 1){
		twoSmallestElements[0] = min(userInput[startIndex],userInput[endIndex]);
		twoSmallestElements[1] = twoSmallestElements[0] ^ userInput[startIndex] ^ userInput[endIndex];
		return twoSmallestElements;
	}
	int middleElement = (startIndex + endIndex)/2;
	int *leftResult = twoSmallestElementsInArrayDivideAndConquer(userInput,startIndex,middleElement);
	int *rightResult = twoSmallestElementsInArrayDivideAndConquer(userInput,middleElement+1,endIndex);
	if(leftResult[0] < rightResult[0]){
		twoSmallestElements[0] = leftResult[0];
		twoSmallestElements[1] = min(leftResult[1],rightResult[0]);
	}else{
		twoSmallestElements[0] = rightResult[0];
		twoSmallestElements[1] = min(leftResult[0],rightResult[1]);
	}
	return twoSmallestElements;
}
#endif /* TWOSMALLERELEMENTSINARRAY_H_ */

/************************************************* End code *******************************************************/
