/***************************************************************************************************************** 
 *  File Name   		: convertTreeIntoSumTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page04\convertTreeIntoSumTree.h
 *  Created on			: Jan 4, 2014 :: 5:11:52 PM
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

#ifndef CONVERTTREEINTOSUMTREE_H_
#define CONVERTTREEINTOSUMTREE_H_

int convertTreeIntoSumtree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	int leftValue = convertTreeIntoSumtree(ptr->left);
	int rightValue = convertTreeIntoSumtree(ptr->right);
	int tempValue = ptr->value;
	ptr->value = leftValue + rightValue;
	return tempValue + ptr->value;
}

void convertTreeIntoSumTreePostOrderIterativeTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,int> nodeValueMap;
	hash_map<uint32_t,int>::iterator itToNodeValueMapLeft,itToNodeValueMapRight;
	stack<tNode *> primaryAuxspace,secondaryAuxspace;
	tNode *currentNode;
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		nodeValueMap.insert(pair<uint32_t,int>((uint32_t)currentNode,currentNode->value));
		if(currentNode->left != NULL){
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			currentNode->value = 0;
		}else{
			currentNode->value = 0;
			if(currentNode->left != NULL){
				currentNode->value += currentNode->left->value;
			}
			if(currentNode->right != NULL){
				currentNode->value += currentNode->right->value;
			}
			itToNodeValueMapLeft = nodeValueMap.find((uint32_t)currentNode->left);
			itToNodeValueMapRight = nodeValueMap.find((uint32_t)currentNode->right);
			if(itToNodeValueMapLeft != nodeValueMap.end()){
				currentNode->value += itToNodeValueMapLeft->second;
			}
			if(itToNodeValueMapRight != nodeValueMap.end()){
				currentNode->value += itToNodeValueMapRight->second;
			}
		}
	}
}

void convertTreeIntoSumreePostOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	hash_map<uint32_t,int> nodeValueMap;
	hash_map<uint32_t,int>::iterator itToNodeValueMapLeft,itToNodeValueMapRight;
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*temp;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			if(currentNode->right != NULL){
				nodeValueMap.insert((uint32_t)currentNode->right,currentNode->right->value);
			}
			nodeValueMap.insert((uint32_t)currentNode,currentNode->value);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->right == auxSpace.top()){
				temp = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = temp;
			}else{
				if(currentNode->left == NULL && currentNode->right == NULL){
					currentNode->value = 0;
				}else{
					currentNode->value = 0;
					if(currentNode->left != NULL){
						currentNode->value += currentNode->left->value;
					}
					if(currentNode->right != NULL){
						currentNode->value += currentNode->right->value;
					}
					itToNodeValueMapLeft = nodeValueMap.find((uint32_t)currentNode->left);
					itToNodeValueMapRight = nodeValueMap.find((uint32_t)currentNode->right);
					if(itToNodeValueMapLeft != nodeValueMap.end()){
						currentNode->value += itToNodeValueMapLeft->second;
					}
					if(itToNodeValueMapRight != nodeValueMap.end()){
						currentNode->value += itToNodeValueMapRight->second;
					}
				}
			}
		}
	}
}
#endif /* CONVERTTREEINTOSUMTREE_H_ */
/************************************************* End code *******************************************************/
