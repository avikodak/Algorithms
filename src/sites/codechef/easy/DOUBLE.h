/***************************************************************************************************************** 
 *  File Name   		: DOUBLE.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\DOUBLE.h
 *  Created on			: Jan 17, 2014 :: 7:58:16 PM
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

#ifndef DOUBLE_H_
#define DOUBLE_H_

void DOUBLE(){
	unsigned long long int userInput;
	unsigned int testCases;
	scanf("%d",&testCases);
	while(testCases--){
		scanf("%lld",&userInput);
		if(userInput&1){
			printf("%lld\n",userInput-1);
		}else{
			printf("%lld\n",userInput);
		}
	}
}

#endif /* DOUBLE_H_ */

/************************************************* End code *******************************************************/
