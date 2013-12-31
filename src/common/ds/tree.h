/* 
 *  File Name   		: tree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\common\ds\tree.h
 *  Created on			: Dec 10, 2013 :: 1:04:21 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 */

using namespace std;
using namespace __gnu_cxx;

/******************User Includes*******************************/
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
/********************User defined constants*********************/
#define null NULL


#ifndef TREE_H_
#define TREE_H_

struct tNode{
	int value;
	tNode *left;
	tNode *right;
};

struct tPNode{
	int value;
	tPNode *left;
	tPNode *right;
	tPNode *parent;
};

struct tNodeAuxVal{
	int value;
	unsigned int auxValue;
	tNodeAuxVal *left;
	tNodeAuxVal *right;
};

struct tPNodeAuxVal{
	int value;
	unsigned int auxValue;
	tPNodeAuxVal *left;
	tPNodeAuxVal *right;
	tPNodeAuxVal *parent;
};

struct tHashmap{
	hash_map<unsigned int,tNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
};

struct tLHashMap{
	hash_map<unsigned int,vector<tNode *> > levelNodeMap;
	hash_map<uint32_t,unsigned int> nodeLevelMap;
};

#endif /* TREE_H_ */
