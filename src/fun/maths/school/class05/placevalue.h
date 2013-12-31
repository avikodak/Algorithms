/***************************************************************************************************************** 
 *  File Name   		: placevalue.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\placevalue.h
 *  Created on			: Dec 26, 2013 :: 10:55:44 PM
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

#ifndef PLACEVALUE_H_
#define PLACEVALUE_H_

vector<unsigned int> getPlaceValue(unsigned int userInput,unsigned int digit){
	vector<unsigned int> placeValues;
	if(digit == 0){
		placeValues.push_back(0);
		return placeValues;
	}
	unsigned int temp = userInput;
	unsigned int remainder;
	unsigned int counter = 0;
	while(temp >= 0){
		remainder = userInput % 10;
		userInput /= 10;
		if(remainder == digit){
			placeValues.push_back(digit * pow(10,counter));
		}
		counter += 1;
	}
	return placeValues;
}

#endif /* PLACEVALUE_H_ */
/************************************************* End code *******************************************************/
