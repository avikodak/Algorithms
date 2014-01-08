/***************************************************************************************************************** 
 *  File Name   		: FindFourElementsForGivenSum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\FindFourElementsForGivenSum.h
 *  Created on			: Jan 8, 2014 :: 2:20:27 PM
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

#ifndef FINDFOURELEMENTSFORGIVENSUM_H_
#define FINDFOURELEMENTSFORGIVENSUM_H_

int *findFourElementsForGivenSumON4(vector<int> userInput,int sum){
	if(userInput.size() < 4){
		return NULL;
	}
	unsigned int firstCrawler,secondCrawler,thirdCrawler,fourthCrawler;
	for(firstCrawler = 0;firstCrawler < userInput.size()-3;firstCrawler++){
		for(secondCrawler = firstCrawler+1;secondCrawler < userInput.size()-2;secondCrawler++){
			for(thirdCrawler = secondCrawler +1;thirdCrawler < userInput.size()-1;thirdCrawler++){
				for(fourthCrawler = thirdCrawler+1;fourthCrawler < userInput.size();fourthCrawler++){
					if(userInput[firstCrawler] + userInput[secondCrawler] + userInput[thirdCrawler] + userInput[fourthCrawler] == sum){
						int result[4];
						result[0] = userInput[firstCrawler];
						result[1] = userInput[secondCrawler];
						result[2] = userInput[thirdCrawler];
						result[3] = userInput[fourthCrawler];
						return result;
					}
				}
			}
		}
	}
	return NULL;
}

int *findFourElementsForGivenSumON3(vector<int> userInput,int sum){
	if(userInput.size() < 4){
		return NULL;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler,rearCrawler;
	int currentSum;
	for(unsigned int firstCrawler = 0;firstCrawler < userInput.size()-3;firstCrawler++){
		for(unsigned int secondCrawler = firstCrawler+1;secondCrawler < userInput.size()-2;secondCrawler++){
			frontCrawler = secondCrawler+1;
			rearCrawler = userInput.size()-1;
			currentSum = userInput[frontCrawler] + userInput[rearCrawler];
			while(frontCrawler < rearCrawler){
				if(currentSum + userInput[frontCrawler] + userInput[rearCrawler] == sum){
					int result[4];
					result[0] = userInput[firstCrawler];
					result[1] = userInput[secondCrawler];
					result[2] = userInput[frontCrawler];
					result[3] = userInput[rearCrawler];
					return result;
				}else{
					if(currentSum+userInput[frontCrawler]+userInput[rearCrawler] > sum){
						frontCrawler++;
					}else{
						rearCrawler--;
					}
				}
			}
		}
	}
}

struct pair{
	int sum;
	unsigned int firstIndex;
	unsigned int secondIndex;
};


bool sortFunc(pair firstPair,pair secondPair){
	return firstPair.sum < secondPair.sum?true:false;
}

bool noCommon(pair firstPair,pair secondPair){
	if(firstPair.firstIndex == secondPair.firstIndex || firstPair.firstIndex == secondPair.secondIndex || firstPair.secondIndex == secondPair.firstIndex || firstPair.secondIndex == secondPair.secondIndex){
		return false;
	}else{
		return true;
	}
}

int *findFourElementsForGivenSum(vector<int> userInput,int sum){
	if(userInput.size() < 4){
		return NULL;
	}
	vector<pair> allPairsSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			pair newPair = new pair();
			newPair.sum = userInput[outerCrawler] + userInput[innerCrawler];
			newPair.firstIndex = outerCrawler;
			newPair.secondIndex = innerCrawler;
			allPairsSum.push_back(newPair);
		}
	}
	sort(allPairsSum.begin(),allPairsSum.end());
	unsigned int frontCrawler = 0,rearCrawler = allPairsSum.size()-1;
	int currentSum;
	while(frontCrawler < rearCrawler){
		currentSum = allPairsSum[frontCrawler].sum + allPairsSum[rearCrawler].sum;
		if(noCommon(allPairsSum[frontCrawler],allPairsSum[rearCrawler]) && currentSum == sum){
			int result[4];
			result[0] = allPairsSum[frontCrawler].firstIndex;
			result[1] = allPairsSum[frontCrawler].secondIndex;
			result[2] = allPairsSum[rearCrawler].firstIndex;
			result[3] = allPairsSum[rearCrawler].secondIndex;
			return result;
		}
		if(currentSum < sum){
			frontCrawler++;
		}else{
			rearCrawler--;
		}
	}
}
#endif /* FINDFOURELEMENTSFORGIVENSUM_H_ */

/************************************************* End code *******************************************************/
