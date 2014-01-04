/***************************************************************************************************************** 
 *  File Name   		: connectNodesInSameLevel.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\connectNodesInSameLevel.h
 *  Created on			: Jan 4, 2014 :: 5:01:28 PM
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

#ifndef CONNECTNODESINSAMELEVEL_H_
#define CONNECTNODESINSAMELEVEL_H_

struct tNodeNextRight{
	int value;
	tNodeNextRight *left;
	tNodeNextRight *right;
	tNodeNextRight *nextRight;
};

void connectNodesAtSameLevel(tNodeNextRight *ptr){
	if(ptr == NULL){
		return;
	}
	queue<tNodeNextRight *> auxSpace;
}

#endif /* CONNECTNODESINSAMELEVEL_H_ */

/************************************************* End code *******************************************************/
