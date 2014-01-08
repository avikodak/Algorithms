/***************************************************************************************************************** 
 *  File Name   		: FindSubArrayForGivenSum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\FindSubArrayForGivenSum.h
 *  Created on			: Jan 8, 2014 :: 1:11:32 PM
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

#ifndef FINDSUBARRAYFORGIVENSUM_H_
#define FINDSUBARRAYFORGIVENSUM_H_

int *findSubArrayForGivenSumON2(vector<int> userInput,int sum){
	if(userInput.size()){
		return NULL;
	}
	int currentSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		currentSum = userInput[outerCrawler];
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			currentSum += userInput[innerCrawler];
			if(currentSum == sum){
				int result[2];
				result[0] = outerCrawler;
				result[1] = innerCrawler;
				return result;
			}
		}
	}
	return NULL;
}

int *findSubArrayForGivenSum(vector<int> userInput,int sum){
	if(userInput.size()){
		return NULL;
	}
	int currentSum = 0;
	unsigned int startIndex = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		currentSum += userInput[counter];
		if(currentSum == sum){
			int result[2];
			result[0] = startIndex;
			result[1] = counter;
			return result;
		}else{
			if(currentSum > sum){
				currentSum -= userInput[startIndex];
				startIndex += 1;
			}
		}
	}
	return NULL;
}

#endif /* FINDSUBARRAYFORGIVENSUM_H_ */

/************************************************* End code *******************************************************/
