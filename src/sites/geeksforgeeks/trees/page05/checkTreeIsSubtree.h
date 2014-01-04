/***************************************************************************************************************** 
 *  File Name   		: checkTreeIsSubtree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\checkTreeIsSubtree.h
 *  Created on			: Jan 4, 2014 :: 1:23:02 PM
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

#ifndef CHECKTREEISSUBTREE_H_
#define CHECKTREEISSUBTREE_H_

bool areTreesIdentical(tNode *parentPtr,tNode *childPtr){
	if(parentPtr == NULL && childPtr == NULL){
		return true;
	}
	if(parentPtr == NULL || childPtr == NULL){
		return false;
	}
	return parentPtr->value == childPtr->value && areTreesIdentical(parentPtr->left,childPtr->left) && areTreesIdentical(parentPtr->right,childPtr->right);
}

bool isTreeSubTree(tNode *parentPtr,tNode *subtreePtr){
	if(parentPtr == NULL && subtreePtr == NULL){
		return true;
	}
	if(subtreePtr == NULL){
		return true;
	}
	if(parentPtr == NULL){
		return false;
	}
	if(areTreesIdentical(parentPtr,subtreePtr)){
		return true;
	}
	return isTreeSubTree(parentPtr->left,subtreePtr) || isTreeSubTree(parentPtr->right,subtreePtr);
}

bool isTreeSubTreeoptimized(tNode *parentPtr,tNode *subTreePtr){
	if(parentPtr == NULL && subTreePtr == NULL){
		return true;
	}
	if(subTreePtr == NULL){
		return true;
	}
	if(parentPtr == NULL){
		return false;
	}
	if(parentPtr->value == subTreePtr->value){
		if(areTreesIdentical(parentPtr,subTreePtr)){
			return true;
		}
	}
	return isTreeSubTree(parentPtr->left,subTreePtr) || isTreeSubTree(parentPtr->right,subTreePtr);
}

#endif /* CHECKTREEISSUBTREE_H_ */

/************************************************* End code *******************************************************/
