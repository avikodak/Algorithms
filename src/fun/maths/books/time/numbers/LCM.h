/***************************************************************************************************************** 
 *  File Name   		: LCM.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\LCM.h
 *  Created on			: Jan 23, 2014 :: 7:31:27 PM
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
#include <numeric>
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

#ifndef LCM_H_
#define LCM_H_

unsigned int lcmNaiveMethod(unsigned int firstNumber,unsigned int secondNumber){

}

unsigned int lcm(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return UINT_MAX;
	}
	if(firstNumber == 1  || secondNumber == 1){
		return firstNumber * secondNumber;
	}
	hash_map<unsigned int,unsigned int> primeFactorizationFirstNumber,primeFactorizationSecondNumber;
	hash_map<unsigned int,unsigned int>::iterator itToPrimeFactorization;
	primeFactorizationOptimized(firstNumber,primeFactorizationFirstNumber);
	primeFactorizationOptimized(secondNumber,primeFactorizationSecondNumber);
	unsigned int lcm = 1;
	for(itToPrimeFactorization = primeFactorizationFirstNumber.begin();itToPrimeFactorization != primeFactorizationFirstNumber.end();itToPrimeFactorization++){
		if(primeFactorizationSecondNumber.find(itToPrimeFactorization->first)){
			lcm *= pow(itToPrimeFactorization->first, max(itToPrimeFactorization->second,primeFactorizationSecondNumber[itToPrimeFactorization->first]));
			primeFactorizationSecondNumber.erase(itToPrimeFactorization->first);
		}else{
			lcm *= pow(itToPrimeFactorization->first,itToPrimeFactorization->second);
		}
	}

	for(itToPrimeFactorization = primeFactorizationSecondNumber.begin();;itToPrimeFactorization++){
		lcm *= pow(itToPrimeFactorization->first,itToPrimeFactorization->second);
	}
	return lcm;
}

unsigned int lcmByFindingHCF(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return UINT_MAX;
	}
	if(firstNumber == 1  || secondNumber == 1){
		return firstNumber * secondNumber;
	}
	unsigned int gcdOfNumbers = gcdEuclidIterative(firstNumber,secondNumber);
	return (firstNumber * secondNumber)/gcdOfNumbers;
}

unsigned int lcmOfNumbers(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	unsigned int gcdOfUserInputs = gcdOfNumbers(userInput);
	unsigned int product = 1;
	accumulate(userInput.begin(),userInput.end(),product,multiplies<unsigned int>());
	return gcdOfUserInputs/product;
}

#endif /* LCM_H_ */

/************************************************* End code *******************************************************/
