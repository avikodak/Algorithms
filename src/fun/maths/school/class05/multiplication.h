/***************************************************************************************************************** 
 *  File Name   		: multiplication.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\multiplication.h
 *  Created on			: Dec 26, 2013 :: 11:15:22 PM
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

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

/* Assuming constraint that only one digit multiplication is allowed*/
unsigned int multiplicationOfNumbers(unsigned int multiplicand,unsigned int multiplier){
	if(multiplicand == 0 || multiplier == 0){
		return multiplicand;
	}
	if(multiplicand == 1 || multiplier == 1){
		return multiplicand ^ multiplier ^ 1; // check this
	}
	if(multiplicand < multiplier){
		unsigned int temp  = multiplicand;
		multiplicand = multiplier;
		multiplier = temp;
	}
	unsigned int result;
	while(multiplier > 0){

	}
}

unsigned int multiplicationByRepeatedAdditionIterative(unsigned int multiplicand,unsigned int multiplier){
	if(multiplicand == 0 || multiplier == 0){
		return multiplicand;
	}
	if(multiplicand == 1 || multiplier == 1){
		return multiplicand ^ multiplier ^ 1; // check this
	}
	unsigned int result = 0;
	for(unsigned int counter = 0;counter < multiplier;counter++){
		result += multiplicand;
	}
	return result;
}

unsigned int multiplicationByRepeatedAddition(unsigned int multiplicand,unsigned int multiplier){
	if(multiplier == 0){
		return 0;
	}
	return multiplicand + multiplicationByRepeatedAddition(multiplicand,multiplier-1);
}

unsigned int *divisionByRepeatedSubstrationIterative(unsigned int divisor,unsigned int dividend){
	if(divisor == 0){
		return NULL;
	}
	unsigned int remainder,quotient;
	while(dividend > divisor){
		quotient += 1;
		dividend -= divisor;
	}
	remainder = dividend;
	unsigned int result[2] = {quotient,remainder};
	return result;
}

#endif /* MULTIPLICATION_H_ */

/************************************************* End code *******************************************************/

