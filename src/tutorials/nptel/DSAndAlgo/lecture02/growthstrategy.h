/***************************************************************************************************************** 
 *  File Name   		: growthstrategy.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture02\growthstrategy.h
 *  Created on			: Dec 29, 2013 :: 6:11:54 PM
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
#define GROWTH_STRATEGY_SIZE_MULTIPLY 2

/************************************************* Main code  ******************************************************/

#ifndef GROWTHSTRATEGY_H_
#define GROWTHSTRATEGY_H_

int *growArrayByGrowthStrategy(int userInput[],unsigned int sizeOfArray,int key){
	int *biggerArray;
	biggerArray = (int *)calloc(sizeOfArray + (GROWTH_STRATEGY_SIZE_MULTIPLY * sizeOfArray),sizeof(int));
	if(biggerArray != NULL){
		for(unsigned int counter = 0;counter < sizeOfArray;counter++){
			biggerArray[counter] = userInput[counter];
		}
	}
	biggerArray[sizeOfArray] = key;
	return biggerArray;
}

#endif /* GROWTHSTRATEGY_H_ */

/************************************************* End code *******************************************************/
