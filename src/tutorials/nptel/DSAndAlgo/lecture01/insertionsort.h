/***************************************************************************************************************** 
 *  File Name   		: insertionsort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture01\insertionsort.h
 *  Created on			: Dec 28, 2013 :: 1:43:44 AM
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

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

void insertionSortIterative(vector<int> &userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	unsigned int outerCounter,innerCounter;
	int temp;
	for(outerCounter = 2;outerCounter < userInput.size();outerCounter++){
		for(innerCounter = outerCounter-1;innerCounter >= 0;innerCounter--){
			if(userInput[innerCounter] > userInput[innerCounter+1]){
				temp = userInput[innerCounter];
				userInput[innerCounter] = userInput[innerCounter+1];
				userInput[innerCounter+1] = temp;
			}else{
				break;
			}
		}
	}
}

void insertionSort(vector<int> &userInput,unsigned int currentIndex){
	if(userInput.size() == 0 || userInput.size() == 1 || currentIndex >= userInput.size()){
		return;
	}
	int tempForSwap;
	for(unsigned int counter = currentIndex-1;counter >= 0;counter--){
		if(userInput[counter] > userInput[counter+1]){
			tempForSwap = userInput[counter];
			userInput[counter] = userInput[counter+1];
			userInput[counter+1] = tempForSwap;
		}else{
			break;
		}
	}
	insertionSort(userInput,currentIndex+1);
}

#endif /* INSERTIONSORT_H_ */

/************************************************* End code *******************************************************/
