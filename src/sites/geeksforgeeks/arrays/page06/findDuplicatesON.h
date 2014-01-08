/***************************************************************************************************************** 
 *  File Name   		: findDuplicatesON.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\findDuplicatesON.h
 *  Created on			: Jan 6, 2014 :: 9:52:35 PM
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

#ifndef FINDDUPLICATESON_H_
#define FINDDUPLICATESON_H_

set<int> findDuplicatesON2(vector<int> userInput){
	set<int> duplicates;
	if(userInput.size() == 0 || userInput.size() == 1){
		return duplicates;
	}
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] == userInput[outerCounter]){
				duplicates.insert(userInput[innerCounter]);
			}
		}
	}
}

vector<int> findDuplicatesONLOGN(vector<int> userInput){
	set<int> duplicates;
	if(userInput.size() == 0 || userInput.size() == 1){
		return duplicates;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	while(counter < userInput.size()){
		if(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]){
			duplicates.insert(userInput[counter]);
			counter += 2;
		}else{
			counter++;
		}
	}
}

vector<int> findDuplicatesONAuxspace(vector<int> userInput){
	vector<int> duplicates;
	if(userInput.size() == 0 || userInput.size() == 1){
		return duplicates;
	}
	hash_map<int,unsigned int> frequencyList;
	hash_map<int,unsigned int>::iterator itToFrequencyList;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyList = frequencyList.find(userInput[counter])) != frequencyList.end()){
			frequencyList[userInput[counter]] += 1;
		}else{
			frequencyList.insert(pair<int,unsigned int>(userInput[counter],1));
		}
	}
	for(itToFrequencyList = frequencyList.begin();itToFrequencyList != frequencyList.end();itToFrequencyList++){
		if(itToFrequencyList->second > 1){
			duplicates.push_back(itToFrequencyList->first);
		}
	}
	return duplicates;
}

vector<int> findDuplicatesON(vector<int> userInput){
	vector<int> duplicates;
	if(userInput.size() == 0 || userInput.size() == 1){
		return duplicates;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[userInput[counter]] < 0){
			duplicates.push_back(abs(userInput[counter]));
		}else{
			userInput[userInput[counter]] *= 1;
		}
	}
}

#endif /* FINDDUPLICATESON_H_ */

/************************************************* End code *******************************************************/
