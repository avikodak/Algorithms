/***************************************************************************************************************** 
 *  File Name   		: FindSortedSubsequenceSize3.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\FindSortedSubsequenceSize3.h
 *  Created on			: Jan 8, 2014 :: 1:13:32 PM
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

#ifndef FINDSORTEDSUBSEQUENCESIZE3_H_
#define FINDSORTEDSUBSEQUENCESIZE3_H_

int *findSortedSubSequenceSize3(vector<int> userInput){
	if(userInput.size() < 2){
		return NULL;
	}
	unsigned int firstCrawler,secondCrawler,thirdCrawler;
	for(firstCrawler = 0;firstCrawler < userInput.size()-2;firstCrawler++){
		for(secondCrawler = firstCrawler+1;secondCrawler < userInput.size()-1;secondCrawler++){
			for(thirdCrawler = secondCrawler+1;thirdCrawler < userInput.size();thirdCrawler++){
				if(userInput[thirdCrawler] > userInput[secondCrawler] && userInput[secondCrawler] > userInput[firstCrawler]){
					int result[3];
					result[0] = userInput[firstCrawler];
					result[1] = userInput[secondCrawler];
					result[2] = userInput[thirdCrawler];
					return result;
				}
			}
		}
	}
	return NULL;
}

int *findSortedSubSequenceON(vector<int> userInput){
	if(userInput.size() < 2){
		return NULL;
	}
	vector<int> smallElementsLeft,largeElementsRight;
	smallElementsLeft.push_back(INT_MAX);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		smallElementsLeft.push_back(min(smallElementsLeft[counter-1]),userInput[counter-1]);
	}
	largeElementsRight[userInput.size()-1] = INT_MIN;
	for(unsigned int counter = userInput.size()-2;counter >= 0;counter--){
		largeElementsRight[counter] = max(largeElementsRight[counter+1],userInput[counter+1]);
	}

	for(unsigned int counter = 1;counter < userInput.size()-1;counter++){
		if(smallElementsLeft[counter] < userInput[counter] && largeElementsRight[counter] > userInput[counter]){
			int result[3];
			result[0] = smallElementsLeft[counter];
			result[1] = userInput[counter];
			result[2] = largeElementsRight[counter];
			return result;
		}
	}
	return NULL;
}
#endif /* FINDSORTEDSUBSEQUENCESIZE3_H_ */
/************************************************* End code *******************************************************/

