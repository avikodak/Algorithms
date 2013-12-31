/***************************************************************************************************************** 
 *  File Name   		: maxelement.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture01\maxelement.h
 *  Created on			: Dec 28, 2013 :: 1:35:55 AM
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

#ifndef MAXELEMENT_H_
#define MAXELEMENT_H_

int maxElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int innerCounter,outerCounter;
	bool isMaxElement;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		isMaxElement = true;
		for(innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] > userInput[outerCounter]){
				isMaxElement = false;
			}
		}
		if(isMaxElement){
			return userInput[outerCounter];
		}
	}
}

int maxElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	return userInput[userInput.size()-1];
}

int maxElementBSTONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	tNode *bstTree,*currentNode;
	createBST(&bstTree,userInput);
	currentNode = bstTree;
	while(currentNode->right != NULL){
		currentNode = currentNode->right;
	}
	return currentNode->value;
}

int maxElementONIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int maxElement = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(maxElement < userInput[counter]){
			maxElement = userInput[counter];
		}
	}
	return maxElement;
}

int maxElementON(vector<int> userInput,unsigned int currentIndex){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(userInput.size() == currentIndex+1){
		return userInput[currentIndex];
	}
	int maxTillNow = maxElementON(userInput,currentIndex+1);
	if(maxTillNow < userInput[currentIndex]){
		maxTillNow = userInput[currentIndex];
	}
	return maxTillNow;
}

int maxElementDivideAndConquer(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){

}
#endif /* MAXELEMENT_H_ */

/************************************************* End code *******************************************************/
