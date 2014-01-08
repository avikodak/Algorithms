/***************************************************************************************************************** 
 *  File Name   		: segregate0s1s.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\segregate0s1s.h
 *  Created on			: Jan 5, 2014 :: 11:55:05 PM
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

#ifndef SEGREGATE0S1S_H_
#define SEGREGATE0S1S_H_

void segregate0s1sON2(vector<bool> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	unsigned int outerCounter,innerCounter;
	bool isFound;
	for(outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if(userInput[outerCounter]){
			continue;
		}
		isFound = false;
		for(innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(!userInput[innerCounter]){
				userInput[outerCounter] = false;
				userInput[innerCounter] = true;
			}
		}
		if(!isFound){
			break;
		}
	}
}

void segregate0s1sON(vector<bool> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	unsigned int frontCrawler = 0,secondCrawler = userInput.size()-1;
	while(frontCrawler  < secondCrawler){
		while(!userInput[frontCrawler]){
			frontCrawler++;
		}
		while(userInput[secondCrawler] && frontCrawler < secondCrawler){
			secondCrawler--;
		}
		if(frontCrawler < secondCrawler){
			userInput[frontCrawler] = false;
			userInput[secondCrawler] = true;
		}
	}
}

void segregate0s1sONCounter(vector<bool> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	unsigned int trueCounter = 0,falseCounter = 0;
	for(unsigned int counter  =0;counter < userInput.size();counter++){
		if(userInput[counter]){
			trueCounter++;
		}else{
			falseCounter++;
		}
	}
	unsigned int fillCounter = 0;
	while(falseCounter){
		userInput[fillCounter] = false;
		falseCounter--;
		fillCounter++;
	}
	while(trueCounter){
		userInput[fillCounter] = true;
		trueCounter--;
		fillCounter++;
	}
}

bool sortFunc(bool first,bool second){
	return first == false?true:false;
}

void segregate0s1sSorting(vector<bool> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	sort(userInput.begin(),userInput.end(),sortFunc);
}

#endif /* SEGREGATE0S1S_H_ */

/************************************************* End code *******************************************************/
