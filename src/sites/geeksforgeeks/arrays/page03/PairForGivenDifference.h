/***************************************************************************************************************** 
 *  File Name   		: PairForGivenDifference.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\PairForGivenDifference.h
 *  Created on			: Jan 8, 2014 :: 2:18:03 PM
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

#ifndef PAIRFORGIVENDIFFERENCE_H_
#define PAIRFORGIVENDIFFERENCE_H_

int *pairForGivenDifferenceON2(vector<int> userInput,int diffValue){
	if(userInput.size() == 0 || userInput.size() == 1){
		return NULL;
	}
	int currentDifference;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = 0;innerCrawler <userInput.size();innerCrawler++){
			if(abs(diffValue) == abs(userInput[innerCrawler] - userInput[outerCrawler])){
				int result[2];
				result[0] = userInput[outerCrawler];
				result[1] = userInput[innerCrawler];
				return result;
			}
		}
	}
	return NULL;
}

int *pairForGivenDifferenceONLOGN(vector<int> userInput,int diffValue){
	if(userInput.size() == 0 || userInput.size() == 1){
		return NULL;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	while(frontCrawler < rearCrawler){
		if(abs(diffValue) == abs(userInput[frontCrawler] - userInput[rearCrawler])){
			int result[2];
			result[0] = userInput[frontCrawler];
			result[1] = userInput[rearCrawler];
			return result;
		}else{
			if(diffValue > userInput[frontCrawler]){
				frontCrawler++;
			}else{
				rearCrawler--;
			}
		}
	}
	return NULL;
}

int *pairForGivenDifferenceON(vector<int> userInput,int diffValue){
	if(userInput.size() == 0 || userInput.size() == 1){
		return NULL;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(abs(diffValue - userInput[counter]))) != frequencyMap.end()){
			int result[2];
			result[0] = userInput[counter];
			result[1] = itToFrequencyMap->first;
			return result;
		}
	}
}

#endif /* PAIRFORGIVENDIFFERENCE_H_ */

/************************************************* End code *******************************************************/
