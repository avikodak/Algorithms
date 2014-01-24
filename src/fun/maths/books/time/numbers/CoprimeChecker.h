/*****************************************************************************************************************
 *  File Name   		: CoprimeChecker.h
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\CoprimeChecker.h
 *  Created on			: Jan 23, 2014 :: 7:51:36 PM
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

#ifndef COPRIMECHECKER_H_
#define COPRIMECHECKER_H_

bool areNumbersCoprime(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 1 || secondNumber == 1){
		return true;
	}
	unsigned int gcdOfNumbers = gcdEuclid(firstNumber,secondNumber);
	return gcdOfNumbers == 1?true:false;
}

#endif /* COPRIMECHECKER_H_ */

/************************************************* End code *******************************************************/
