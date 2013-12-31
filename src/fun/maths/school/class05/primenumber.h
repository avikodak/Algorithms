/***************************************************************************************************************** 
 *  File Name   		: primenumber.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\primenumber.h
 *  Created on			: Dec 27, 2013 :: 1:39:10 AM
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

#ifndef PRIMENUMBER_H_
#define PRIMENUMBER_H_

bool isPrimeNumber(unsigned int userInput){
	if(userInput == 0 || userInput == 1){
		return false;
	}
	if(userInput == 2){
		return true;
	}
	if(userInput%2 == 0){
		return false;
	}
	for(unsigned int counter = 3;counter <= sqrt(userInput);counter+=2){
		if(userInput%counter == 0){
			return false;
		}
	}
	return true;
}

bool isPrimeNumberFactorsCount(unsigned int userInput){
	if(userInput == 0 || userInput == 1){
		return false;
	}
	vector<unsigned int> factorsOfGivenNumber = facorsOfGivenNumber(userInput);
	return factorsOfGivenNumber.size() == 2?true:false;
}

#endif /* PRIMENUMBER_H_ */

/************************************************* End code *******************************************************/
