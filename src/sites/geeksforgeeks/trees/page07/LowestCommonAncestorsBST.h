/***************************************************************************************************************** 
 *  File Name   		: LowestCommonAncestorsBST.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\LowestCommonAncestorsBST.h
 *  Created on			: Dec 13, 2013 :: 2:13:40 AM
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

#ifndef LOWESTCOMMONANCESTORSBST_H_
#define LOWESTCOMMONANCESTORSBST_H_

bool checkIfNodeExists(tNode *ptr,int value){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == value){
		return true;
	}
	return checkIfNodeExists(ptr->left,value) && checkIfNodeExists(ptr->right,value);
}

unsigned int lowestCommonAncestorNaiveAlgo(tNode *ptr,int lowestValue,int greatestValue){
	if(ptr == NULL){
		return INT_MAX;
	}
	if(checkIfNodeExists(ptr->left,lowestValue) && checkIfNodeExists(ptr->right,greatestValue)){
		return ptr->value;
	}
	unsigned int leftValue = lowestCommonAncestorNaiveAlgo(ptr->left,lowestValue,greatestValue);
	if(leftValue != INT_MAX){
		return leftValue;
	}
	return lowestCommonAncestorNaiveAlgo(ptr->right,lowestValue,greatestValue);

}

unsigned int lowestCommonAncestorsBST(tNode *ptr,int lowestValue,int greatestValue){
	if(ptr == NULL){
		return INT_MAX;
	}
	if(ptr->value >= lowestValue && ptr->value <= greatestValue){
		return ptr->value;
	}
	if(ptr->value > lowestValue){
		return lowestCommonAncestorsBST(ptr->left,lowestValue,greatestValue);
	}else{
		return lowestCommonAncestorsBST(ptr->right,lowestValue,greatestValue);
	}
}

unsigned int lowestCommonAncestorsBSTIterative(tNode *ptr,int lowestValue,int greatestValue){
	if(ptr == NULL){
		return INT_MAX;
	}
	if(lowestValue > greatestValue){
		int tempValue = lowestValue;
		lowestValue = greatestValue;
		greatestValue = lowestValue;
	}
	tNode *currentNode = ptr;
	while(currentNode != NULL){
		if(currentNode->value >= lowestValue && currentNode->value <= greatestValue){
			return currentNode->value;
		}
		if(currentNode->value > lowestValue){
			currentNode = currentNode->left;
		}else{
			currentNode = currentNode->right;
		}
	}
	return INT_MAX;
}

struct tPNodeWithLevel{
	tPNode *ptr;
	unsigned int level;
};

tPNodeWithLevel *findNodeAndLevelWithValue(tPNode *ptr,int userInput,unsigned int level){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value == userInput){
		tPNodeWithLevel *newNode = (tPNodeWithLevel *)malloc(sizeof(tPNodeWithLevel));
		newNode->ptr = ptr;
		newNode->level = level;
		return  newNode;
	}
	tPNodeWithLevel *fromLeft = findNodeWithValue(ptr->left,userInput,level+1);
	if(fromLeft != NULL){
		return fromLeft;
	}
	return findNodeWithValue(ptr->right,userInput,level+1);
}

unsigned int lowestCommonAncestorFindingParentPtrs(tPNode *ptr,int minValue,int maxValue){
	if(ptr == NULL){
		return INT_MAX;
	}
	tPNodeWithLevel *minNodeWithLevel = findNodeWithValue(ptr,minValue);
	tPNodeWithLevel *maxNodeWithLevel = findNodeWithValue(ptr,maxValue);
	tPNode *ptrMinNode = minNodeWithLevel->ptr,*ptrMaxNode = maxNodeWithLevel->ptr;
	if(minNodeWithLevel->level != maxNodeWithLevel->level){
		unsigned int diff = abs(minNodeWithLevel->level,maxNodeWithLevel->level);
		if(minNodeWithLevel->level >  maxNodeWithLevel->level){
			while(diff--){
				ptrMinNode = ptrMinNode->parent;
			}
		}else{
			while(diff--){
				ptrMaxNode = ptrMaxNode->parent;
			}
		}
	}
	while(ptrMinNode != NULL && ptrMaxNode != NULL){
		if(ptrMinNode == ptrMaxNode){
			return ptrMinNode;
		}
		ptrMinNode = ptrMinNode->parent;
		ptrMaxNode = ptrMaxNode->parent;
	}
	return NULL;
}

#endif /* LOWESTCOMMONANCESTORSBST_H_ */
/************************************************* End code *******************************************************/
