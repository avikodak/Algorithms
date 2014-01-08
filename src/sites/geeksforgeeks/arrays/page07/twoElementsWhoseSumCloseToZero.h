/***************************************************************************************************************** 
 *  File Name   		: twoElementsWhoseSumCloseToZero.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\twoElementsWhoseSumCloseToZero.h
 *  Created on			: Jan 5, 2014 :: 11:50:15 PM
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

#ifndef TWOELEMENTSWHOSESUMCLOSETOZERO_H_
#define TWOELEMENTSWHOSESUMCLOSETOZERO_H_

int *twoValuesSumCloseToZeroON2(vector<int> userInput){
	if(userInput.size() == 0|| userInput.size() == 1){
		return NULL;
	}
	int twoValues[2];
	unsigned int sumCloseToZero = INT_MAX,difference;
	for(unsigned int outerCounter=0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			difference = abs(userInput[innerCounter] + userInput[outerCounter]);
			if(difference < sumCloseToZero ){
				sumCloseToZero = difference;
				twoValues[0] = userInput[outerCounter];
				twoValues[1] = userInput[innerCounter];
			}
		}
	}
	return twoValues;
}

int *twoValuesSumCloseToZeroONLOGN(vector<int> userInput){
	if(userInput.size() == 0|| userInput.size() == 1){
		return NULL;
	}
	int twoValues[2],sum,min_sum = INT_MAX;
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;

	while(frontCrawler < backCrawler){
		sum = userInput[frontCrawler] + userInput[backCrawler];
		if(abs(min_sum) > abs(sum)){
			min_sum = sum;
		}
		if(sum > 0){
			backCrawler--;
		}else{
			frontCrawler++;
		}
	}

}

#endif /* TWOELEMENTSWHOSESUMCLOSETOZERO_H_ */

/************************************************* End code *******************************************************/
