/***************************************************************************************************************** 
 *  File Name   		: LeafToRootPath.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\LeafToRootPath.h
 *  Created on			: Dec 17, 2013 :: 7:55:38 PM
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
#include <programming/utils/treeutils.h>

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef LEAFTOROOTPATH_H_
#define LEAFTOROOTPATH_H_

void leafToRootPath(tNode *ptr,stack<tNode *> auxSpace){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.top()->value);
			auxSpace.pop();
		}
		printf("\n");
		return;
	}
	auxSpace.push(ptr);
	leafToRootPath(ptr->left,auxSpace);
	leafToRootPath(ptr->right,auxSpace);
}

void leafToRootPathParentPtr(tPNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		tPNode *currentNode = ptr;
		while(currentNode != NULL){
			printf("%d\t",currentNode->value);
			currentNode = currentNode->parent;
		}
		return;
	}
	leafToRootPathParentPtr(ptr->left);
	leafToRootPathParentPtr(ptr->right);
}

void leafToRootPathParentPtrIterative(tPNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tPNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			while(currentNode != NULL){
				printf("%d\t",currentNode->value);
				currentNode = currentNode->parent;
			}
		}else{
			if(currentNode->right == NULL){
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left == NULL){
				auxSpace.push(currentNode->left);
			}
		}
	}
}

void leafToRootPathHashmap(tNode *ptr){
	if(ptr == NULL){
		return;
	}

}

#endif /* LEAFTOROOTPATH_H_ */

/************************************************* End code *******************************************************/
