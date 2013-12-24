/***************************************************************************************************************** 
 *  File Name   		: LevelOrderSpiralForm.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\LevelOrderSpiralForm.h
 *  Created on			: Dec 17, 2013 :: 7:41:14 PM
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

#ifndef LEVELORDERSPIRALFORM_H_
#define LEVELORDERSPIRALFORM_H_

void levelOrderSpiralOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<tNode *> straightLevel;
	stack<tNode *> reverseLevel;
	straightLevel.push(ptr);
	tNode *currentNode;
	while(!straightLevel.empty() && !reverseLevel.empty()){
		while(!straightLevel.empty()){
			currentNode = straightLevel.front();
			printf("%d\t",currentNode->value);
			if(currentNode->left != NULL){
				reverseLevel.push(currentNode->left);
			}
			if(currentNode->right != NULL){
				reverseLevel.push(currentNode->right);
			}
		}
		while(!reverseLevel.empty()){
			currentNode = reverseLevel.top();
			printf("%d\t",currentNode->value);
			if(currentNode->left != NULL){
				straightLevel.push(currentNode->left);
			}
			if(currentNode->right != NULL){
				straightLevel.push(currentNode->right);
			}
		}
		printf("\n");
	}
}

void levelOrderSpriralOrderHashmap(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tHashmap *hashmapFormTree;
	hash_map<unsigned int,tNode *> indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap;
	sort(indexNodeMap.begin(),indexNodeMap.end());
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){

	}
}

#endif /* LEVELORDERSPIRALFORM_H_ */
/************************************************* End code *******************************************************/
