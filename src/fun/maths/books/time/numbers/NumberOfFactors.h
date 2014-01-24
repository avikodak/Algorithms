/***************************************************************************************************************** 
 *  File Name   		: NumberOfFactors.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\NumberOfFactors.h
 *  Created on			: Jan 23, 2014 :: 7:47:38 PM
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

#ifndef NUMBEROFFACTORS_H_
#define NUMBEROFFACTORS_H_

unsigned int noOfFactors(unsigned int userInput){
	if(userInput == 0){
		return 0;
	}
	if(userInput == 1){
		return 1;
	}
	unsigned int factorsCount = 2;
	for(unsigned int counter = 2;counter <= (userInput/2);counter++){
		if(userInput%counter == 0){
			factorsCount++;
		}
	}
	return factorsCount;
}

unsigned int noOfFactorsFactorization(unsigned int userInput){
	if(userInput == 0){
		return 0;
	}
	if(userInput == 1){
		return 1;
	}
	unsigned int factorsCounter = 1;
	hash_map<unsigned int,unsigned int> primeFactorization;
	hash_map<unsigned int,unsigned int>::iterator itToPrimeFactorization;
	primeFactorizationOptimized(userInput,primeFactorization);
	for(itToPrimeFactorization = primeFactorization.begin();itToPrimeFactorization != primeFactorization.end();itToPrimeFactorization++){
		factorsCounter *= (1 + itToPrimeFactorization->second);
	}
	return factorsCounter;
}

#endif /* NUMBEROFFACTORS_H_ */

/************************************************* End code *******************************************************/
