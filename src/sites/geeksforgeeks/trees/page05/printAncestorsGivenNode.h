/***************************************************************************************************************** 
 *  File Name   		: printAncestorsGivenNode.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\printAncestorsGivenNode.h
 *  Created on			: Jan 4, 2014 :: 12:00:12 PM
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

#ifndef PRINTANCESTORSGIVENNODE_H_
#define PRINTANCESTORSGIVENNODE_H_

void printAncestorGivenNode(tNode *ptr,stack<tNode *> auxSpace,int nodeValue){
	if(ptr == NULL){
		return;
	}
	if(ptr->value == nodeValue){
		printf("%d\t",ptr->value);
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.top()->value);
			auxSpace.pop();
		}
		return;
	}
	auxSpace.push(ptr);
	printAncestorGivenNode(ptr->left,auxSpace,nodeValue);
	printAncestorGivenNode(ptr->right,auxSpace,nodeValue);
}

void printAncestorGivenNodeParentPtr(tPNode *ptr,int nodeValue){
	if(ptr == NULL){
		return;
	}
	if(ptr->value == nodeValue){
		tPNode *currentNode = ptr;
		while(currentNode != NULL){
			printf("%d\t",currentNode->value);
			currentNode = currentNode->parent;
		}
		return;
	}
	printAncestorGivenNodeParentPtr(ptr->left,nodeValue);
	printAncestorGivenNodeParentPtr(ptr->right,nodeValue);
}

void printAncestorsGivenNodeHashmap(tNode *ptr,int nodeValue){
	if(ptr == NULL){
		return;
	}
	hash_map<unsigned int,tNode *> indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(itToIndexNodeMap->second->value == nodeValue){
			unsigned int currentIndex = itToIndexNodeMap->first;
			while(currentIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentIndex /= 2;
			}
			return;
		}
	}
	return;
}

bool printAncestorsBinaryTree(tNode *ptr,int nodeValue){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == nodeValue){
		printf("%d\t",ptr->value);
		return true;
	}
	if(printAncestorGivenNode(ptr->left,nodeValue) || printAncestorGivenNode(ptr->right,nodeValue)){
		printf("%d\t",ptr->value);
		return true;
	}
	return false;
}

#endif /* PRINTANCESTORSGIVENNODE_H_ */

/************************************************* End code *******************************************************/
