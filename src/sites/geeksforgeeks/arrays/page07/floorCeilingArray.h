/***************************************************************************************************************** 
 *  File Name   		: floorCeilingArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\floorCeilingArray.h
 *  Created on			: Jan 5, 2014 :: 11:57:24 PM
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

#ifndef FLOORCEILINGARRAY_H_
#define FLOORCEILINGARRAY_H_

int *floorCeilingSortedArrayLinearSearch(vector<int> userInput,int key){
	if(userInput.size() == 0) {
		return NULL;
	}
	int floorCeiling[2];
	if(userInput.size() == 1) {
		floorCeiling[0] = userInput[0];
		floorCeiling[1] = userInput[0];
		return floorCeiling;
	}
	if(userInput[0] > key){
		floorCeiling[0] = INT_MIN;
		floorCeiling[1] = userInput[0];
		return floorCeiling;
	}
	if(userInput[userInput.size() - 1] < key){
		floorCeiling[0] = userInput[userInput.size()-1];
		floorCeiling[1] = INT_MAX;
		return floorCeiling;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			if(counter-1 > 0){
				floorCeiling[0] = userInput[counter-1];
			}
			if(counter + 1 < userInput.size()){
				floorCeiling[1] = userInput[counter+1];
			}
			break;
		}else{
			if(counter + 1 < userInput.size()){
				if(userInput[counter] > key && userInput[counter+1] < key){
					floorCeiling[0] = userInput[counter];
					floorCeiling[1] = userInput[counter + 1];
					break;
				}
			}
		}
	}
	return floorCeiling;
}

int *floorCeilingBinarySearch(vector<int> userInput,unsigned int startIndex,unsigned int endIndex,int key){
	if(startIndex > endIndex){
		return NULL;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	int floorCeiling[2];
	if(middleIndex == 0){
		floorCeiling[0] = INT_MIN;
		floorCeiling[1] = userInput[middleIndex];
		return floorCeiling;
	}
	if(middleIndex + 1 == userInput.size()){
		floorCeiling[0] = userInput[middleIndex];
		floorCeiling[1] = INT_MAX;
		return floorCeiling;
	}
	if(userInput[middleIndex] == key){
		floorCeiling[0] = userInput[middleIndex-1];
		floorCeiling[1] = userInput[middleIndex+1];
		return floorCeiling;
	}
	if(userInput[middleIndex] > key && userInput[middleIndex+1] > key){
		floorCeiling[0] = userInput[middleIndex];
		floorCeiling[1] = userInput[middleIndex+1];
		return floorCeiling;
	}
	if(userInput[middleIndex] > key){
		return floorCeilingBinarySearch(userInput,startIndex,middleIndex-1,key);
	}else{
		return floorCeilingBinarySearch(userInput,middleIndex+1,endIndex,key);
	}
}

#endif /* FLOORCEILINGARRAY_H_ */

/************************************************* End code *******************************************************/
