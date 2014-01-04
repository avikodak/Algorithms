/***************************************************************************************************************** 
 *  File Name   		: constructTreeFromPreOrder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\constructTreeFromPreOrder.h
 *  Created on			: Jan 4, 2014 :: 7:27:41 PM
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

#ifndef CONSTRUCTTREEFROMPREORDER_H_
#define CONSTRUCTTREEFROMPREORDER_H_

tNode *createTreeFromPreorder(vector<int> preOrderValues,vector<bool> nodeStatus,unsigned int &index){
	if(index >= nodeStatus.size()){
		return NULL;
	}
	tNode *newNode = (tNode *)malloc(sizeof(tNode *));
	newNode->value = preOrderValues[index];
	newNode->left = NULL;
	newNode->right = NULL;
	index += 1;
	if(nodeStatus[index]){
		newNode->left = createTreeFromPreorder(preOrderValues,nodeStatus,index);
		newNode->right = createTreeFromPreorder(preOrderValues,nodeStatus,index);
	}
	return newNode;
}

#endif /* CONSTRUCTTREEFROMPREORDER_H_ */

/************************************************* End code *******************************************************/
