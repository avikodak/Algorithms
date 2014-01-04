/***************************************************************************************************************** 
 *  File Name   		: preorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture07\preorder.h
 *  Created on			: Dec 30, 2013 :: 5:34:07 PM
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

#ifndef PREORDER_H_
#define PREORDER_H_

void preOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	printf("%d\t",ptr->value);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}

void preOrderTraversalIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		printf("%d",currentNode->value);
		auxSpace.pop();
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
	}
}

void preOrderTraversalIterativeMorris(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNode *currentNode = ptr,*temp;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			temp =currentNode->left;
			while(temp->right != NULL && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == NULL){
				printf("%d\t",currentNode->value);
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = NULL;
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

#endif /* PREORDER_H_ */
/************************************************* End code *******************************************************/
