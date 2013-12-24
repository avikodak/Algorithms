/***************************************************************************************************************** 
 *  File Name   		: CountNoOfInts.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\CountNoOfInts.h
 *  Created on			: Dec 18, 2013 :: 12:20:53 AM
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

#ifndef COUNTNOOFINTS_H_
#define COUNTNOOFINTS_H_

unsigned int countOccurenceLL(llNode *ptr,int userInput){
	if(ptr == NULL){
		return 0;
	}
	llNode *traversalPtr = ptr;
	unsigned int occurences  = 0;
	while(traversalPtr != NULL){
		if(traversalPtr->value == userInput){
			occurences += 1;
		}
	}
	return occurences;
}

unsigned int countOccurenceLLHashmap(llNode *ptr,int userInput){
	if(ptr == NULL){
		return 0;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	llNode *traversalPtr = ptr;
	while(traversalPtr != NULL){
		if((itToFrequencyMap = frequencyMap.find(traversalPtr->value)) != frequencyMap.end()){
			frequencyMap[itToFrequencyMap->first] += 1;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(traversalPtr->value,1));
		}
		traversalPtr = traversalPtr->next;
	}
	if((itToFrequencyMap = frequencyMap.find(userInput))!= frequencyMap.end()){
		return itToFrequencyMap->second;
	}else{
		return 0;
	}
}

unsigned int countOccurenceLLBST(llNode *ptr,int userInput){
	if(ptr == NULL){
		return NULL;
	}
	tNodeAuxVal *aBST,*keyNode;
	createFrequencyBSTForLL(&aBST,aBST,ptr);
	keyNode = searchForNodeABSTIterative(aBST,userInput);
	return keyNode != NULL?keyNode->auxValue:0;
}
#endif /* COUNTNOOFINTS_H_ */

/************************************************* End code *******************************************************/
