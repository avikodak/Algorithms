/***************************************************************************************************************** 
 *  File Name   		: FindRowWithMaximumNumberOf1s.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\FindRowWithMaximumNumberOf1s.h
 *  Created on			: Jan 8, 2014 :: 2:22:57 PM
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

#ifndef FINDROWWITHMAXIMUMNUMBEROF1S_H_
#define FINDROWWITHMAXIMUMNUMBEROF1S_H_

unsigned int findRowWithMaxNumber1sNaive(vector<vector<bool> > userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	unsigned int maxRowIndex;
	unsigned int maxOnes = 0,countOnes;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		countOnes = 0;
		for(unsigned int innerCounter = 0;innerCounter < userInput[0].size();innerCounter++){
			if(userInput[outerCounter][innerCounter]){
				countOnes++;
			}
		}
		if(maxOnes < countOnes){
			maxOnes = countOnes;
			maxRowIndex = outerCounter;
		}
	}
	return maxRowIndex;
}

unsigned int findCeilIndexForTrue(vector<bool> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex]){
		if(middleIndex-1>startIndex){
			return findCeilIndexForTrue(userInput,startIndex,middleIndex-1);
		}
		return middleIndex;
	}else{
		return findCeilIndexForTrue(userInput,middleIndex+1,endIndex);
	}
}

unsigned int findRowWithMaxNumber1sBinarySearch(vector<vector<bool> > userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	unsigned int maxOnesRow,minOneIndex,temp;
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		if(userInput[rowCounter]){
			temp = findCeilIndexForTrue(userInput[rowCounter],0,userInput[0].size());
			if(temp != UINT_MAX){
				if(temp == 0){
					return rowCounter;
				}
				if(minOneIndex > temp){
					minOneIndex = temp;
					maxOnesRow = rowCounter;
				}
			}
		}
	}
	return maxOnesRow;
}

#endif /* FINDROWWITHMAXIMUMNUMBEROF1S_H_ */

/************************************************* End code *******************************************************/
