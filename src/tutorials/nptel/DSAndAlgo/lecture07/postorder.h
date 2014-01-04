/***************************************************************************************************************** 
 *  File Name   		: postorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture07\postorder.h
 *  Created on			: Dec 30, 2013 :: 5:34:17 PM
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
#ifndef POSTORDER_H_
#define POSTORDER_H_

void postOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	postOrderTraversal(ptr->left);
	postOrderTraversal(ptr->right);
	printf("%d\t",ptr->value);
}

void postOrderTraversalIterativeTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> primaryAuxspace,secondaryAuxspace;
	tNode *currentNode;
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		if(currentNode->left != NULL){
			primaryAuxspace.push(currentNode->left);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		printf("%d\t",currentNode->value);
	}
}

void postOrderTraversalIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*temp;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->right == auxSpace.top()){
				temp = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = temp;
			}else{
				printf("%d\t",currentNode->value);
				currentNode = NULL;
			}
		}
	}
}

#endif /* POSTORDER_H_ */

/************************************************* End code *******************************************************/
