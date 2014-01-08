/***************************************************************************************************************** 
 *  File Name   		: maximumOfSubArraySizeK.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\maximumOfSubArraySizeK.h
 *  Created on			: Jan 8, 2014 :: 2:02:58 AM
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

#ifndef MAXIMUMOFSUBARRAYSIZEK_H_
#define MAXIMUMOFSUBARRAYSIZEK_H_

vector<int> maximumSubArraySizeK(vector<int> userInput,unsigned int kValue){
	if(userInput.size() == 0){
		return userInput;
	}
	vector<int> maxValuesSubArrayK;
	unsigned int outerCounter = 0,innerCounter = 0;
	int maxValue;
	for(outerCounter= 0;outerCounter < userInput.size() - kValue;outerCounter++){
		maxValue = INT_MIN;
		for(innerCounter = outerCounter;innerCounter < outerCounter + kValue;innerCounter++){
			if(maxValue < userInput[innerCounter]){
				maxValue = userInput[innerCounter];
			}
		}
		maxValuesSubArrayK.push_back(maxValue);
	}
	return maxValuesSubArrayK;
}

vector<int> maximumSubArraysSizeKONLOGN(vector<int> userInput,unsigned int kValue){
	if(userInput.size() == 0){
		return userInput;
	}
}

vector<int> maximumSubArraySizeKON(vector<int> userInput,unsigned int kValue){
	if(userInput.size() == 0){
		return userInput;
	}
	vector<int> maxValuesSubArrayK;
	deque<int> auxSpace;
	unsigned int counter;
	for(counter = 0;counter < kValue;counter++){

	}

	for(;counter < userInput.size();counter++){

	}
}

#endif /* MAXIMUMOFSUBARRAYSIZEK_H_ */

/************************************************* End code *******************************************************/
