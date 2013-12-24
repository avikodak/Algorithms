/***************************************************************************************************************** 
 *  File Name   		: InsertNodeIntoSortedLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\InsertNodeIntoSortedLL.h
 *  Created on			: Dec 18, 2013 :: 11:40:23 PM
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

/************************************************* End code *******************************************************/

#ifndef INSERTNODEINTOSORTEDLL_H_
#define INSERTNODEINTOSORTEDLL_H_

void insertNodeIntoSortedLL(llNode **ptr,int userInput){
	if(*ptr == NULL){
		(*ptr) = createNewLLNode(userInput);
	}else{
		llNode *crawler = *ptr;
		while(crawler->value < userInput){
			crawler = crawler->next;
		}
		llNode *newNode = createNewLLNode(crawler->value);
		newNode->next = crawler->next;
		crawler->value = userInput;
	}
}

#endif /* INSERTNODEINTOSORTEDLL_H_ */
