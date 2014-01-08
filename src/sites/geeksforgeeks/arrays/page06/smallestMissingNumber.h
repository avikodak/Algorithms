/***************************************************************************************************************** 
 *  File Name   		: smallestMissingNumber.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\smallestMissingNumber.h
 *  Created on			: Jan 6, 2014 :: 10:17:50 PM
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

#ifndef SMALLESTMISSINGNUMBER_H_
#define SMALLESTMISSINGNUMBER_H_

int smallestMissingNumberON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int minValue = min_element(userInput.begin(),userInput.end());
	bool isFound;
	for(int counter = minValue;counter < minValue+userInput.size();counter++){
		isFound = false;
		for(unsigned int crawler = 0;crawler < userInput.size();crawler++){
			if(userInput[crawler] == counter){
				isFound = true;
			}
		}
		if(!isFound){
			return counter;
		}
	}
	return minValue + userInput.size();
}

int smallestMissingNumberONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size() - 1;counter++){
		if(userInput[counter+1] - userInput[counter] != 1){
			return userInput[counter] + 1;
		}
	}
	return userInput[0] + userInput.size();
}

int smallestMissingNumberBinarySearch(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == middleIndex){
		if(middleIndex+1 <= endIndex && userInput[middleIndex+1] != middleIndex+1){
			return middleIndex+1;
		}else{
			return smallestMissingNumberBinarySearch(userInput,middleIndex+1,endIndex);
		}
	}else{
		if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] == middleIndex-1){
			return middleIndex-1;
		}else{
			return smallestMissingNumberBinarySearch(userInput,startIndex,middleIndex-1);
		}
	}
}

#endif /* SMALLESTMISSINGNUMBER_H_ */

/************************************************* End code *******************************************************/
