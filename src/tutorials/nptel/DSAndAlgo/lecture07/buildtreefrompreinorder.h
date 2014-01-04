/***************************************************************************************************************** 
 *  File Name   		: buildtreefrompreinorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture07\buildtreefrompreinorder.h
 *  Created on			: Dec 30, 2013 :: 5:43:40 PM
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

#ifndef BUILDTREEFROMPREINORDER_H_
#define BUILDTREEFROMPREINORDER_H_

tNode *buildTreeFromPreInorder(vector<int> preOrder,vector<int> inOrder,hash_map<int,int> inOrderValueIndexMap,unsigned int preOrderStartIndex,unsigned int preOrderEndIndex,unsigned int inOrderStartIndex,unsigned int inOrderEndIndex){
	if(preOrder.size() == 0 || inOrder.size() == 0 || preOrderStartIndex > preOrderEndIndex || inOrderStartIndex > inOrderEndIndex){
		return NULL;
	}
	tNode *newNode;
	newNode = (tNode *)malloc(sizeof(tNode));
	newNode->value = preOrder[preOrderStartIndex];
	unsigned int inOrderIndex = inOrderValueIndexMap.find(newNode->value);

	if(inOrderIndex < inOrderStartIndex || inOrderIndex > inOrderEndIndex){
		printf("Cannot build the tree");
		return NULL;
	}
	newNode->left = buildTreeFromPreInorder(preOrder,inOrder,inOrderValueIndexMap,preOrderStartIndex+1,preOrderStartIndex+(inOrderIndex - inOrderStartIndex),inOrderStartIndex,inOrderIndex-1);
	newNode->right = buildTreeFromPreInorder(preOrder,inOrder,inOrderValueIndexMap,preOrderStartIndex + (inOrderIndex - inOrderStartIndex) + 1,preOrderEndIndex,inOrderIndex+1,inOrderEndIndex);
	return newNode;
}

#endif /* BUILDTREEFROMPREINORDER_H_ */

/************************************************* End code *******************************************************/
