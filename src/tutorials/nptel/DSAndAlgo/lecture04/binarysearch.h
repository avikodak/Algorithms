/***************************************************************************************************************** 
 *  File Name   		: binarysearch.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture04\binarysearch.h
 *  Created on			: Dec 30, 2013 :: 12:13:42 AM
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

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

bool binarySearch(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex || userInput.size() == 0){
		return false;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return true;
	}
	if(userInput[middleIndex] > key){
		return binarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return binarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

bool binarySearchIterative(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	unsigned int startIndex = 0,endIndex = userInput.size()-1;
	unsigned int middleIndex;
	while(startIndex < endIndex){
		middleIndex = (startIndex + endIndex)/2;
		if(userInput[middleIndex] == key){
			return true;
		}
		if(userInput[middleIndex] > key){
			endIndex = middleIndex - 1;
		}else{
			startIndex = middleIndex + 1;
		}
	}

}

#endif /* BINARYSEARCH_H_ */

/************************************************* End code *******************************************************/
