/***************************************************************************************************************** 
 *  File Name   		: constructTreeFromInorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\constructTreeFromInorder.h
 *  Created on			: Jan 4, 2014 :: 7:27:27 PM
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

#ifndef CONSTRUCTTREEFROMINORDER_H_
#define CONSTRUCTTREEFROMINORDER_H_

unsigned int getMaxIndex(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	if(startIndex == endIndex){
		return startIndex;
	}
	int maxValue = INT_MIN;
	unsigned int maxIndex = UINT_MAX;
	for(unsigned int counter = startIndex;counter <= endIndex;counter++){
		if(maxValue < userInput[counter]){
			maxIndex = counter;
			maxValue = userInput[counter];
		}
	}
	return maxIndex;
}

tNode *buildTreeFromInorder(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return NULL;
	}
	unsigned int maxIndex = getMaxIndex(userInput,startIndex,endIndex);
	tNode *newNode = (tNode *)malloc(sizeof(tNode));
	newNode->value = userInput[maxIndex];
	newNode->left = buildTreeFromInorder(userInput,startIndex,maxIndex-1);
	newNode->right = buildTreeFromInorder(userInput,maxIndex+1,endIndex);
	return newNode;
}


#endif /* CONSTRUCTTREEFROMINORDER_H_ */

/************************************************* End code *******************************************************/
