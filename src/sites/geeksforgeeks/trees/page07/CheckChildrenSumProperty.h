/***************************************************************************************************************** 
 *  File Name   		: BinarySumTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\BinarySumTree.h
 *  Created on			: Dec 17, 2013 :: 9:46:24 AM
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

#ifndef CHECKCHILDRENSUMPROPERTY_H_
#define CHECKCHILDRENSUMPROPERTY_H_

bool checkChildrenSumPropertyPreOrder(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return true;
	}
	int sumChildren = 0;
	if(ptr->left != NULL){
		sumChildren += ptr->left->value;
	}
	if(ptr->right != NULL){
		sumChildren += ptr->right->value;
	}
	if(ptr->value != sumChildren){
		return false;
	}
	return checkChildrenSumPropertyPreOrder(ptr->left) && checkChildrenSumPropertyPreOrder(ptr->right);
}

bool checkChildrenSumProperyInOrder(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return true;
	}
	if(!checkChildrenSumProperyInOrder(ptr->left)){
		return false;
	}
	int sumChildren = 0;
	if(ptr->left != NULL){
		sumChildren += ptr->left->value;
	}
	if(ptr->right != NULL){
		sumChildren += ptr->right->value;
	}
	if(sumChildren != ptr->value){
		return false;
	}
	return checkChildrenSumProperyInOrder(ptr->right);
}

bool checkWhetherTreeIsSumTreePostOrder(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return true;
	}
	if(!checkWhetherTreeIsSumTree(ptr->left) || !checkWhetherTreeIsSumTree(ptr->right)){
		return false;
	}
	int sumChildren = 0;
	if(ptr->left != NULL){
		sumChildren += ptr->left->value;
	}
	if(ptr->right != NULL){
		sumChildren += ptr->right->value;
	}
	return sumChildren == ptr->value?true:false;
}

bool checkWhetherTreeIsSumTreePostIterativeTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	stack<tNode *> primaryAuxSpace,secondaryAuxSpace;
	tNode *currentNode;
	primaryAuxSpace.push(ptr);
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpace.push(currentNode);
		if(currentNode->left != NULL){
			primaryAuxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			primaryAuxSpace.push(currentNode->right);
		}
	}
	int sumChildren = 0;
	while(!secondaryAuxSpace.empty()){
		currentNode = secondaryAuxSpace.top();
		sumChildren = 0;
		if(currentNode->left != NULL){
			sumChildren += currentNode->left;
		}
		if(currentNode->right != NULL){
			sumChildren += currentNode->right;
		}
		if(sumChildren != currentNode->value){
			return false;
		}
	}
	return true;
}

bool checkWhetherTreeIsSumTreePostIterative(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr,*tempNode;
	int sumChildren = 0;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->right == auxSpace.top()){
				tempNode = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = tempNode;
			}else{
				sumChildren = 0;
				if(currentNode->left != NULL){
					sumChildren += currentNode->left->value;
				}
				if(currentNode->right != NULL){
					sumChildren += currentNode->right->value;
				}
				if(currentNode->value != sumChildren){
					return false;
				}
				currentNode = NULL;
			}
		}
	}
	return true;
}

bool checkChildrenSumPropertyPreOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	auxSpace.push(ptr);
	int sumChildren;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		sumChildren = 0;
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
			sumChildren += currentNode->right->value;
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			sumChildren += currentNode->left->value;
		}
		if(sumChildren != currentNode->value){
			return false;
		}
		auxSpace.pop();
	}
	return true;
}

bool checkChildrenSumProperyInOrderIterative(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	int sumChildren;
	while(!auxSpace.empty() && currentNode != NULL){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			sumChildren = 0;
			if(currentNode->left != NULL){
				sumChildren += currentNode->left->value;
			}
			if(currentNode->right != NULL){
				sumChildren += currentNode->right->value;
			}
			if(sumChildren != currentNode->value){
				return false;
			}
			auxSpace.pop();
			currentNode = currentNode->right;
		}
	}
	return true;
}

bool checkChildrenSumProperyHashMap(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	tHashMap *hashMapTree;
	hash_map<unsigned int,tNode *> indexNodeMap;
	hash_map<unsigned int,tNode *>::iterator itToIndexNodeMap,itToLeftLeaf,itToRightLeaf;
	unsigned int currentNodeIndex;
	int sumOfChildren;

	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeIndex = itToIndexNodeMap->first;
		sumOfChildren = 0;
		if(((itToLeftLeaf = indexNodeMap.find(2*currentNodeIndex))!= indexNodeMap.end()) || ((itToRightLeaf = indexNodeMap.find(2*currentNodeIndex+1)) != indexNodeMap.end()) ){
			if(itToLeftLeaf != indexNodeMap.end()){
				sumOfChildren += itToLeftLeaf->second->value;
			}
			if(itToRightLeaf != indexNodeMap.end()){
				sumOfChildren += itToRightLeaf->second->value;
			}
			if(sumOfChildren != itToIndexNodeMap->second->value){
				return false;
			}
		}
	}
	return true;
}

#endif /* CHECKCHILDRENSUMPROPERTY_H_ */
/************************************************* End code *******************************************************/
