/***************************************************************************************************************** 
 *  File Name   		: convertBinaryToBST.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\convertBinaryToBST.h
 *  Created on			: Jan 4, 2014 :: 6:51:24 PM
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

#ifndef CONVERTBINARYTOBST_H_
#define CONVERTBINARYTOBST_H_

void getInOrderValues(tNode *ptr,vector<int> &inordervalues){
	if(ptr == NULL){
		return;
	}
	convertBinaryTreeToBST(ptr->left,inordervalues);
	inordervalues.push_back(ptr->value);
	convertBinaryTreeToBST(ptr->right,inordervalues);
}

void fillTreeWithValues(tNode *ptr,vector<int> inOrderValues){
	if(ptr == NULL || inOrderValues.size() == 0){
		return;
	}
	static unsigned int index = 0;
	fillTreeWithValues(ptr->left,inOrderValues);
	ptr->value = inOrderValues[index++];
	fillTreeWithValues(ptr->right,inOrderValues);
}

void convertBinaryTreeToBST(tNode *ptr){
	if(ptr == NULL || (ptr->left == NULL && ptr->right == NULL)){
		return;
	}
	vector<int> inOrderValues;
	getInOrderValues(ptr,inOrderValues);
	sort(inOrderValues.begin(),inOrderValues.end());
	fillTreeWithValues(ptr,inOrderValues);
}

#endif /* CONVERTBINARYTOBST_H_ */

/************************************************* End code *******************************************************/
