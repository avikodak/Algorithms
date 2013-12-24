/***************************************************************************************************************** 
 *  File Name   		: InorderIterative.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\InorderIterative.h
 *  Created on			: Dec 23, 2013 :: 1:02:36 PM
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

#ifndef INORDERITERATIVE_H_
#define INORDERITERATIVE_H_

void inorderIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
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

#endif /* INORDERITERATIVE_H_ */

/************************************************* End code *******************************************************/
