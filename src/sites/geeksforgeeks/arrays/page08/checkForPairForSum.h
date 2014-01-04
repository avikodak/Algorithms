/***************************************************************************************************************** 
 *  File Name   		: checkForPairForSum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\checkForPairForSum.h
 *  Created on			: Jan 2, 2014 :: 5:51:10 PM
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

#ifndef CHECKFORPAIRFORSUM_H_
#define CHECKFORPAIRFORSUM_H_

struct pair{
	int first;
	int second;
};

vector<pair> getPairForGivenSumON2(vector<int> userInput,int sum){
	vector<pair> allPairsForSum;
	if(userInput.size() == 0){
		return allPairsForSum;
	}
	unsigned int outerCrawler,innerCrawler;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(outerCrawler == innerCrawler){
				continue;
			}
			if(userInput[innerCrawler] + userInput[outerCrawler] == sum){
				pair newPair = (pair)malloc(sizeof(pair));
				newPair.first = userInput[outerCrawler];
				newPair.second = userInput[innerCrawler];
				allPairsForSum.push_back(newPair);
			}
		}
	}
}

vector<pair> getPairForGivenSumONLOGN(vector<int> userInput,int sum){
	vector<pair> allPairsForSum;
	if(userInput.size() == 0){
		return allPairsForSum;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int startCrawler=0,endCrawler = userInput.size()-1;
	int currentSum;
	while(startCrawler < endCrawler){
		currentSum = userInput[startCrawler] + userInput[endCrawler];
		if(currentSum == sum){
			pair newPair = (pair)malloc(sizeof(pair));
			newPair.first = userInput[startCrawler];
			newPair.second = userInput[endCrawler];
			allPairsForSum.push_back(newPair);
			startCrawler += 1;
			endCrawler -= 1;
		}else{
			if(currentSum > sum){
				endCrawler -= 1;
			}else{
				startCrawler -= 1;
			}
		}
	}
}

vector<pair> getPairForGivenSumONLOGNBST(vector<int> userInput,int sum){

}

vector<pair> getPairForGivenSumON(vector<int> userInput,int sum){
	vector<pair> allPairsForSum;
	if(userInput.size() == 0){
		return allPairsForSum;
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
		if((itToFrequencyMap = frequencyMap.find(sum - userInput[counter])) != frequencyMap.end()){
			pair newPair = (pair)malloc(sizeof(pair));
			newPair.first = userInput[counter];
			newPair.second = itToFrequencyMap->first;
		}
	}
}

#endif /* CHECKFORPAIRFORSUM_H_ */

/************************************************* End code *******************************************************/
