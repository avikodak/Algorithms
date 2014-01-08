/***************************************************************************************************************** 
 *  File Name   		: minLengthUnsortedSubarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\minLengthUnsortedSubarray.h
 *  Created on			: Jan 7, 2014 :: 10:49:55 AM
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

#ifndef MINLENGTHUNSORTEDSUBARRAY_H_
#define MINLENGTHUNSORTEDSUBARRAY_H_

unsigned int minimumLengthUnsortedSubarray(vector<int> userInput){
	if(userInput.size() == 0|| userInput.size() == 1){
		return 0;
	}
	unsigned int minIndex = 0,maxIndex = userInput.size()-1;

}

#endif /* MINLENGTHUNSORTEDSUBARRAY_H_ */

/************************************************* End code *******************************************************/
