/***************************************************************************************************************** 
 *  File Name   		: maximumElementInArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\maximumElementInArray.h
 *  Created on			: Jan 7, 2014 :: 12:19:43 PM
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

#ifndef MAXIMUMELEMENTINARRAY_H_
#define MAXIMUMELEMENTINARRAY_H_

int maxElementIncreasingDecreasingNaive(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	int maxElement = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(maxElement < userInput[counter]){
			maxElement =  userInput[counter];
		}
	}
	return maxElement;
}

int maxElementIncreasingDecreasingBinary(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(userInput.size() == 0 || startIndex > endIndex){
		return 0;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(middleIndex + 1 < endIndex){
		if(userInput[middleIndex + 1] < userInput[middleIndex]){
			return userInput[middleIndex];
		}else{
			if(userInput[middleIndex] < userInput[middleIndex+1]){
				return maxElementIncreasingDecreasingBinary(userInput,middleIndex+1,endIndex);
			}else{
				return maxElementIncreasingDecreasingBinary(userInput,startIndex,middleIndex-1);
			}
		}
	}else{
		return userInput[middleIndex];
	}
}

#endif /* MAXIMUMELEMENTINARRAY_H_ */

/************************************************* End code *******************************************************/
