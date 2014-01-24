/***************************************************************************************************************** 
 *  File Name   		: PrimeFactorization.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\topcoder\number theory\PrimeFactorization.h
 *  Created on			: Jan 23, 2014 :: 7:33:33 PM
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

#ifndef PRIMEFACTORIZATION_H_
#define PRIMEFACTORIZATION_H_

hash_map<unsigned int,unsigned int> primeFactorization(unsigned int userInput){
	hash_map<unsigned int,unsigned int> factorsOfUserInput;
	if(userInput == 0 || userInput == 1){
		return factorsOfUserInput;
	}
	unsigned int runner = userInput;
	for(unsigned int counter = 2;counter <= sqrt(userInput);counter++){
		if(userInput%counter == 0){
			if(factorsOfUserInput.find(counter) != factorsOfUserInput.end()){
				factorsOfUserInput[counter]++;
			}else{
				factorsOfUserInput.insert(pair<unsigned int,unsigned int>(counter,1));
			}
			userInput /= counter;
		}
	}
	return factorsOfUserInput;
}

hash_map<unsigned int,unsigned int> primeFactorizationOptimisedIterative(unsigned int userInput){
	hash_map<unsigned int,unsigned int> factorsOfUserInput;
	if(userInput == 0 || userInput == 1){
		return factorsOfUserInput;
	}
	unsigned int squareRootOfNumber;
	do{
		while(userInput&1 == 0){
			if(factorsOfUserInput.find(2) != factorsOfUserInput.end()){
				factorsOfUserInput[2]++;
			}else{
				factorsOfUserInput.insert(pair<unsigned int,unsigned int>(2,1));
			}
			userInput /= 2;
		}
		squareRootOfNumber = sqrt(userInput);
		for(unsigned int counter = 3;counter <= squareRootOfNumber;counter+=2){
			if(userInput%counter == 0){
				if(factorsOfUserInput.find(counter) != factorsOfUserInput.end()){
					factorsOfUserInput[counter]++;
				}else{
					factorsOfUserInput.insert(pair<unsigned int,unsigned int>(counter,1));
				}
				userInput /= counter;
				break;
			}
		}
	}while(userInput > 1);
	return factorsOfUserInput;
}

void primeFactorizationOptimized(unsigned int userInput,hash_map<unsigned int,unsigned int> &factors){
	if(userInput <= 1){
		return;
	}
	while(userInput%2 == 0){
		if(factors.find(2) != factors.end()){
			factors[2]++;
		}else{
			factors.insert(pair<unsigned int,unsigned int>(2,1));
		}
		userInput /= 2;
	}
	for(unsigned int counter = 3;counter < sqrt(userInput);counter+=2){
		if(userInput%counter == 0){
			if(factors.find(counter) != factors.end()){
				factors[counter]++;
			}else{
				factors.insert(pair<unsigned int,unsigned int>(counter,1));
			}
			userInput /= counter;
			break;
		}
	}
	primeFactorizationOptimized(userInput,factors);
}

#endif /* PRIMEFACTORIZATION_H_ */

/************************************************* End code *******************************************************/
