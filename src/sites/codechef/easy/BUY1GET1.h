/***************************************************************************************************************** 
 *  File Name   		: BUY1GET1.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\BUY1GET1.h
 *  Created on			: Jan 19, 2014 :: 8:16:30 PM
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
#define ALPHABET_SIZE 52
#define MAX_SIZE 201

/************************************************* Main code  ******************************************************/

#ifndef BUY1GET1_H_
#define BUY1GET1_H_

void BUY1GET1(){
	char userInput[MAX_SIZE];
	unsigned int testCases,inputLength,counter,minCost;
	unsigned int frequencyCounter[ALPHABET_SIZE] = {0};
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%s",userInput);
		inputLength = strlen(userInput);
		for(counter = 0;counter < inputLength;counter++){
			if(userInput[counter] >= 'a' && userInput[counter] <= 'z'){
				frequencyCounter[userInput[counter]-'a']++;
			}else{
				frequencyCounter[userInput[counter]-'A'+26]++;
			}
		}

		for(counter = 0;counter < ALPHABET_SIZE;counter++){
			minCost = (frequencyCounter[counter] / 2) + (frequencyCounter[counter]&1);
			frequencyCounter[counter] = 0;
		}
		printf("%u",frequencyCounter);
	}
}

#endif /* BUY1GET1_H_ */

/************************************************* End code *******************************************************/
