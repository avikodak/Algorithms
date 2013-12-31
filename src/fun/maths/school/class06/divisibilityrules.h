/***************************************************************************************************************** 
 *  File Name   		: DivisibilityRules.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class06\DivisibilityRules.h
 *  Created on			: Dec 27, 2013 :: 1:00:50 AM
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

#ifndef DIVISIBILITYRULES_H_
#define DIVISIBILITYRULES_H_

bool isNumberDivisibleBy2(unsigned int userInput){
	unsigned int remainder;
	remainder = userInput % 10;
	return remainder == 0 || userInput == 2 || userInput == 4 || userInput == 6 || userInput== 8;
}

bool isNumberDivisibleBy3(unsigned int userInput){
	unsigned int sumOfDigits = 0;
	while(userInput > 0){
		sumOfDigits += (userInput % 10);
		userInput /= 10;
	}
	return sumOfDigits%3 == 0?true:false;
}

bool isNumberDivisibleBy4(unsigned int userInput){
	unsigned int lastTwoDigits = userInput%100;
	return lastTwoDigits%4 == 0? true:false;
}

bool isNumberDivisibleBy5(unsigned int userInput){
	unsigned int remainder = (userInput%10)%5;
	return userInput == 5 || userInput == 0;
}

bool isNumberDivisibleBy6(unsigned int userInput){
	return isNumberDivisibleBy2(userInput) && isNumberDivisibleBy3(userInput);
}

bool isNumberDivisibleBy8(unsigned int userInput){
	unsigned int lastThreeDigits = userInput % 1000;
	return lastThreeDigits%8 ==0?true:false;
}

bool isNumberDivisibleBy9(unsigned int userInput){
	unsigned int sumOfDigits = 0;
	while(userInput > 0){
		sumOfDigits += (userInput%10);
		userInput /= 10;
	}
	return sumOfDigits%9 == 0?true:false;
}

bool isNumberDivisibleBy10(unsigned int userInput){
	return userInput%10 == 0?true:false;
}

bool isNumberDivisibleBy11(unsigned int userInput){
	unsigned int sumOfOddDigits = 0,sumOfEvenDigits = 0;
	bool isOdd = true;
	while(userInput > 0){
		if(isOdd){
			sumOfOddDigits += userInput % 10;
		}else{
			sumOfEvenDigits += userInput % 10;
		}
		userInput /= 10;
		isOdd = !isOdd;
	}
	return abs(sumOfEvenDigits - sumOfOddDigits)%11 == 0?true:false;
}
#endif /* DIVISIBILITYRULES_H_ */
/************************************************* End code *******************************************************/
