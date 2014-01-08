/***************************************************************************************************************** 
 *  File Name   		: checkIfArrayElementsAreConsecutive.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\checkIfArrayElementsAreConsecutive.h
 *  Created on			: Jan 6, 2014 :: 10:59:58 PM
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

#ifndef CHECKIFARRAYELEMENTSARECONSECUTIVE_H_
#define CHECKIFARRAYELEMENTSARECONSECUTIVE_H_

bool areArrayElementsConsecutive(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return true;
	}
	int minValue = min_element(userInput.begin(),userInput.end());
	bool isFound;
	for(unsigned int outerCounter = minValue;outerCounter < userInput.size() + minValue;outerCounter++){
		isFound = false;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(userInput[counter] == outerCounter){
				isFound = true;
				break;
			}
		}
		if(!isFound){
			return false;
		}
	}
	return true;
}

bool areArrayElementConsecutiveSorting(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return true;
	}
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(userInput[counter+1] - userInput[counter] == 1){
			return false;
		}
	}
	return true;
}

bool areArrayElementsConsecutiveSum(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return true;
	}
	int minValue = min_element(userInput.begin(),userInput.end());
	int maxValue = max_element(userInput.begin(),userInput.end());
	if(maxValue - minValue != userInput.size()){
		return false;
	}
	int sum = (userInput.size()/2)(minValue + maxValue);
	int sumArray;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sumArray += userInput[counter];
	}
	return sum == sumArray?true:false;
}

bool areElementsConsecutiveVisitedArray(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return true;
	}
	int minValue = min_element(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < 0){
			return false;
		}
		userInput[userInput[counter] - minValue] *= -1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			return false;
		}
	}
	return true;
}
#endif /* CHECKIFARRAYELEMENTSARECONSECUTIVE_H_ */

/************************************************* End code *******************************************************/
