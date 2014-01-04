/***************************************************************************************************************** 
 *  File Name   		: findMissingNumber.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\findMissingNumber.h
 *  Created on			: Jan 2, 2014 :: 6:38:20 PM
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

#ifndef FINDMISSINGNUMBER_H_
#define FINDMISSINGNUMBER_H_

unsigned int findMissingNumberON2(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	bool isFound;
	for(unsigned int noCounter = 1;noCounter <= userInput.size();noCounter++){
		isFound = false;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(userInput[counter] == noCounter){
				isFound = true;
			}
		}
		if(!isFound){
			return noCounter;
		}
	}
	return UINT_MAX;
}

unsigned int findMissingNumberONLOGN(vector<unsigned int> userInput){
	if(userInput.size() == 0){
			return 1;
	}
	sort(userInput.front(),userInput.end());
	for(unsigned int counter =0;counter < userInput.size();counter++){
		if(userInput[counter] != counter + 1){
			return counter+1;
		}
	}
	return UINT_MAX;
}

unsigned int findMissingNumberONAuxspace(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	bool auxSpace[userInput.size()+1] = {false};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace[userInput[counter]] = true;
	}
	for(unsigned int counter=1;counter < userInput.size()+1;counter++){
		if(!auxSpace[counter]){
			return counter;
		}
	}
}

unsigned int findMissingNumberON(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[abs(userInput[counter]) -1] *= -1;
	}
	unsigned int counter;
	for(counter=0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			break;
		}
	}
	return counter+1;
}

unsigned int findMissingNumberONSum(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	unsigned int sumArray = 0,actualSum;
	unsigned int lastNo = userInput.size();
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sumArray += userInput[counter];
	}
	actualSum = (lastNo*(lastNo+1))/2;
	return actualSum-sumArray;
}

unsigned int findMissingNumberONXOR(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	unsigned int xorNumber = 0,xorArray = 0;
	for(unsigned int numbCounter = 1;numbCounter <= userInput.size();numbCounter++){
		xorNumber ^= numbCounter;
	}
	for(unsigned int counter=0;counter < userInput.size();counter++){
		xorArray ^= userInput[counter];
	}
	return xorNumber ^ xorArray;
}

#endif /* FINDMISSINGNUMBER_H_ */

/************************************************* End code *******************************************************/
