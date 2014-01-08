/***************************************************************************************************************** 
 *  File Name   		: countSmallerElementsInRightSide.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\countSmallerElementsInRightSide.h
 *  Created on			: Jan 7, 2014 :: 12:20:05 PM
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

#ifndef COUNTSMALLERELEMENTSINRIGHTSIDE_H_
#define COUNTSMALLERELEMENTSINRIGHTSIDE_H_

vector<int> countSmallerElementsRightSideON2(vector<int> userInput){
	if(userInput.size() == 0){
		return userInput;
	}
	vector<int> counterGreaterElements;
	unsigned int counter;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		counter = 0;
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] < userInput[outerCounter]){
				counter++;
			}
		}
		counterGreaterElements.push_back(counter);
	}
}

vector<int> countSmallerElementRightSideONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return userInput;
	}
	stack<int> auxSpace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace.push(userInput[counter]);
	}
}

#endif /* COUNTSMALLERELEMENTSINRIGHTSIDE_H_ */

/************************************************* End code *******************************************************/
