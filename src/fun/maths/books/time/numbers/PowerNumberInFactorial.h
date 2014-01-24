/***************************************************************************************************************** 
 *  File Name   		: PowerNumberInFactorial.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\PowerNumberInFactorial.h
 *  Created on			: Jan 23, 2014 :: 7:36:50 PM
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

#ifndef POWERNUMBERINFACTORIAL_H_
#define POWERNUMBERINFACTORIAL_H_

unsigned int powerNumberInFactorial(unsigned int userInput,unsigned int number){
	unsigned int powerNumbers = 0;
	unsigned int runningNumber = number;
	while(userInput/runningNumber > 1){
		powerNumbers += userInput/runningNumber;
		runningNumber *= runningNumber;
	}
	return powerNumbers;
}

unsigned int numberZerosInFactorial(unsigned int userInput){
	unsigned int powerOfFive;
	powerOfFive = powerNumberInFactorial(userInput,5);
	return powerOfFive;
}

#endif /* POWERNUMBERINFACTORIAL_H_ */

/************************************************* End code *******************************************************/
