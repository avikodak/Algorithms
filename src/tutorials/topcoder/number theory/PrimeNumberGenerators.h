/***************************************************************************************************************** 
 *  File Name   		: PrimeNumberGenerators.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\topcoder\number theory\PrimeNumberGenerators.h
 *  Created on			: Jan 23, 2014 :: 7:34:31 PM
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
#define MAX_SIZE 100001
/************************************************* Main code  ******************************************************/

#ifndef PRIMENUMBERGENERATORS_H_
#define PRIMENUMBERGENERATORS_H_

vector<unsigned int> generatePrimeNumbersNaive(unsigned int start,unsigned int end){
	if(start > end){
		swap(start,end);
	}
	vector<unsigned int> primeNumbers(MAX_SIZE);
	if(end == 0 || end == 1){
		return primeNumbers;
	}
	if(start >= 2){
		primeNumbers.push_back(2);
	}
	if(end == 2){
		return primeNumbers;
	}
	for(unsigned int counter = start;counter <= end;counter++){
		if(counter&1 == 1){
			if(checkIfNumberIsPrime(counter)){
				primeNumbers.push_back(counter);
			}
		}
	}
	return primeNumbers;
}

vector<unsigned int> generatePrimeNumbers(unsigned int start,unsigned int end){
	if(start > end){
		swap(start,end);
	}
	vector<unsigned int> primeNumbers(MAX_SIZE);
	bool flags[MAX_SIZE] = {true};
	if(end == 0 || end == 1){
		return primeNumbers;
	}
	if(start >= 2){
		primeNumbers.push_back(2);
	}
	if(end == 2){
		return primeNumbers;
	}
	unsigned int outerCounter,innerCounter,product;
	for(outerCounter = 3;outerCounter < end;outerCounter++){
		for(innerCounter = 2;outerCounter * innerCounter <= end;innerCounter++){
			product = outerCounter * innerCounter;
			if(product & 1 == 1){
				flags[(product-1)/2] = false;
			}
		}
	}
	for(unsigned int counter = start;counter <= end;counter++){
		if(flags[counter]){
			primeNumbers.push_back(2*counter+1);
		}
	}
	return primeNumbers;
}

#endif /* PRIMENUMBERGENERATORS_H_ */

/************************************************* End code *******************************************************/
