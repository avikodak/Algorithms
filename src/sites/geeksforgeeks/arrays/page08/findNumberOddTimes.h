/***************************************************************************************************************** 
 *  File Name   		: findNumberOddTimes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\findNumberOddTimes.h
 *  Created on			: Jan 2, 2014 :: 6:36:48 PM
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

#ifndef FINDNUMBERODDTIMES_H_
#define FINDNUMBERODDTIMES_H_

int findNumberOccuringOddTimesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler,frequencyOfElement;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequencyOfElement = 1;
		for(innerCrawler = outerCrawler+1;outerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequencyOfElement += 1;
			}
		}
		if(frequencyOfElement%2 == 1){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

int findNumberOccuringOddTimesONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frequency;
	for(unsigned int counter = 0;counter < userInput.size();){
		frequency = 1;
		while(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]){
			frequency += 1;
		}
		if(frequency%2 == 1){
			return userInput[counter];
		}
		counter += frequency;
	}
	return INT_MIN;
}

int findNumberOccuringOddTimesONLOGNBST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
}

int findNumberOccuringOddTimesONHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[itToFrequencyMap->first]++;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(counter,1));
		}
	}

	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second%2 == 1){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

int findNumberOccuringOddTimesXORIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int xorresult = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		xorresult ^= userInput[counter];
	}
	return xorresult;
}

int findNumberOccuringOddTimesXOR(vector<int> userInput,unsigned int currentIndex){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(currentIndex >= userInput.size()){
		return 0;
	}
	int xorResult = findNumberOccuringOddTimesXOR(userInput,currentIndex+1);
	return xorResult^userInput[currentIndex];
}

#endif /* FINDNUMBERODDTIMES_H_ */

/************************************************* End code *******************************************************/
