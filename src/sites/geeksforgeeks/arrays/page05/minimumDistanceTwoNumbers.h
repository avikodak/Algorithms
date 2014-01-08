/***************************************************************************************************************** 
 *  File Name   		: minimumDistanceTwoNumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\minimumDistanceTwoNumbers.h
 *  Created on			: Jan 8, 2014 :: 1:44:45 AM
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

#ifndef MINIMUMDISTANCETWONUMBERS_H_
#define MINIMUMDISTANCETWONUMBERS_H_

unsigned int minimumDistanceTwoNumbersON2(vector<int> userInput,int firstNumber,int secondNumber){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int minDistance = UINT_MAX;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if(userInput[outerCounter] == firstNumber || userInput[firstNumber] == secondNumber){
			for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
				if(userInput[innerCounter] == (userInput[outerCounter] ^ firstNumber ^ secondNumber)){
					minDistance = min(minDistance,innerCounter - outerCounter);
				}
			}
		}
	}
	return minDistance;
}

unsigned int minimumDistanceTwoNumberON(vector<int> userInput,int firstNumber,int secondNumber){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int minDistance = UINT_MAX;
	unsigned int prevIndex = -1;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == firstNumber || userInput[counter] == secondNumber){
			if(prevIndex == -1){
				prevIndex = counter;
			}else{
				if(userInput[prevIndex] == userInput[counter]){
					prevIndex = counter;
				}else{
					minDistance = min(minDistance,counter - prevIndex);
					prevIndex = counter;
				}
			}
		}
	}
	return minDistance;
}

#endif /* MINIMUMDISTANCETWONUMBERS_H_ */

/************************************************* End code *******************************************************/
