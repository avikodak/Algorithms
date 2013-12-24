/***************************************************************************************************************** 
 *  File Name   		: RemoveDuplicatesFromSortedLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page04\RemoveDuplicatesFromSortedLL.h
 *  Created on			: Dec 18, 2013 :: 11:41:06 PM
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

#ifndef REMOVEDUPLICATESFROMSORTEDLL_H_
#define REMOVEDUPLICATESFROMSORTEDLL_H_

void removeDuplicatesFromSortedLL(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr,*tempNode;
	while(crawler != NULL){
		while(crawler->next != NULL && crawler->value == crawler->next->value){
			tempNode = crawler->next;
			crawler->next = crawler->next->next;
			free(tempNode);
		}
		crawler = crawler->next;
	}
	return;
}

void removeDuplicatesFromSortedLLNewList(llNode **ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr,*newList,*newListCrawler;
	while(crawler != NULL){
		if(newList == NULL){
			newList = createNewLLNode(crawler->value);
			newListCrawler = newList;
		}else{
			if(newListCrawler->value != crawler->value){
				newListCrawler->next = createNewLLNode(crawler->value);
				newListCrawler = newListCrawler->next;
			}
		}
		crawler = crawler->next;
	}
}

#endif /* REMOVEDUPLICATESFROMSORTEDLL_H_ */

/************************************************* End code *******************************************************/
