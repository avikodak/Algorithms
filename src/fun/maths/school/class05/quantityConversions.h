/***************************************************************************************************************** 
 *  File Name   		: quantityConversions.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\quantityConversions.h
 *  Created on			: Dec 26, 2013 :: 11:39:16 PM
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
#define ML 1
#define LITER 1000 * ML

/************************************************* Main code  ******************************************************/
#ifndef QUANTITYCONVERSIONS_H_
#define QUANTITYCONVERSIONS_H_

long long int converIntoMilliliters(unsigned int noLiter,unsigned int noMilliliter){
	long long int result = 0;
	result += noLiter * LITER;
	result += noMilliliter;
	return result;
}

hash_map<string,unsigned int> convertIntoUnits(long long int userInputml){
	hash_map<string,unsigned int> respectiveUnitsAmounts;
	unsigned int noLiter = userInputml / LITER;
	userInputml -=  noLiter * LITER;
	respectiveUnitsAmounts.insert(pair<string,unsigned int>("liters",noLiter));
	respectiveUnitsAmounts.insert(pair<string,unsigned int>("milliliter",userInputml));
	return respectiveUnitsAmounts;
}
#endif /* QUANTITYCONVERSIONS_H_ */
/************************************************* End code *******************************************************/
