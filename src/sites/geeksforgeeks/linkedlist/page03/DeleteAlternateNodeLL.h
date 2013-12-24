/***************************************************************************************************************** 
 *  File Name   		: DeleteAlternateNodeLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\DeleteAlternateNodeLL.h
 *  Created on			: Dec 22, 2013 :: 8:26:36 PM
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

#ifndef DELETEALTERNATENODELL_H_
#define DELETEALTERNATENODELL_H_

void deleteAlternateNodeLL(llNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	llNode *nodeToBeDeleted = ptr->next;
	ptr->next = ptr->next->next;
	free(nodeToBeDeleted);
	deleteAlternateNodeLL(ptr->next);
}

void deleteAlternateNodeLLIterative(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr,*nodeToBeDeleted;
	while(crawler != NULL&&crawler->next != NULL){
		nodeToBeDeleted = crawler->next;
		crawler->next = crawler->next->next;
		free(nodeToBeDeleted);
		crawler = crawler->next;
	}
}

void deleteAlternateNodesLLAuxspaceIterative(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<int> auxSpace;
	llNode *crawler,*nodeToBeDeleted;
	bool shouldPush = true;
	while(crawler != NULL){
		if(shouldPush){
			auxSpace.push(crawler);
		}
		crawler = crawler->next;
		shouldPush = !shouldPush;
	}
	crawler = ptr;
	while(!auxSpace.empty()){
		crawler->value = auxSpace.front();
		auxSpace.pop();
		crawler = crawler->next;
	}

	while(crawler != NULL){
		nodeToBeDeleted = crawler;
		crawler = crawler->next;
		free(nodeToBeDeleted);
	}
}

void deleteAlternateNodeLLHashmap(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	llNode *crawler = ptr;
	unsigned int counter = 0;
	hash_map<unsigned int,llNode *> indexNodeMap;
	hash_map<unsigned int,llNode *>::iterator itToIndexNodeMap,itToCurrentNode;
	while(crawler != NULL){
		indexNodeMap.insert(pair<unsigned int,llNode *>(++counter,crawler));
		crawler = crawler->next;
	}
	for(unsigned int indexCounter = 1;indexCounter < counter;indexCounter+=2){
		itToCurrentNode = indexNodeMap.find(indexCounter);
		if((itToIndexNodeMap = indexNodeMap.find(2*indexCounter+1)) != indexNodeMap.end()){
			itToCurrentNode->second->next = itToIndexNodeMap->second;
		}
		if((itToIndexNodeMap = indexNodeMap.find(2*indexCounter)) != indexNodeMap.end()){
			free(itToIndexNodeMap->second);
		}
	}
}

void deleteAlternateNodesLLNewLL(llNode **ptr){
	if(*ptr == NULL){
		return;
	}
	llNode *newList = NULL,*newListCrawler,*crawler = (*ptr),*temp;
	bool shouldAppend = true;
	while(crawler != NULL){
		if(shouldAppend){
			if(newList == NULL){
				newList = createNewLLNode(crawler->value);
				newListCrawler = newList;
			}else{
				newListCrawler->next = createNewLLNode(crawler->value);
				newListCrawler = newListCrawler->next;
			}
		}
		shouldAppend = !shouldAppend;
		crawler = crawler->next;
	}
	while(crawler != NULL){
		temp = crawler;
		crawler = crawler->next;
		free(temp);
	}
	(*ptr) = newList;
}

#endif /* DELETEALTERNATENODELL_H_ */

/************************************************* End code *******************************************************/
