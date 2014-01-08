/***************************************************************************************************************** 
 *  File Name   		: maximumDifferenceTwoElements.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\maximumDifferenceTwoElements.h
 *  Created on			: Jan 6, 2014 :: 12:02:27 AM
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

#ifndef MAXIMUMDIFFERENCETWOELEMENTS_H_
#define MAXIMUMDIFFERENCETWOELEMENTS_H_

int maxDifferenceTwoValuesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(userInput.size() == 1){
		return userInput[0];
	}
	unsigned int outerCounter,innerCounter;
	int maxDifference = INT_MIN,difference;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			difference = userInput[innerCounter] - userInput[outerCounter];
			if(difference > maxDifference){
				maxDifference = difference;
			}
		}
	}
	return maxDifference;
}

int maxDifferenceTwoValueON(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(userInput.size() == 1){
		return userInput[0];
	}
	int maxDifference = INT_MIN,minValue = userInput[0],difference;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		difference = userInput[counter] - minValue;
		if(difference > maxDifference){
			maxDifference = difference;
		}
		if(minValue > userInput[counter]){
			minValue = userInput[counter];
		}
	}
	return maxDifference;
}

int maxDifferenceTwoValueONSumSubArray(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	vector<int> differenceAuxSpace;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		differenceAuxSpace.push_back(userInput[counter] - userInput[counter-1]);
	}
	int maxSum = INT_MIN;
	int currentSum = userInput[0];
	for(unsigned int counter = 1;counter < differenceAuxSpace.size();counter++){
		currentSum += userInput[counter];
		if(currentSum > 0){
			if(currentSum > maxSum){
				maxSum = currentSum;
			}
		}else{
			currentSum = min(userInput[counter],currentSum);
		}
	}
	return maxSum;
}

#endif /* MAXIMUMDIFFERENCETWOELEMENTS_H_ */

/************************************************* End code *******************************************************/
