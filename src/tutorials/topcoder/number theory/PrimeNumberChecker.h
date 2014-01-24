/***************************************************************************************************************** 
 *  File Name   		: PrimeNumberChecker.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\topcoder\number theory\PrimeNumberChecker.h
 *  Created on			: Jan 23, 2014 :: 7:33:59 PM
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

#ifndef PRIMENUMBERCHECKER_H_
#define PRIMENUMBERCHECKER_H_

bool checkIfNumberIsPrimeNaive(unsigned int userInput){
	if(userInput == 1 || userInput == 0){
		return false;
	}
	unsigned int sumOfDivisors = 0;
	for(unsigned int counter = 1;counter <= userInput;counter++){
		if(userInput%counter == 0){
			sumOfDivisors++;
		}
	}
	return sumOfDivisors == 2?true:false;
}

bool checkIfNumberIsPrime(unsigned int userInput){
	if(userInput == 1 || userInput == 0){
		return false;
	}
	if(userInput == 2){
		return true;
	}
	unsigned int squareRootOfUserInput = sqrt(userInput);
	bool isPrimeNumber = true;
	for(unsigned int counter = 2;counter <= squareRoot;counter++){
		if(userInput % counter == 0){
			isPrimeNumber = false;
			break;
		}
	}
	return isPrimeNumber;
}


#endif /* PRIMENUMBERCHECKER_H_ */

/************************************************* End code *******************************************************/
