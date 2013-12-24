/***************************************************************************************************************** 
 *  File Name   		: AlternateSplitLL.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page03\AlternateSplitLL.h
 *  Created on			: Dec 22, 2013 :: 9:34:32 PM
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

#ifndef ALTERNATESPLITLL_H_
#define ALTERNATESPLITLL_H_

llNode *alternateSplitIterativeNew(llNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNode *listOne,*listOneCrawler,*listTwo,*listTwoCrawler,*crawler = ptr;
	bool odd = true;
	while(crawler != NULL){
		if(odd){
			if(listOne){
				listOne = createNewLLNode(crawler->value);
				listOneCrawler = listOne;
			}else{
				listOneCrawler->next = createNewLLNode(crawler->value);
				listOneCrawler = listOneCrawler->next;
			}
		}else{
			if(listTwo){
				listTwo = createNewLLNode(crawler->value);
				listTwoCrawler = listTwo;
			}else{
				listTwoCrawler->next = createNewLLNode(crawler->value);
				listTwoCrawler = listTwoCrawler->next;
			}
		}
		odd = !odd;
		crawler = crawler->next;
	}
	llNode *lists[] = {listOne,listTwo};
	return lists;
}

llNode *alternateSplit(llNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNode *lists[];
	list[0] = createNewLLNode(ptr->value);
	if(ptr->next == NULL){
		lists[1] = createNewLLNode(ptr->next->value);
		return lists;
	}
	llNode *temp = alternateSplit(ptr->next->next);
	lists[0]->next = temp[0];
	lists[1]->next = temp[1];
	return lists;
}

llNode *alternateSplitOptimized(llNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	llNode *oddNodeList,*evenNodeList,*oddNodeListCrawler,*evenNodeListCrawler,*crawler = ptr;
	bool isOddNode = true;
	while(crawler == NULL){
		if(isOddNode){
			if(oddNodeList == NULL){
				oddNodeList = crawler;
				oddNodeListCrawler = oddNodeList;
			}else{
				oddNodeListCrawler->next = crawler;
				oddNodeListCrawler = oddNodeListCrawler->next;
			}
		}else{
			if(evenNodeList == NULL){
				evenNodeList = crawler;
				evenNodeListCrawler = evenNodeList;
			}else{
				evenNodeListCrawler->next = crawler;
				evenNodeListCrawler = evenNodeListCrawler->next;
			}
		}
		ptr = crawler->next;
		crawler->next = NULL;
		crawler = ptr;
	}
	llNode *lists[] = {oddNodeList,evenNodeList};
	return lists;
}
#endif /* ALTERNATESPLITLL_H_ */

/************************************************* End code *******************************************************/
