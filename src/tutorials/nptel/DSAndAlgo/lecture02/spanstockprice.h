/***************************************************************************************************************** 
 *  File Name   		: spanstockprice.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture02\spanstockprice.h
 *  Created on			: Dec 29, 2013 :: 5:58:08 PM
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

#ifndef SPANSTOCKPRICE_H_
#define SPANSTOCKPRICE_H_

vector<int> spanON2(vector<int> userInput){
	vector<int> span;
	if(userInput.size() == 0){
		return span;
	}
	span.push_back(-1);
	bool isFound;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		isFound = false;
		for(unsigned int innerCounter = outerCounter-1;innerCounter >= 0;innerCounter--){
			if(userInput[innerCounter] >= userInput[outerCounter]){
				span.push_back(outerCounter - innerCounter + 1);
				isFound = true;
			}
		}
		if(!isFound){
			userInput.push_back(-1);
		}
	}
}

vector<int> spanON(vector<int> userInput){
	vector<int> span;
	if(userInput.size() == 0){
		return span;
	}
	stack<unsigned int> index;
	span.push_back(-1);
	index.push(0);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		while(!index.empty()&& userInput[index.top()] < userInput[counter]){
			index.pop();
		}
		if(index.empty()){
			span.push_back(-1);
		}else{
			span.push_back(counter - index.top() + 1);
		}
		index.push(counter);
	}
}
#endif /* SPANSTOCKPRICE_H_ */

/************************************************* End code *******************************************************/
