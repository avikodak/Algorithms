/***************************************************************************************************************** 
 *  File Name   		: Factorial.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\Factorial.h
 *  Created on			: Jan 23, 2014 :: 7:46:33 PM
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

#ifndef FACTORIAL_H_
#define FACTORIAL_H_

long long int factorialIterative(unsigned int userInput){
	if(userInput == 0 || userInput == 1){
		return 1;
	}
	unsigned int counter = userInput;
	long long int factorial = 1;
	while(counter > 1){
		factorial *= counter;
		counter--;
	}
	return factorial;
}

long long int factorial(unsigned int userInput){
	if(userInput == 0 || userInput == 1){
		return 1;
	}
	return userInput * factorial(userInput-1);
}

#endif /* FACTORIAL_H_ */

/************************************************* End code *******************************************************/
