/***************************************************************************************************************** 
 *  File Name   		: SortNearlySortedArrays.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\SortNearlySortedArrays.h
 *  Created on			: Jan 8, 2014 :: 8:42:58 PM
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

#ifndef SORTNEARLYSORTEDARRAYS_H_
#define SORTNEARLYSORTEDARRAYS_H_

void nearlySortedAlgorithm(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int outerCrawler,innerCrawler;
	int key;
	for(outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
		innerCrawler = outerCrawler-1;
		key = userInput[outerCrawler];
		while(userInput[innerCrawler+1] < userInput[innerCrawler] && innerCrawler>=0){
			swab(userInput[innerCrawler],userInput[innerCrawler+1]);
		}
		userInput[innerCrawler] = key;
	}
}



void nearlySortedAlgorithmBST(vector<int> userInput,unsigned int kValue){
	if(userInput.size() == 0){
		return;
	}
	tNode *bst = NULL;
	for(unsigned int counter = 0;counter < kValue;counter++){
		insertNodeBST(&bst,userInput[counter]);
	}
	for(unsigned int counter = kValue;counter < userInput.size();counter++){

	}
}

#endif /* SORTNEARLYSORTEDARRAYS_H_ */

/************************************************* End code *******************************************************/
