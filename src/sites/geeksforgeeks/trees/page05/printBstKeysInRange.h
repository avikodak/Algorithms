/***************************************************************************************************************** 
 *  File Name   		: printBstKeysInRange.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\printBstKeysInRange.h
 *  Created on			: Jan 4, 2014 :: 12:14:42 PM
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

#ifndef PRINTBSTKEYSINRANGE_H_
#define PRINTBSTKEYSINRANGE_H_

void printBSTkeysInRange(tNode *ptr,int startValue,int endValue){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value > startValue){
		printBSTkeysInRange(ptr->left,startValue,endValue);
	}
	if(ptr->value > startValue && ptr->value < endValue){
		printf("%d\t",ptr->value);
	}
	if(ptr->value < endValue){
		printBSTkeysInRange(ptr->right,startValue,endValue);
	}
}

void printBSTKeysInRangeInorder(tNode *ptr,int startValue,int endValue){
	if(ptr == NULL){
		return;
	}
	printBSTKeysInRangePreorder(ptr->left,startValue,endValue);
	if(ptr->value > startValue && ptr->value < endValue){
		printf("%d\t",ptr->value);
	}
	printBSTKeysInRangePreorder(ptr->right,startValue,endValue);
}

void printBSTKeysInRangeInorderIterative(tNode *ptr,int startValue,int endValue){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode!= NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->value > startValue?currentNode->left:NULL;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value > startValue&& currentNode->value < endValue){
				printf("%d\t",currentNode->value);
			}
			currentNode = currentNode->value < endValue?currentNode->right:NULL;
		}
	}
}

void printBSTKeysInRangeMorris(tNode *ptr,int startValue,int endValue){
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
				if(currentNode->value > startValue && currentNode->value < endValue){
					printf("%d\t",currentNode->value);
				}
				temp->right = NULL;
				currentNode = currentNode->right;
			}
		}else{
			if(currentNode->value > startValue && currentNode->value < endValue){
				printf("%d\t",currentNode->value);
			}
			currentNode = currentNode->right;
		}
	}
}
#endif /* PRINTBSTKEYSINRANGE_H_ */
/************************************************* End code *******************************************************/
