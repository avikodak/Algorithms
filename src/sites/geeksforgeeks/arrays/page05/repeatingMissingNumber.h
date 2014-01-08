/*****************************************************************************************************************
 *  File Name   		: repeatingMissingNumber.h
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\repeatingMissingNumber.h
 *  Created on			: Jan 7, 2014 :: 12:18:09 PM
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

#ifndef REPEATINGMISSINGNUMBER_H_
#define REPEATINGMISSINGNUMBER_H_

int *repeatingMissingNumberON2(vector<int> userInput){
	if(userInput.size() == 0){
		return NULL;
	}
	int result[2];
	unsigned int frequency;
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		frequency = 0;
		for(unsigned int arrayCounter = 0;arrayCounter < userInput.size();arrayCounter++){
			if(userInput[arrayCounter] == counter){
				frequency++;
			}
		}
		if(frequency == 2){
			result[0] = counter;
		}
		if(frequency == 0){
			result[1] = counter;
		}
	}
	return result;
}

int *repeatingMissingNumberONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return NULL;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	int result[2];
	if(userInput[0] != 1){
		result[1] = 1;
	}
	while(counter+1 < userInput.size()){
		if(userInput[counter] == userInput[counter+1]){
			result[0] = userInput[counter];
		}
		if(userInput[counter+1] - userInput[counter] > 1){
			result[1] = userInput[counter] + 1;
		}
	}
	return result;
}

int *repeatingMissingNumberHashmapON(vector<int> userInput){
	if(userInput.size() == 0){
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
	int result[2];
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find()) != frequencyMap.end()){
			if(itToFrequencyMap->second > 1){
				result[1] = counter;
			}
		}else{
			result[0] = counter;
		}
	}
	return result;
}

int *repeatingMissingNumberSumProduct(vector<int> userInput){
	if(userInput.size() == 0){
		return NULL;
	}
	unsigned int requiredSum = 0,requiredProduct = 1;
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		requiredSum += counter;
		requiredProduct *= counter;
	}
	unsigned int arraySum = 0,arrayProduct = 1;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		arraySum += userInput[counter];
		arrayProduct *= userInput[counter];
	}
}

int *repeatingMissingNumberArrayFlags(vector<int> userInput){
	if(userInput.size() == 0){
		return NULL;
	}
	int result[2];
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[userInput[counter]] < 0){
			result[1] = userInput[counter];
		}else{
			userInput[userInput[counter]] *= -1;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			result[0] = counter;
		}
	}
	return result;
}

int *repeatingMissingNumberXOR(vector<int> userInput){
	if(userInput.size() == 0){
		return NULL;
	}
	unsigned int xorResult;
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		xorResult ^= counter;
		xorResult ^= userInput[counter-1];
	}

	unsigned int setBit = xorResult & ~(xorResult - 1);
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int result[2];
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] & setBit){
			result[0] ^= userInput[counter];
		}else{
			result[1] ^= userInput[counter];
		}
		if(counter & setBit){
			result[0] ^= counter;
		}else{
			result[1] ^= counter;
		}
	}
	return result;
}

#endif /* REPEATINGMISSINGNUMBER_H_ */

/************************************************* End code *******************************************************/
