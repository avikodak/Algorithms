/***************************************************************************************************************** 
 *  File Name   		: leadersInArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\leadersInArray.h
 *  Created on			: Jan 5, 2014 :: 7:34:38 PM
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

#ifndef LEADERSINARRAY_H_
#define LEADERSINARRAY_H_

vector<int> leadersInArrayON2(vector<int> userInput){
	vector<int> leaders;
	if(userInput.size() == 0){
		return leaders;
	}
	if(userInput.size() == 1){
		return userInput;
	}
	unsigned int outerCounter,innerCounter;
	bool isGreatest;
	int key;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		key = userInput[outerCounter];
		isGreatest = true;
		for(innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] > key){
				isGreatest = false;
			}
		}
		if(!isGreatest){
			leaders.push_back(userInput[outerCounter]);
		}
	}
	return leaders;
}

void leadersInArrayBST(tNode *ptr,int &maxValue,vector<int> &leaders){
	if(ptr == NULL){
		return;
	}
	leadersInArrayBST(ptr->left,maxValue,leaders);
	leadersInArrayBST(ptr->right,maxValue,leaders);
	if(ptr->value > maxValue){
		leaders.push_back(ptr->value);
		maxValue = ptr->value;
	}
}

vector<int> leadersInArrayONLOGNBST(vector<int> userInput){
	vector<int> leaders;
	if(userInput.size() == 0){
		return leaders;
	}
	if(userInput.size() == 1){
		return userInput;
	}
	tNode *bst = NULL;
	createBST(&bst,userInput);
	int max = INT_MIN;
	leadersInArrayBST(bst,max,leaders);
	return leaders;
}

vector<int> leadersInArrayON(vector<int> userInput){
	vector<int> leaders;
	if(userInput.size() == 0){
		return leaders;
	}
	if(userInput.size() == 1){
		return userInput;
	}
	int maxElement = INT_MIN;
	for(unsigned int counter = userInput.size()-1;counter >= 0;counter--){
		if(userInput[counter] > maxElement){
			leaders.push_back(userInput[counter]);
			maxElement = userInput[counter];
		}
	}
}
#endif /* LEADERSINARRAY_H_ */

/************************************************* End code *******************************************************/
