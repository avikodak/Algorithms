/***************************************************************************************************************** 
 *  File Name   		: FindTwoNumbersOddOccurence.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\FindTwoNumbersOddOccurence.h
 *  Created on			: Jan 8, 2014 :: 1:15:48 PM
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

#ifndef FINDTWONUMBERSODDOCCURENCE_H_
#define FINDTWONUMBERSODDOCCURENCE_H_

int *findTwoNumbersWithOddOccurenceON2(vector<int> userInput){
	if(userInput.size() == 0){
		return  NULL;
	}
	int result[2];
	unsigned int fillCounter = 0;
	unsigned int frequency;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(innerCrawler == outerCrawler){
				continue;
			}
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequency += 1;
			}
		}
		if(frequency&1 == 1){
			if(fillCounter != 0){
				if(result[0] != userInput[outerCrawler]){
					result[fillCounter] = userInput[outerCrawler];
					break;
				}
			}else{
				result[fillCounter++] = userInput[outerCrawler];
			}
		}
	}
	return result;
}

int *findTwoNumbersWithOddOccurenceONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return  NULL;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int crawler = 0,frequency;
	int result[2],resultCrawler = -1;
	while(crawler < userInput.size()){
		frequency = 1;
		while(crawler < userInput.size() && userInput[crawler] == userInput[crawler+1]){
			frequency += 1;
		}
		if(frequency%2 == 1){
			result[++resultCrawler] = userInput[crawler];
			if(resultCrawler == 1){
				return result;
			}
		}
		crawler += frequency;
	}
	return NULL;
}

int *findTwoNumbersWithOddOccurenceONHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return  NULL;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 11;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
		}
	}
	int result[2];
	int fillCounter = -1;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second & 1 == 1){
			result[++fillCounter] = itToFrequencyMap->first;
			if(fillCounter == 1){
				break;
			}
		}
	}
	return result;
}

int *findTwoNumbersWithOddOccurenceONXOR(vector<int> userInput){
	if(userInput.size() == 0){
		return  NULL;
	}
	int xorResult = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		xorResult ^= userInput[counter];
	}
	unsigned int setBit = xorResult & ~(xorResult -1);
	int result[2] = {0};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] & setBit){
			result[0] ^= userInput[counter];
		}else{
			result[1] ^= userInput[counter];
		}
	}
	return result;
}

#endif /* FINDTWONUMBERSODDOCCURENCE_H_ */

/************************************************* End code *******************************************************/
