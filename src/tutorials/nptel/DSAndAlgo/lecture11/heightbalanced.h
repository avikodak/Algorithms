/***************************************************************************************************************** 
 *  File Name   		: heightbalanced.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture11\heightbalanced.h
 *  Created on			: Dec 31, 2013 :: 1:47:04 PM
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

#ifndef HEIGHTBALANCED_H_
#define HEIGHTBALANCED_H_

unsigned int heightOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1 + max(ptr->left,ptr->right);
}

bool isTreeHeightBalanced(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	if(abs(heightOfTree(ptr->left)-heightOfTree(ptr->right)) != 1){
		return false;
	}
	return isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
}

unsigned int isTreeHeightBalancedBottomTop(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int leftHeight = isTreeHeightBalancedBottomTop(ptr->left);
	if(leftHeight == INT_MAX){
		return INT_MAX;
	}
	unsigned int rightHeight = isTreeHeightBalancedBottomTop(ptr->right);
	if(rightHeight == INT_MAX){
		return INT_MAX;
	}
	return abs(leftHeight - rightHeight) == 1?1+max(leftHeight,rightHeight):INT_MAX;
}
#endif /* HEIGHTBALANCED_H_ */

/************************************************* End code *******************************************************/
