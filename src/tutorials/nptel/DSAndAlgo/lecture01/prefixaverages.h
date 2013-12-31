/***************************************************************************************************************** 
 *  File Name   		: prefixaverages.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture01\prefixaverages.h
 *  Created on			: Dec 28, 2013 :: 2:17:15 AM
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

#ifndef PREFIXAVERAGES_H_
#define PREFIXAVERAGES_H_

vector<float> prefixAveragesON2(vector<int> userInput){
	vector<float> prefixAverages;
	if(userInput.size() == 0){
		return prefixAverages;
	}
	unsigned int outerCounter,innerCounter;
	int sumOfElements;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		sumOfElements = 0;
		for(innerCounter = 0;innerCounter <= outerCounter;innerCounter++){
			sumOfElements += userInput[innerCounter];
		}
		prefixAverages[outerCounter] = sumOfElements/float(outerCounter+1);
	}
	return prefixAverages;
}

vector<float> prefixAveragesON(vector<int> userInput){
	vector<float> prefixAverages;
	if(userInput.size() == 0){
		return prefixAverages;
	}
	int sum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sum += userInput[counter];
		prefixAverages[counter] = sum/float(counter+1);
	}
}

#endif /* PREFIXAVERAGES_H_ */

/************************************************* End code *******************************************************/
