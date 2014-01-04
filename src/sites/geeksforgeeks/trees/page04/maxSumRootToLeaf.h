/***************************************************************************************************************** 
 *  File Name   		: maxSumRootToLeaf.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\maxSumRootToLeaf.h
 *  Created on			: Jan 4, 2014 :: 6:00:22 PM
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

#ifndef MAXSUMROOTTOLEAF_H_
#define MAXSUMROOTTOLEAF_H_

int maxSumRootToLeaf(tNode *ptr,int runningSum){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return runningSum + ptr->value;
	}
	return max(maxSumRootToLeaf(ptr->left,runningSum+ptr->value),maxSumRootToLeaf(ptr->right,runningSum + ptr->value));
}

int maxSumRootToLeafParentPtr(tPNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		tPNode *currentNode = ptr;
		int sum = 0;
		while(currentNode != NULL){
			sum += currentNode->value;
			currentNode = currentNode->parent;
		}
		return sum;
	}
	return max(maxSumRootToLeafParentPtr(ptr->left),maxSumRootToLeafParentPtr(ptr->right));
}

int maxSumRootToLeafHashmap(tNode *ptr){

}

#endif /* MAXSUMROOTTOLEAF_H_ */

/************************************************* End code *******************************************************/
