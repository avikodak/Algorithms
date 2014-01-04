/***************************************************************************************************************** 
 *  File Name   		: buildtreefrompostinorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture07\buildtreefrompostinorder.h
 *  Created on			: Dec 30, 2013 :: 5:48:37 PM
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

#ifndef BUILDTREEFROMPOSTINORDER_H_
#define BUILDTREEFROMPOSTINORDER_H_

tNode *buildTreeFromPostInorder(vector<int> postOrder,vector<int> inOrder,hash_map<int,unsigned int> inOrderValueIndexMap,unsigned int postOrderStartIndex,unsigned int postOrderEndIndex,unsigned int inOrderStartIndex,unsigned int inOrderEndIndex){
	if(postOrder.size() == 0 || inOrder.size() == 0 || postOrderStartIndex > postOrderEndIndex || inOrderStartIndex > inOrderEndIndex){
		return NULL;
	}
	tNode *newNode = (tNode *)malloc(sizeof(tNode));
	newNode->value = postOrder[postOrderEndIndex];
	unsigned int inorderIndex;
	newNode->left = buildTreeFromPostInorder(postOrder,inOrder,inOrderValueIndexMap,postOrderStartIndex,postOrderStartIndex + (inOrderStartIndex - inorderIndex),inOrderStartIndex,inorderIndex - 1);
	newNode->right = buildTreeFromPostInorder(postOrder,inOrder,inOrderValueIndexMap,postOrderStartIndex + (inOrderStartIndex - inorderIndex) + 1,postOrderEndIndex,inorderIndex + 1,inOrderEndIndex);
	return newNode;
}

#endif /* BUILDTREEFROMPOSTINORDER_H_ */
/************************************************* End code *******************************************************/
