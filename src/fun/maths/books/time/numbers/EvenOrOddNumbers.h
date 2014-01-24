/***************************************************************************************************************** 
 *  File Name   		: EvenOrOddNumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\EvenOrOddNumbers.h
 *  Created on			: Jan 23, 2014 :: 7:49:13 PM
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

#ifndef EVENORODDNUMBERS_H_
#define EVENORODDNUMBERS_H_

bool isNumberEven(unsigned int userInput){
	return userInput%2 == 0?true:false;
}

bool isNumberEvenAndOperator(unsigned int userInput){
	return userInput&1 == 1?true:false;
}
#endif /* EVENORODDNUMBERS_H_ */

/************************************************* End code *******************************************************/
