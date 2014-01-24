/***************************************************************************************************************** 
 *  File Name   		: PowerUnitDigit.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\books\time\numbers\PowerUnitDigit.h
 *  Created on			: Jan 23, 2014 :: 7:36:26 PM
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

#ifndef POWERUNITDIGIT_H_
#define POWERUNITDIGIT_H_

unsigned int unitsDigitsInPower(unsigned int base,unsigned int radical){
	vector<unsigned int> unitsDigit;
	unitsDigit.push_back(base%10);
	unsigned int runner = base*base;
	unsigned int period = 1;
	while(runner%10 != unitsDigit[0]){
		unitsDigit.push_back(runner%10);
		period++;
	}
	return unitsDigit[radical%period];
}

#endif /* POWERUNITDIGIT_H_ */

/************************************************* End code *******************************************************/
