/***************************************************************************************************************** 
 *  File Name   		: MaximumProductSubarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\MaximumProductSubarray.h
 *  Created on			: Jan 9, 2014 :: 2:02:22 PM
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

#ifndef MAXIMUMPRODUCTSUBARRAY_H_
#define MAXIMUMPRODUCTSUBARRAY_H_

int maximumProductSubArray(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int outerCrawler,innerCrawler;
	int maxProduct = INT_MIN,currentProduct;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		currentProduct = 1;
		for(innerCrawler = outerCrawler+1;innerCrawler< userInput.size();innerCrawler++){
			currentProduct *= userInput[innerCrawler];
		}
		if(maxProduct < currentProduct){
			maxProduct = currentProduct;
		}
	}
	return maxProduct;
}

int maximumProductSubArrayKandaneAlgo(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	int minEndingHere = 1,maxEndingHere = 1,max = INT_MIN,temp;
	unsigned int counter;

	for(counter = 0;counter< userInput.size();counter++){
		if(userInput[counter] == 0){
			minEndingHere = 1;
			maxEndingHere = 1;
		}else{
			if(userInput[counter] > 0){
				maxEndingHere = maxEndingHere * userInput[counter];
				minEndingHere = min(1,minEndingHere * userInput[counter]);
			}else{
				temp = maxEndingHere;
				maxEndingHere = max(1,minEndingHere*userInput[counter]);
				minEndingHere = maxEndingHere * userInput[counter];
			}
		}
		if(max < maxEndingHere){
			max = maxEndingHere;
		}
	}
	return max;
}

#endif /* MAXIMUMPRODUCTSUBARRAY_H_ */

/************************************************* End code *******************************************************/
