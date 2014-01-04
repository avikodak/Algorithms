/***************************************************************************************************************** 
 *  File Name   		: reverseArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\reverseArray.h
 *  Created on			: Jan 2, 2014 :: 10:09:38 PM
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

#ifndef REVERSEARRAY_H_
#define REVERSEARRAY_H_

void reverseArrayIterativeAuxspace(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	stack<int> auxSpace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace.push(userInput[counter]);
	}
	unsigned int counter = 0;
	while(!auxSpace.empty()){
		userInput[counter] = auxSpace.top();
		auxSpace.pop();
	}
}

void reverseArrayIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int frontCrawler = 0,backCrawler= userInput.size();
	int tempForSwap;
	while(frontCrawler < backCrawler){
		tempForSwap = userInput[frontCrawler];
		userInput[frontCrawler] = userInput[backCrawler];
		userInput[backCrawler] = temp;
		frontCrawler++;
		backCrawler--;
	}
}

void reverseArray(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(userInput.size() == 0 || startIndex > endIndex){
		return;
	}
	int temp = userInput[startIndex];
	userInput[startIndex] = userInput[endIndex];
	userInput[endIndex] = temp;
	reverseArray(userInput,startIndex+1,endIndex-1);
}

void reverseArrayRecursive(vector<int> userInput,unsigned int crawler,unsigned int &startCrawler){
	if(userInput.size() == 0 || crawler >= userInput.size()){
		return;
	}
	reverseArrayRecursive(userInput,crawler+1,startCrawler);
	if(startCrawler < crawler){
		int temp = userInput[crawler];
		userInput[crawler] = userInput[startCrawler];
		userInput[startCrawler] = temp;
		startCrawler += 1;
	}
}

void reverseArrayNewArray(vector<int> userInput){
	if(userInput.size()==0){
		return;
	}
	vector<int> reverseArray;
	copy_backward(userInput.begin(),userInput.end(),reverseArray.begin());
	copy(reverseArray.begin(),reverseArray.end(),userInput.begin());
}
#endif /* REVERSEARRAY_H_ */

/************************************************* End code *******************************************************/
