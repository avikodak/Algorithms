/***************************************************************************************************************** 
 *  File Name   		: findKthSmallestBST.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\findKthSmallestBST.h
 *  Created on			: Jan 4, 2014 :: 11:12:02 AM
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

#ifndef FINDKTHSMALLESTBST_H_
#define FINDKTHSMALLESTBST_H_

int findKthSmallestElementBST(tNode *ptr,unsigned int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}
	static unsigned int node = 0;
	int leftValue = findKthSmallestElementBST(ptr->left,kValue);
	if(leftValue != INT_MIN){
		return leftValue;
	}
	node+=1;
	if(node == kValue){
		return ptr->value;
	}
	return findKthSmallestElementBST(ptr->right,kValue);
}

int findKthSmallestElementBSTIterative(tNode *ptr,unsigned int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	unsigned int nodeCounter = 0;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			nodeCounter += 1;
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(nodeCounter == kValue){
				return currentNode->value;
			}
			currentNode = currentNode->right;
		}
	}
	return INT_MIN;
}

int findKthSmallestElementBSTMorris(tNode *ptr,unsigned int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}
	tNode *currentNode = ptr,*temp;
	unsigned int counter = 0;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			temp = currentNode->left;
			while(temp->right != NULL || temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == NULL){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				counter += 1;
				if(counter == kValue){
					return currentNode->value;
				}
				temp->right = NULL;
				currentNode = currentNode->right;
			}
		}else{
			counter += 1;
			if(counter == kValue){
				return currentNode->value;
			}
			currentNode = currentNode->right;
		}
	}
	return INT_MIN;
}

/*store aux space */
#endif /* FINDKTHSMALLESTBST_H_ */

/************************************************* End code *******************************************************/
