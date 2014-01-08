/***************************************************************************************************************** 
 *  File Name   		: nextGreaterElement.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\nextGreaterElement.h
 *  Created on			: Jan 6, 2014 :: 10:17:39 PM
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

#ifndef NEXTGREATERELEMENT_H_
#define NEXTGREATERELEMENT_H_

vector<int> nextGreaterElementON2(vector<int> userInput){
	vector<int> greaterElements;
	if(userInput.size() == 0){
		return greaterElements;
	}
	bool maxValueFound;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		maxValueFound = false;
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] > userInput[outerCounter]){
				greaterElements.push_back(userInput[innerCounter]);
				maxValueFound = true;
				break;
			}
		}
		if(!maxValueFound){
			greaterElements.push_back(INT_MAX);
		}
	}
	return greaterElements;
}

vector<int> nextGreaterElementsON(vecor<int> userInput){
	vector<int> greaterElements;
	if(userInput.size() == 0){
		return greaterElements;
	}
}
#endif /* NEXTGREATERELEMENT_H_ */

/************************************************* End code *******************************************************/
