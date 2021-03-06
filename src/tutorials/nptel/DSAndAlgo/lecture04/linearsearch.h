/***************************************************************************************************************** 
 *  File Name   		: linearsearch.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture04\linearsearch.h
 *  Created on			: Dec 30, 2013 :: 12:13:33 AM
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

#ifndef LINEARSEARCH_H_
#define LINEARSEARCH_H_

bool linearSearch(vector<int> userInput,int key,unsigned int currentIndex = 0){
	if(currentIndex >= userInput.size()){
		return false;
	}
	if(userInput[currentIndex] == key){
		return true;
	}
	return linearSearch(userInput,key,currentIndex+1);
}

bool linearSearch(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			return true;
		}
	}
	return false;
}

#endif /* LINEARSEARCH_H_ */

/************************************************* End code *******************************************************/
