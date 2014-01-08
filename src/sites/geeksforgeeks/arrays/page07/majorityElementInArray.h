/***************************************************************************************************************** 
 *  File Name   		: majorityElementInArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\majorityElementInArray.h
 *  Created on			: Jan 6, 2014 :: 6:48:43 PM
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

#ifndef MAJORITYELEMENTINARRAY_H_
#define MAJORITYELEMENTINARRAY_H_

bool majorityElement(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	if(userInput.size() == 1){
		return true;
	}
	int sumOfElements = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			sumOfElements += 1;
		}
	}
	if(sumOfElements > userInput.size()/2){
		return true;
	}
	return false;
}

unsigned int majorityElementBinarySearch(vector<int> userInput,unsigned int startIndex,unsigned int endIndex,int key){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex - 1 >= startIndex && userInput[middleIndex - 1] != key){
			return middleIndex;
		}else{
			return majorityElementBinarySearch(userInput,startIndex,middleIndex-1,key);
		}
	}
	if(userInput[middleIndex] > startIndex){
		return majorityElementBinarySearch(userInput,startIndex,middleIndex-1,key);
	}else{
		return majorityElementBinarySearch(userInput,middleIndex+1,endIndex,key);
	}
}

bool majorityBinarySearchDriver(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	if(userInput.size() == 1){
		return true;
	}
	unsigned int lowestIndex = majorityElementBinarySearch(userInput,0,userInput.size(),key);
	return userInput[lowestIndex + userInput.size()/2] == key?true:false;
}
#endif /* MAJORITYELEMENTINARRAY_H_ */

/************************************************* End code *******************************************************/
