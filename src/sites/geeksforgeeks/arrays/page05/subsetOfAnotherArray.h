
/***************************************************************************************************************** 
 *  File Name   		: subsetOfAnotherArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\subsetOfAnotherArray.h
 *  Created on			: Jan 8, 2014 :: 12:23:23 AM
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

#ifndef SUBSETOFANOTHERARRAY_H_
#define SUBSETOFANOTHERARRAY_H_

bool isSubsetOfAnotherArray(vector<int> superSet,vector<int> subset){
	if(superSet.size() == 0 && subset.size() == 0){
		return true;
	}
	if(superSet.size() == 0 || subset.size() == 0){
		return superSet.size() == 0?false:true;
	}
	if(subset.size() > superSet.size()){
		return false;
	}
	bool isFound;
	for(unsigned int subsetCounter = 0;subsetCounter < subset.size();subsetCounter++){
		isFound = false;
		for(unsigned int supersetCounter = 0;supersetCounter < superSet.size();subsetCounter++){
			if(subset[subsetCounter] == superSet[supersetCounter]){
				isFound = true;
				break;
			}
		}
		if(!isFound){
			return false;
		}
	}
	return true;
}

bool isSubsetOfAnotherArrayONLOGN(vector<int> superSet,vector<int> subset){
	if(superSet.size() == 0 && subset.size() == 0){
		return true;
	}
	if(superSet.size() == 0 || subset.size() == 0){
		return superSet.size() == 0?false:true;
	}
	if(subset.size() > superSet.size()){
		return false;
	}
	sort(superSet.begin(),superSet.end());
	for(unsigned int counter = 0;counter < subset.size();counter++){
		if(!binary_search(superSet.begin(),superSet.end(),superSet[counter])){
			return false;
		}
	}
	return true;
}

bool isSubsetOfAnotherArrayONLOGNSorting(vector<int> superSet,vector<int> subset){
	if(superSet.size() == 0 && subset.size() == 0){
		return true;
	}
	if(superSet.size() == 0 || subset.size() == 0){
		return superSet.size() == 0?false:true;
	}
	if(subset.size() > superSet.size()){
		return false;
	}
	sort(superSet.begin(),superSet.end());
	sort(subset.begin(),subset.end());
	unsigned int supersetCrawler = 0,subsetCrawler = 0;
	while(supersetCrawler < superSet.size() && subsetCrawler < subset.size()){
		if(superSet[supersetCrawler] == subset[subsetCrawler]){
			supersetCrawler++;
			subsetCrawler++;
		}else{
			if(superSet[supersetCrawler] < subset[subsetCrawler]){
				supersetCrawler++;
			}else{
				return false;
			}
		}
	}
	return true;
}

bool isSubsetOfAnotherArrayON(vector<int> superSet,vector<int> subset){
	if(superSet.size() == 0 && subset.size() == 0){
		return true;
	}
	if(superSet.size() == 0 || subset.size() == 0){
		return superSet.size() == 0?false:true;
	}
	if(subset.size() > superSet.size()){
		return false;
	}
	hash_map<int,unsigned int> frequencyMapSuperSet;
	hash_map<int,unsigned int>::iterator itToFrequencyMapSuperSet;
	for(unsigned int counter = 0;counter < superSet.size();counter++){
		if((itToFrequencyMapSuperSet = frequencyMapSuperSet.find(superSet[counter])) != frequencyMapSuperSet.end()){
			frequencyMapSuperSet[itToFrequencyMapSuperSet->first] += 1;
		}else{
			frequencyMapSuperSet.insert(pair<int,unsigned int>(superSet[counter],1));
		}
	}

	for(unsigned int counter = 0;counter < subset.size();counter++){
		if((itToFrequencyMapSuperSet = frequencyMapSuperSet.find(subset[counter])) != frequencyMapSuperSet.end()){
			if(itToFrequencyMapSuperSet->second == 1){
				frequencyMapSuperSet.erase(itToFrequencyMapSuperSet->first);
			}else{
				frequencyMapSuperSet[subset[counter]] -= 1;
			}
		}else{
			return false;
		}
	}
	return true;
}

#endif /* SUBSETOFANOTHERARRAY_H_ */

/************************************************* End code *******************************************************/
