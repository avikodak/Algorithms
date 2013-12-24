/***************************************************************************************************************** 
 *  File Name   		: llNode.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\common\ds\llNode.h
 *  Created on			: Dec 13, 2013 :: 2:20:05 AM
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

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct llNode{
	int value;
	llNode *next;
};

struct dllNode{
	int value;
	dllNode *next;
	dllNode *prev;
};

struct llHashmap{
	hash_map<unsigned int,llNode *> indexNodeMap;
};

#endif /* LINKEDLIST_H_ */
/************************************************* End code *******************************************************/
