/***************************************************************************************************************** 
 *  File Name   		: verticalSumTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\verticalSumTree.h
 *  Created on			: Jan 4, 2014 :: 5:52:41 PM
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

#ifndef VERTICALSUMTREE_H_
#define VERTICALSUMTREE_H_

void verticalSumTree(tNode *ptr,int verticalIndex,hash_map<int,int> &verticalSumMap){
	if(ptr == NULL){
		return;
	}
	if(verticalSumMap.find(verticalIndex) != verticalSumMap.end()){
		verticalSumMap[verticalIndex] += ptr->value;
	}else{
		verticalSumMap.insert(pair<int,int>(verticalIndex,ptr->value));
	}
	verticalSumTree(ptr->left,verticalIndex-1,verticalSumMap);
	verticalSumTree(ptr->right,verticalIndex+1,verticalSumMap);
}

#endif /* VERTICALSUMTREE_H_ */

/************************************************* End code *******************************************************/
