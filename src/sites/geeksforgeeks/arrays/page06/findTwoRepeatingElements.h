/***************************************************************************************************************** 
 *  File Name   		: findTwoRepeatingElements.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\findTwoRepeatingElements.h
 *  Created on			: Jan 6, 2014 :: 8:49:56 PM
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

#ifndef FINDTWOREPEATINGELEMENTS_H_
#define FINDTWOREPEATINGELEMENTS_H_

int *FindTwoRepeatingElementsON2(vector<int> userInput){
	if(userInput.size() == 0||userInput.size() == 1){
		return NULL;
	}
	unsigned int outerCounter,innerCounter;
	int twoRepeatedElements[2];
	int counter = -1;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] == userInput[innerCounter]){
				twoRepeatedElements[++counter] = userInput[outerCounter];
			}
		}
	}
	return twoRepeatedElements;
}

int *findTwoRepeatingElementsHashmap(vector<int> userInput){
	if(userInput.size() == 0||userInput.size() == 1){
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
	int twoRepeatedElements[2];
	int counter = -1;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > 1){
			twoRepeatedElements[++counter] = itToFrequencyMap->first;
		}
	}
	return twoRepeatedElements;
}

int *findTwoRepeatingElementsXOR(vector<int> userInput){
	if(userInput.size() == 0||userInput.size() == 1){
		return NULL;
	}
	int xorValue = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		xorValue ^= userInput[counter];
	}
	bitset<32> binaryRepXor(xorValue);
	unsigned int setBit;
	for(unsigned int counter = 0;counter < 32;counter++){
		if(binaryRepXor[counter]){
			setBit = counter;
			break;
		}
	}
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;
	vector<int> firstAuxspace,secondAuxspace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		bitset<32> binaryRep(userInput[counter]);
		if(binaryRep[setBit]){
			secondAuxspace.push_back(userInput[counter]);
		}else{
			firstAuxspace.push_back(userInput[counter]);
		}
	}

	xorValue = 0;
	for(unsigned int counter = 0;counter < firstAuxspace.size();counter++){
		xorValue ^= firstAuxspace[counter];
	}
	int result[2];
	result[0] = xorValue;
	for(unsigned int counter =0;counter < secondAuxspace.size();counter++){
		xorValue ^= secondAuxspace[counter];
	}
	result[1] = xorValue;
	return result;
}
#endif /* FINDTWOREPEATINGELEMENTS_H_ */

/************************************************* End code *******************************************************/
