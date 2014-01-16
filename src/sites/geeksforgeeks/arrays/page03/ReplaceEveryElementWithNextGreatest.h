/***************************************************************************************************************** 
 *  File Name   		: ReplaceEveryElementWithNextGreatest.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\ReplaceEveryElementWithNextGreatest.h
 *  Created on			: Jan 8, 2014 :: 2:18:32 PM
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

#ifndef REPLACEEVERYELEMENTWITHNEXTGREATEST_H_
#define REPLACEEVERYELEMENTWITHNEXTGREATEST_H_

/************************************** Replace with next greater than current *************************************/
void replaceEveryElementWithNextGreatestON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	int maxVal;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		maxVal = INT_MIN;
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(maxVal < userInput[innerCrawler]){
				maxVal = userInput[innerCrawler];
			}
		}
		userInput[outerCrawler] = maxVal;
	}
}

void replaceEveryElementWithGreatestON(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	stack<int> auxSpace;
	for(unsigned int counter = userInput.size()-1;counter >= 0;counter++){
		while(!auxSpace.empty() && auxSpace.top() < userInput[counter]){
			auxSpace.pop();
		}
		if(auxSpace.empty()){
			userInput[counter] = INT_MAX;
		}else{
			userInput[counter] = auxSpace.top();
		}
		auxSpace.push(userInput[counter]);
	}
}

/****************************************************************************************************************************/

void replaceNextGreatestRightSideON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	int maxElement;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		maxElement = INT_MIN;
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(maxElement < userInput[innerCounter]){
				maxElement = userInput[innerCounter];
			}
		}
		userInput[outerCounter] = maxElement;
	}
}

void replaceNextGreatestRightIterative(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	int maxValue = INT_MIN;
	for(unsigned int counter = userInput.size();counter < userInput.size();counter++){
		userInput[counter] = maxValue;
		if(maxValue < userInput[counter]){
			maxValue = userInput[counter];
		}
	}
}

int replaceNextGreatestRight(vector<int> userInput,unsigned int currentIndex){
	if(userInput.size() == 0 || userInput.size() == 1 || currentIndex >= userInput.size()){
		return INT_MIN;
	}
	int nextGreatest = replaceNextGreatestRight(userInput,currentIndex+1);
	int temp = userInput[currentIndex];
	userInput[currentIndex] = nextGreatest;
	return nextGreatest > temp?nextGreatest:temp;
}

#endif /* REPLACEEVERYELEMENTWITHNEXTGREATEST_H_ */

/************************************************* End code *******************************************************/
