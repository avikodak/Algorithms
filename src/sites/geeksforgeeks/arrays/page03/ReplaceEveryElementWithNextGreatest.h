/***************************************************************************************************************** 
 *  File Name   		: ReplaceEveryElementWithNextGreatest.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\ReplaceEveryElementWithNextGreatest.h
 *  Created on			: Jan 8, 2014 :: 2:18:32 PM
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

#ifndef REPLACEEVERYELEMENTWITHNEXTGREATEST_H_
#define REPLACEEVERYELEMENTWITHNEXTGREATEST_H_

void replaceEveryElementWithNextGreatestON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	int maxVal;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		maxVal = INT_MIN;
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(maxVal < userInput[innerCrawler]){
				maxVal = userInput[innerCrawler];
			}
		}
		userInput[outerCrawler] = maxVal;
	}
}

#endif /* REPLACEEVERYELEMENTWITHNEXTGREATEST_H_ */

/************************************************* End code *******************************************************/
