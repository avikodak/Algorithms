/***************************************************************************************************************** 
 *  File Name   		: arrayRotation.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\arrayRotation.h
 *  Created on			: Jan 3, 2014 :: 6:48:44 PM
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

#ifndef ARRAYROTATION_H_
#define ARRAYROTATION_H_

void rotateArrayByOne(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	int key = userInput[0];
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		userInput[counter] = userInput[counter+1];
	}
	userInput[userInput.size()-1] = key;
}

void rotateArray(vector<int> userInput,unsigned int rotateBy){
	if(userInput.size() == 0|| userInput.size() == 1){
		return;
	}
	for(unsigned int counter = 0;counter < rotateBy;counter++){
		rotateArrayByOne(userInput);
	}
}

void rotateArrayByNewArray(vector<int> userInput,unsigned int rotateBy){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	vector<int> rotatedArray;
	unsigned int fillCounter = (userInput.size() - (rotateBy % userInput)) - 1;
	for(unsigned int counter =0;counter < userInput.size();counter++){
		rotatedArray[fillCounter % userInput.size()] = userInput[counter];
	}
	copy(rotatedArray.begin(),rotatedArray.end(),userInput.begin());
}

void rotationByJuggling(vector<int> userInput,unsigned int rotateBy){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	unsigned int gcd;
	for(unsigned int counter = 0;counter < gcd;counter++){

	}
}

void rotationByBlockswap(vector<int> userInput,unsigned int startIndex,unsigned int endIndex,unsigned int rotateBy){

}
#endif /* ARRAYROTATION_H_ */

/************************************************* Ensd code *******************************************************/
