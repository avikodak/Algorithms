/***************************************************************************************************************** 
 *  File Name   		: sortElementsByFrequency.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\sortElementsByFrequency.h
 *  Created on			: Jan 5, 2014 :: 8:08:17 PM
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

#ifndef SORTELEMENTSBYFREQUENCY_H_
#define SORTELEMENTSBYFREQUENCY_H_

bool sortFunc(pair<int,unsigned> it1,pair<int,unsigned int> it2){
	if(it1.second != it2.second){
		return it1.second > it2.second?true:false;
	}else{
		return it1.first > it2.first?true:false;
	}
}

void sortElementsByFrequencyHashmap(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	vector<pair<int,unsigned int> > sortedFrequencyMap;
	pair<int,unsigned int> itToSortedPair;
	unsigned int count;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[itToFrequencyMap->first] += 1;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
		}
	}
	copy(frequencyMap.begin(),frequencyMap.end(),back_inserter(sortedFrequencyMap));
	sort(sortedFrequencyMap.begin(),sortedFrequencyMap.end(),sortFunc);
	userInput.clear();
	for(unsigned int counter = 0;counter < sortedFrequencyMap.size();counter++){
		itToSortedPair = sortedFrequencyMap[counter];
		count = itToSortedPair.second;
		while(count--){
			userInput.push_back(itToSortedPair.first);
		}
	}
}

void sortElementsByFrequencySort(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	sort(userInput.begin(),userInput.end());
	vector<pair<int,unsigned int> > frequencyMap;
	unsigned int frequency = 0;
	for(unsigned int counter=0;counter < userInput.size();){
		frequency = 1;
		while(counter + 1 < userInput.size() && userInput[counter] == userInput[counter+1]){
			frequency += 1;
		}
		frequencyMap.push_back(pair<int,unsigned int>(userInput[counter],frequency));
		counter += frequency;
	}
	sort(frequencyMap.begin(),frequencyMap.end(),sortFunc);
	userInput.clear();
	pair<int,unsigned int> itToSortedPair;
	for(unsigned int counter = 0;counter < frequencyMap.size();counter++){
		itToSortedPair = frequencyMap[counter];
		frequency = itToSortedPair.second;
		while(frequency--){
			userInput.push_back(itToSortedPair.first);
		}
	}
}

#endif /* SORTELEMENTSBYFREQUENCY_H_ */

/************************************************* End code *******************************************************/
