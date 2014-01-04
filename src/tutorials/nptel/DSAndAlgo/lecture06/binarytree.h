/***************************************************************************************************************** 
 *  File Name   		: binarytree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture06\binarytree.h
 *  Created on			: Dec 30, 2013 :: 5:33:39 PM
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

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

tNode *createBinaryTree(vector<int> userInput,unsigned int counter){
	if(counter >= userInput.size()){
		return NULL;
	}
	tNode *newNode = (tNode *)malloc(sizeof(tNode));
	newNode->value = userInput[counter];
	newNode->left = createBinaryTree(userInput,2*counter+1);
	newNode->right = createBinaryTree(userInput,2*counter+2);
	return newNode;
}

#endif /* BINARYTREE_H_ */

/************************************************* End code *******************************************************/
