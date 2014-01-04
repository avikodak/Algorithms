/***************************************************************************************************************** 
 *  File Name   		: tightstrategy.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture02\tightstrategy.h
 *  Created on			: Dec 29, 2013 :: 6:11:41 PM
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
#define TIGHT_STRATEGY_SIZE_INCREMENTS 10

/************************************************* Main code  ******************************************************/

#ifndef TIGHTSTRATEGY_H_
#define TIGHTSTRATEGY_H_

int *growArrayByTightStrategy(int userInput[],unsigned int sizeOfArray,int key){
	int *biggerArray;
	biggerArray = (int *)calloc(sizeOfArray + TIGHT_STRATEGY_SIZE_INCREMENTS,sizeof(int));
	if(userInput != NULL){
		for(unsigned int counter = 0;counter < sizeOfArray;counter++){
			biggerArray[counter] = userInput[counter];
		}
	}
	biggerArray[sizeOfArray] = key;
	return biggerArray;
}

#endif /* TIGHTSTRATEGY_H_ */

/************************************************* End code *******************************************************/
