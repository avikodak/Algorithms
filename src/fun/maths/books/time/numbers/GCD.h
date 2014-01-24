/***************************************************************************************************************** 
 *  File Name   		: GCD.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\GCD.h
 *  Created on			: Jan 24, 2014 :: 1:23:50 AM
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

#ifndef GCD_H_
#define GCD_H_

unsigned int gcd(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return UINT_MAX;
	}
	if(firstNumber == 1  || secondNumber == 1){
		return 1;
	}
	hash_map<unsigned int,unsigned int> primeFactorizationFirstNumber,primeFactorizationSecondNumber;
	hash_map<unsigned int,unsigned int>::iterator itToPrimeFactorization;
	primeFactorizationOptimized(firstNumber,primeFactorizationFirstNumber);
	primeFactorizationOptimized(secondNumber,primeFactorizationSecondNumber);
	unsigned int gcd = 1;
	for(itToPrimeFactorization = primeFactorizationFirstNumber.begin();itToPrimeFactorization != primeFactorizationFirstNumber.end();itToPrimeFactorization++){
		if(primeFactorizationSecondNumber.find(itToPrimeFactorization->first)){
			gcd *= pow(itToPrimeFactorization->first,min(itToPrimeFactorization->second,primeFactorizationSecondNumber[itToPrimeFactorization->first]));
		}
	}
	return gcd;
}

unsigned int gcdEuclidIterative(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return UINT_MAX;
	}
	if(firstNumber == 1  || secondNumber == 1){
		return 1;
	}
	if(firstNumber > secondNumber){
		swap(firstNumber,secondNumber);
	}
	unsigned int remainder;
	while(firstNumber>1){
		remainder = secondNumber%firstNumber;
		if(remainder == 0){
			return firstNumber;
		}
		secondNumber = firstNumber;
		firstNumber = remainder;
	}
	return 1;
}

unsigned int gcdEuclid(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return UINT_MAX;
	}
	if(firstNumber == 1  || secondNumber == 1){
		return 1;
	}
	if(firstNumber > secondNumber){
		swap(firstNumber,secondNumber);
	}

}

unsigned int gcdOfNumbers(vector<unsigned int> userInputs){
	if(userInputs.size() == 0){
		return UINT_MAX;
	}
	if(userInputs.size() == 1){
		return userInputs[0];
	}
	unsigned int gcdOfNumbers = gcdEuclid(userInputs[0],userInputs[1]);
	for(unsigned int counter = 2;counter <= userInputs;counter++){
		gcdOfNumbers = gcdEuclid(userInputs[counter],gcdOfNumbers);
	}
	return gcdOfNumbers;
}

#endif /* GCD_H_ */

/************************************************* End code *******************************************************/
