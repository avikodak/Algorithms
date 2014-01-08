/***************************************************************************************************************** 
 *  File Name   		: SmallestNumberMissing.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\SmallestNumberMissing.h
 *  Created on			: Jan 8, 2014 :: 1:15:14 PM
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

#ifndef SMALLESTNUMBERMISSING_H_
#define SMALLESTNUMBERMISSING_H_

int smallestMissingNumber(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int temp;
	while(frontCrawler < rearCrawler){
		while(userInput[frontCrawler] < 0 && frontCrawler < rearCrawler){
			frontCrawler++;
		}
		while(userInput[rearCrawler]>=0 && frontCrawler < rearCrawler){
			rearCrawler--;
		}
		if(frontCrawler < rearCrawler){
			temp = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[rearCrawler];
			userInput[rearCrawler] = temp;
			frontCrawler++;
			rearCrawler--;
		}
	}

}

#endif /* SMALLESTNUMBERMISSING_H_ */

/************************************************* End code *******************************************************/
