/***************************************************************************************************************** 
 *  File Name   		: InorderSuccessorBST.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page05\InorderSuccessorBST.h
 *  Created on			: Dec 25, 2013 :: 12:35:43 PM
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

#ifndef INORDERSUCCESSORBST_H_
#define INORDERSUCCESSORBST_H_

tNode *inOrderSuccessorBST(tNode *ptr,tNode *ptrToKey){
	if(ptr == NULL || ptrToKey == NULL){
		return NULL;
	}
	tNode *temp;
	if(ptrToKey->right != NULL){
		temp = ptrToKey->right;
		while(temp->left != NULL){
			temp = temp->left;
		}
	}else{
		temp = root;
		tNode *successor = NULL;
		while(temp->left != ptrToKey || temp->right != ptrToKey){
			if(temp->value > ptrToKey->value){
				successor = temp;
				temp = temp->left;
			}else{
				temp = temp->right;
			}
		}
		temp = successor;
	}
	return temp;
}

tNode *inOrderSuccessorBSTIterative(tNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	tNode *crawler,*probableSuccessor = NULL;
	while(crawler != NULL && crawler->value != value){
		if(crawler->value > value){
			probableSuccessor = crawler;
			crawler = crawler->left;
		}else{
			crawler = crawler->right;
		}
	}
	if(crawler->right != NULL){
		crawler = crawler->right;
		while(crawler->left != NULL){
			crawler = crawler->left;
		}
		return crawler;
	}
	return probableSuccessor;
}

tNode *inOrderSuccessorBST(tNode *ptr,tNode **probableSuccessor,int value){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value == value){
		if(ptr->right == NULL){
			return (*probableSuccessor);
		}
		ptr = ptr->right;
		while(ptr->left != NULL){
			ptr = ptr->left;
		}
		return ptr;
	}
	if(ptr->value > value){
		probableSuccessor = ptr;
		return inOrderSuccessorBST(ptr->left,probableSuccessor,value);
	}else{
		return inOrderSuccessorBST(ptr->right,probableSuccessor,value);
	}
}

#endif /* INORDERSUCCESSORBST_H_ */

/************************************************* End code *******************************************************/
