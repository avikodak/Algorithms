/***************************************************************************************************************** 
 *  File Name   		: linearprobing.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture05\linearprobing.h
 *  Created on			: Dec 30, 2013 :: 11:59:03 AM
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
#define SIZE_OF_HASH_MAP 20
#define DELETION_MARKER INT_MIN
#define EMPTY_MARKER INT_MAX

/************************************************* Main code  ******************************************************/

#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_

unsigned int hashmap[SIZE_OF_HASH_MAP] = {EMPTY_MARKER};
unsigned int current_size = 0;

unsigned int getHashcode(unsigned int key){
	return key % SIZE_OF_HASH_MAP;
}

void insertIntoHashmap(unsigned int userInput){
	if(current_size == SIZE_OF_HASH_MAP){
		printf("Hash map is full");
		return;
	}
	unsigned int hashcode = getHashcode(userInput);
	while(hashmap[hashcode] != EMPTY_MARKER){
		hashcode = (hashcode + 1)%SIZE_OF_HASH_MAP;
	}
	hashmap[hashcode] = userInput;
	current_size++;
}

bool searchForNodeHashmap(unsigned int userInput){
	unsigned int hashcode = getHashcode(userInput);
	unsigned int counter = 0;
	while(hashmap[hashcode] != userInput && hashmap[hashcode] == EMPTY_MARKER && counter != SIZE_OF_HASH_MAP){
		hashcode += 1;
		counter++;
	}
	if(hashmap[hashcode] == userInput){
		return true;
	}
	return false;
}

unsigned int getHashCodeFromHashmap(unsigned int userInput){
	unsigned int hashcode = getHashcode(userInput);
	unsigned int counter = 0;
	while(hashmap[hashcode] != userInput && hashmap[hashcode] == EMPTY_MARKER && counter != SIZE_OF_HASH_MAP){
		hashcode += 1;
		counter++;
	}
	if(hashmap[hashcode] == userInput){
		return hashcode;
	}
	return UINT_MAX;
}

void deleteFromHashmap(unsigned int userInput){
	unsigned int hashcode = getHashCodeFromHashmap(userInput);
	if(hashcode != UINT_MAX){
		hashmap[hashcode] = DELETION_MARKER;
	}
}
#endif /* LINEARPROBING_H_ */

/************************************************* End code *******************************************************/
