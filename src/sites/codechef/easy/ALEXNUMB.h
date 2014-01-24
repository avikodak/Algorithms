/***************************************************************************************************************** 
 *  File Name   		: ALEXNUMB.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\ALEXNUMB.h
 *  Created on			: Jan 20, 2014 :: 11:52:03 AM
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

#ifndef ALEXNUMB_H_
#define ALEXNUMB_H_

void ALEXNUMB(){
	unsigned int testCases,noOfUserInputs,counter;
	long long int userInput,result; // actually we dont need input this algo runs in o(1)
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&noOfUserInputs);
		for(counter = 0;counter < noOfUserInputs;counter++){
			scanf("%lld",&userInput);
		}
		result = (noOfUserInputs * (noOfUserInputs+1))/2;
		printf("%d\n",result);
	}
}

#endif /* ALEXNUMB_H_ */

/************************************************* End code *******************************************************/
