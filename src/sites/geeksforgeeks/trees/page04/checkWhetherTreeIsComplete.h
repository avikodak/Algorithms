/***************************************************************************************************************** 
 *  File Name   		: checkWhetherTreeIsComplete.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\checkWhetherTreeIsComplete.h
 *  Created on			: Jan 4, 2014 :: 6:40:00 PM
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

#ifndef CHECKWHETHERTREEISCOMPLETE_H_
#define CHECKWHETHERTREEISCOMPLETE_H_

bool checkWhetherTreeIsCompleteLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
}

void countNumberOfNodesInLevel(tNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelCountMap){
	if(ptr == NULL){
		return;
	}
	countNumberOfNodesInLevel(ptr->left,level+1,levelCountMap);
	countNumberOfNodesInLevel(ptr->right,level+1,levelCountMap);
	if((levelCountMap.find(level))!=levelCountMap.end()){
		levelCountMap[level] += 1;
	}else{
		levelCountMap.insert(pair<unsigned int,unsigned int>(level,1));
	}
}

bool checkWhetherTreeIsCompleteHashmap(tNode *ptr){

}

bool isTreeCompleteIterative(tNode *ptr){

}

#endif /* CHECKWHETHERTREEISCOMPLETE_H_ */

/************************************************* End code *******************************************************/
