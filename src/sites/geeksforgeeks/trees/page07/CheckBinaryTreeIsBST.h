/***************************************************************************************************************** 
 *  File Name   		: CheckBinaryTreeIsBST.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\CheckBinaryTreeIsBST.h
 *  Created on			: Dec 17, 2013 :: 7:48:21 PM
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

#ifndef CHECKBINARYTREEISBST_H_
#define CHECKBINARYTREEISBST_H_

bool checkWhetherAllValuesAreUnderConstraint(tNode *ptr,bool lessThanConstraint,int userInput){
	if(ptr == NULL){
		return true;
	}
	if(lessThanConstraint){
		if(ptr->value > userInput){
			return false;
		}
	}else{
		if(ptr->value < userInput){
			return false;
		}
	}
	return checkWhetherAllValuesAreUnderConstraint(ptr->left,lessThanConstraint,userInput) && checkWhetherAllValuesAreUnderConstraint(ptr->right,lessThanConstraint,userInput);
}

bool checkWhetherBinaryTreeIsBSTOrNot(tNode *ptr,int minValue,int maxValue){
	if(ptr == NULL){
		return true;
	}
}

bool checkWhetherBinaryTreeIsBSTOrNotBottomUp(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
}

#endif /* CHECKBINARYTREEISBST_H_ */
/************************************************* End code *******************************************************/
