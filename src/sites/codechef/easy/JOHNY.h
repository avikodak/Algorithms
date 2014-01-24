/***************************************************************************************************************** 
 *  File Name   		: JOHNY.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\JOHNY.h
 *  Created on			: Jan 19, 2014 :: 8:05:30 PM
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
#define MAX_SIZE 1000000000

/************************************************* Main code  ******************************************************/

#ifndef JOHNY_H_
#define JOHNY_H_

int main(){
	int userInput[MAX_SIZE],key;
	unsigned int testCases,noOfInputs,counter,songPosition,lessThanKey;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&noOfInputs);
		for(counter = 0;counter < noOfInputs;counter++){
			scanf("%d",&userInput[counter]);
		}
		scanf("%u",&songPosition);
		key = userInput[songPosition-1];
		lessThanKey = 0;
		for(counter = 0;counter < noOfInputs;counter++){
			if(userInput[counter] < key){
				lessThanKey++;
			}
		}
		printf("%u\n",lessThanKey+1);
	}
}

#endif /* JOHNY_H_ */

/************************************************* End code *******************************************************/
