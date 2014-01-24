/***************************************************************************************************************** 
 *  File Name   		: bucketSort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture23\bucketSort.h
 *  Created on			: Jan 24, 2014 :: 10:22:49 PM
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
#include <numeric>
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
#define SIZE 10001
/************************************************* Main code  ******************************************************/

#ifndef BUCKETSORT_H_
#define BUCKETSORT_H_

void bucketSort(vector<int> userInput){
	int frequencyCounter[SIZE] = {0};
	int userInput;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		frequencyCounter[userInput[counter]]+=1;
		totalnumbers--;
	}
	for(unsigned int counter = 0;counter < SIZE;counter++){
		while(frequencyCounter[counter]--){
			printf("%d\n",counter);
		}
	}
}


#endif /* BUCKETSORT_H_ */

/************************************************* End code *******************************************************/
