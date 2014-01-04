/***************************************************************************************************************** 
 *  File Name   		: inorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture07\inorder.h
 *  Created on			: Dec 30, 2013 :: 5:34:24 PM
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
#ifndef INORDER_H_
#define INORDER_H_

void inOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	inOrderTraversal(ptr->left);
	printf("%d\n",ptr->value);
	inOrderTraversal(ptr->right);
}

void inOrderTraversalIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

void inOrderTraversalMorris(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNode *currentNode = ptr,*temp;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			temp = currentNode->left;
			while(temp->right != NULL && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == NULL){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				printf("%d\t",currentNode->value);
				temp->right = NULL;
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

#endif /* INORDER_H_ */
/************************************************* End code *******************************************************/
