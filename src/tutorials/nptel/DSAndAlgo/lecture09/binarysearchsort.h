/***************************************************************************************************************** 
 *  File Name   		: binarysearchsort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture09\binarysearchsort.h
 *  Created on			: Dec 31, 2013 :: 12:20:55 PM
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

#ifndef BINARYSEARCHSORT_H_
#define BINARYSEARCHSORT_H_

void bstSort(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	tNode *bstTree = NULL;
	createBST(&bstTree,userInput);
	stack<tNode *> auxSpace;
	tNode *currentNode = bstTree;
	unsigned int counter = -1;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			userInput[++counter] = currentNode->value;
			auxSpace.pop();
			currentNode = currentNode->right;
		}
	}
}

#endif /* BINARYSEARCHSORT_H_ */
/************************************************* End code *******************************************************/
