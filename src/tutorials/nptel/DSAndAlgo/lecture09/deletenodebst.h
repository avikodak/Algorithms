/***************************************************************************************************************** 
 *  File Name   		: deletenodebst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture09\deletenodebst.h
 *  Created on			: Dec 31, 2013 :: 12:20:44 PM
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

#ifndef DELETENODEBST_H_
#define DELETENODEBST_H_

void deleteNodeBST(tNode *ptr,tNode *ptrToKey){
	if(ptr == NULL || ptrToKey == NULL){
		return;
	}
	if(ptrToKey->left == NULL || ptrToKey->right == NULL){
		tNode *ptrToParent = ptr;
		while(ptrToParent->left != ptrToKey || ptrToParent->right != ptrToKey){
			if(ptrToParent->value > ptrToKey->value){
				ptrToParent = ptrToParent->left;
			}else{
				ptrToParent = ptrToParent->right;
			}
		}
		if(ptrToParent->left == ptrToKey){
			if(ptrToKey->left != NULL){
				ptrToParent->left  = ptrToKey->left;
			}else{
				ptrToParent->left = ptrToKey->right;
			}
		}else{
			if(ptrToKey->left != NULL){
				ptrToParent->right = ptrToKey->left;
			}else{
				ptrToParent->right = ptrToKey->right;
			}
		}
		free(ptrToKey);
	}else{
		tNode *predecessor = ptrToKey->left,*predecessorParent = ptrToKey;
		while(predecessor->right != NULL){
			predecessor = predecessor->right;
			predecessorParent = predecessorParent->right;
		}
		ptrToKey->value = predecessor->value;
		if(predecessor->left != NULL){
			predecessorParent->right = predecessor->left;
		}
		free(predecessor);
	}
}

void deleteNodesBSTParentPtr(tPNode *ptrTokey){
	if(ptrTokey == NULL){
		return;
	}
	tPNode *nodeToBeDeleted;
	if(ptrTokey->left == NULL || ptrTokey->right == NULL){
		nodeToBeDeleted = ptrTokey;
		if(ptrTokey->left != NULL){
			if(ptrTokey->parent->left == ptrTokey){
				ptrTokey->parent->left = ptrTokey->left;
			}else{
				ptrTokey->parent->right = ptrTokey->left;
			}
		}else{
			if(ptrTokey->parent->left == ptrTokey){
				ptrTokey->parent->left = ptrTokey->right;
			}else{
				ptrTokey->parent->right = ptrTokey->right;
			}
		}
		free(nodeToBeDeleted);
	}else{
		tPNode *predecessorNode;
		predecessorNode = ptrTokey->left;
		while(predecessorNode->right != NULL){
			predecessorNode = predecessorNode->right;
		}
		ptrTokey->value = predecessorNode->value;
		nodeToBeDeleted = predecessorNode;
		if(predecessorNode->parent->left == predecessorNode){
			predecessorNode->parent->left = predecessorNode->left;
		}else{
			predecessorNode->parent->right = predecessorNode->left;
		}
		free(nodeToBeDeleted);
	}
}
#endif /* DELETENODEBST_H_ */
/************************************************* End code *******************************************************/
