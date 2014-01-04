/***************************************************************************************************************** 
 *  File Name   		: majorityElement.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\majorityElement.h
 *  Created on			: Jan 2, 2014 :: 6:02:39 PM
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

#ifndef MAJORITYELEMENT_H_
#define MAJORITYELEMENT_H_

int majorityElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler,frequency;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequency += 1;
			}
		}
		if(frequency > (userInput.size())/2){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

int majorityElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frequency;
	for(unsigned int counter =0;counter < userInput.size();){
		frequency = 1;
		while(userInput[counter] == userInput[counter+1]){
			frequency += 1;
		}
		if(frequency > (userInput.size()/2)){
			return userInput[counter];
		}
	}
	return INT_MIN;
}

int majorityBSTPreOrder(tNode *ptr){

}

int majorityElementONLOGNBST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
}

int majorityElementONHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]]++;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > userInput.size()/2){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

int majorityElementMooreVoting(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
}

#endif /* MAJORITYELEMENT_H_ */

/************************************************* End code *******************************************************/
