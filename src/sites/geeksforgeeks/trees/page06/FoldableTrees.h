/***************************************************************************************************************** 
 *  File Name   		: FoldableTrees.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\FoldableTrees.h
 *  Created on			: Dec 24, 2013 :: 6:41:40 PM
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

#ifndef FOLDABLETREES_H_
#define FOLDABLETREES_H_

bool areSubTreesMirrorImages(tNode *firstPtr,tNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return true;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		return false;
	}
	if(firstPtr->value != secondPtr->value){
		return false;
	}
	return areSubTreesMirrorImages(firstPtr->left,secondPtr->right) && areSubTreesMirrorImages(firstPtr->right,secondPtr->left);
}

bool isTreeFoldableDriver(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	return areSubTreesMirrorImages(ptr->left,ptr->right);
}

void convertTreeIntoMirrorImage(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	convertTreeIntoMirrorImage(ptr->left);
	convertTreeIntoMirrorImage(ptr->right);
	tNode *temp;
	temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

void areTreesIdentical(tNode *firstPtr,tNode *secondPtr){
	if(firstPtr == NULL && secondPtr == NULL){
		return true;
	}
	if(firstPtr == NULL || secondPtr == NULL){
		return false;
	}
	if(firstPtr->value != secondPtr->value){
		return false;
	}
	return areTreesIdentical(firstPtr->left,secondPtr->left) && areTreesIdentical(firstPtr->right,secondPtr->right);
}

bool isTreeFoldableMirrorImage(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	convertTreeIntoMirrorImage(ptr->left);
	return areTreesIdentical(areTreesIdentical(ptr->left,ptr->right));
}

bool isTreeFoldableHashMap(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
}
#endif /* FOLDABLETREES_H_ */

/************************************************* End code *******************************************************/
