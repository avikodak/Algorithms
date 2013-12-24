/***************************************************************************************************************** 
 *  File Name   		: ReverseLLInGroupGivenSize.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\ReverseLLInGroupGivenSize.h
 *  Created on			: Dec 23, 2013 :: 1:47:12 AM
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

#ifndef REVERSELLINGROUPGIVENSIZE_H_
#define REVERSELLINGROUPGIVENSIZE_H_

void reverseLLInGroupSizeIterative(llNode *ptr,unsigned int groupSize){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr;
	queue<int> auxSpace;
	stack<int> reverseAuxSpace;
	bool shouldReverse = false;
	unsigned int sizeCounter = groupSize;
	while(crawler != NULL){
		if(shouldReverse){
			reverseAuxSpace.push(crawler->value);
		}else{
			auxSpace.push(crawler->value);
		}
		crawler = crawler->next;
		sizeCounter--;
		if(sizeCounter == 0){
			if(shouldReverse){
				while(!reverseAuxSpace.empty()){
					auxSpace.push(reverseAuxSpace.top());
					reverseAuxSpace.pop();
				}
			}
			sizeCounter = groupSize;
		}
	}
	crawler = ptr;
	while(crawler != NULL){
		crawler->value = auxSpace.front();
		auxSpace.pop();
		crawler = crawler->next;
	}
}

void reverseLLInGroupSizeIterative(llNode *ptr,unsigned int groupSize){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr;
	unsigned int counter = groupSize;
	while(crawler != NULL){

	}
}

#endif /* REVERSELLINGROUPGIVENSIZE_H_ */

/************************************************* End code *******************************************************/
