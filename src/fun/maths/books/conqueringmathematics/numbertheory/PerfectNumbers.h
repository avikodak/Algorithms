/***************************************************************************************************************** 
 *  File Name   		: PerfectNumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\conqueringmathematics\numbertheory\PerfectNumbers.h
 *  Created on			: Jan 21, 2014 :: 1:36:32 PM
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

#ifndef PERFECTNUMBERS_H_
#define PERFECTNUMBERS_H_

bool perfectNumber(unsigned int userInput){
	if(userInput == 0){
		return false;
	}
	if(userInput == 1){
		return true;
	}
	unsigned int sumOfDivisors = 1;
	for(unsigned int counter = 0;counter <= (userInput/2);counter++){
		if(userInput%counter == 0){
			sumOfDivisors += counter;
		}
	}
	return userInput == sumOfDivisors?true:false;
}

bool perfectNumberSumFactorization(unsigned int userInput){
	if(userInput == 0){
		return false;
	}
	if(userInput == 1){
		return true;
	}
	hash_map<unsigned int,unsigned int> primeFactorsUserInput;

}

#endif /* PERFECTNUMBERS_H_ */

/************************************************* End code *******************************************************/
