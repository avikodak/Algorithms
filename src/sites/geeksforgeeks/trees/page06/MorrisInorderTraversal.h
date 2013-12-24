/***************************************************************************************************************** 
 *  File Name   		: MorrisInorderTraversal.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\MorrisInorderTraversal.h
 *  Created on			: Dec 23, 2013 :: 1:05:54 PM
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

#ifndef MORRISINORDERTRAVERSAL_H_
#define MORRISINORDERTRAVERSAL_H_

void morrisInOrderTraversal(tNode *ptr){
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
				temp->right = NULL;
				printf("%d\t",currentNode->value);
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

#endif /* MORRISINORDERTRAVERSAL_H_ */

/************************************************* End code *******************************************************/
