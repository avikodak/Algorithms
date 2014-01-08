/***************************************************************************************************************** 
 *  File Name   		: equilibriumIndex.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\equilibriumIndex.h
 *  Created on			: Jan 6, 2014 :: 10:17:09 PM
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

#ifndef EQUILIBRIUMINDEX_H_
#define EQUILIBRIUMINDEX_H_

vector<int> equilibriumIndexON2(vector<int> userInput){
	vector<int> equilibriumIndexes;
	if(userInput.size() == 0){
		return equilibriumIndexes;
	}
	int leftSum,rightSum;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		leftSum = 0;
		rightSum = 0;
		for(unsigned int leftCounter = 0;leftCounter < counter;leftCounter++){
			leftSum += userInput[leftCounter];
		}
		for(unsigned int rightCounter = counter+1;rightCounter < userInput.size();rightCounter++){
			rightSum += userInput[rightCounter];
		}
		if(leftSum == rightSum){
			equilibriumIndexes.push_back(counter);
		}
	}
}

vector<int> equilibriumIndexON(vector<int> userInput){
	vector<int> equilibriumIndexes;
	if(userInput.size() == 0){
		return equilibriumIndexes;
	}
	vector<int> leftSum;
	leftSum[0] = 0;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftSum[counter] = leftSum[counter-1] + userInput[counter-1];
	}
	int rightSum = 0;
	for(unsigned int counter = userInput.size()-1;counter >= 0;counter--){
		if(leftSum[counter] == rightSum){
			equilibriumIndexes.push_back(counter);
		}
		rightSum += userInput[counter];
	}
}
#endif /* EQUILIBRIUMINDEX_H_ */

/************************************************* End code *******************************************************/
