/***************************************************************************************************************** 
 *  File Name   		: LCMOfFractions.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\conqueringmathematics\numbertheory\LCMOfFractions.h
 *  Created on			: Jan 23, 2014 :: 8:04:45 PM
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

#ifndef LCMOFFRACTIONS_H_
#define LCMOFFRACTIONS_H_

struct fraction{
	unsigned int numerator;
	unsigned int denominator;
};

fraction *lcmOfFractions(vector<fraction> userInput){
	if(userInput.size() == 0){
		return NULL;
	}
	if(userInput.size() == 1){
		return userInput[0];
	}

}

#endif /* LCMOFFRACTIONS_H_ */

/************************************************* End code *******************************************************/
