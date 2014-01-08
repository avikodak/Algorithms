/***************************************************************************************************************** 
 *  File Name   		: segregateEvenOddNumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\segregateEvenOddNumbers.h
 *  Created on			: Jan 6, 2014 :: 8:27:14 PM
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

#ifndef SEGREGATEEVENODDNUMBERS_H_
#define SEGREGATEEVENODDNUMBERS_H_

void segregateEvenOddNumbersON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	unsigned int outerCounter,innerCounter;
	int temp;
	bool isEvenFound = false;
	for(outerCounter  = 0;outerCounter < userInput.size();outerCounter++){
		if(userInput[outerCounter]%2 != 0){
			isEvenFound = false;
			for(innerCounter = 0;innerCounter < userInput.size();innerCounter++){
				if(userInput[innerCounter] % 2 == 0){
					isEvenFound = true;
					break;
				}
			}
			temp = userInput[outerCounter];
			userInput[outerCounter] = userInput[innerCounter];
			userInput[innerCounter] = temp;
		}
	}
}

void segregateEvenOddNumbersONAuxSpace(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	queue<int> oddBucket,evenBucket;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter]%2 == 0){
			oddBucket.push(userInput[counter]);
		}else{
			evenBucket.push(userInput[counter]);
		}
	}
	unsigned int counter = 0;
	while(!oddBucket.empty()){
		userInput[counter++] = oddBucket.front();
		oddBucket.pop();
	}
	while(!evenBucket.empty()){
		userInput[counter++] = evenBucket.front();
		evenBucket.pop();
	}
}

void segregateEvenOddNumbersON(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;
	int temp;
	while(frontCrawler < backCrawler){
		while(userInput[frontCrawler]%2 == 1){
			frontCrawler++;
		}
		while(userInput[backCrawler]%2 == 0 && frontCrawler < backCrawler){
			backCrawler--;
		}
		if(frontCrawler < backCrawler){
			temp = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[backCrawler];
			userInput[backCrawler] = temp;
		}
	}
}

#endif /* SEGREGATEEVENODDNUMBERS_H_ */

/************************************************* End code *******************************************************/
