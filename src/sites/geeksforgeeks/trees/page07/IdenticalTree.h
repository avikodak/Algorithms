/***************************************************************************************************************** 
 *  File Name   		: IdenticalTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page07\IdenticalTree.h
 *  Created on			: Dec 11, 2013 :: 3:44:20 AM
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

#ifndef IDENTICALTREE_H_
#define IDENTICALTREE_H_

bool areTwoTreesIdentical(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	if(ptrToFirstTree->value != ptrToSecondTree->value){
		return false;
	}
	return areTwoTreesIdentical(ptrToFirstTree->left,ptrToSecondTree->left) && areTwoTreesIdentical(ptrToFirstTree->right,ptrToSecondTree->right);
}

bool areTreesWithSamePreOrder(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	if(ptrToFirstTree->value != ptrToSecondTree->value){
		return false;
	}

	return areTreesWithSamePreOrder(ptrToFirstTree->left,ptrToSecondTree->left) && areTreesWithSamePreOrder(ptrToFirstTree->right,ptrToSecondTree->right);
}

bool areTreesWithSameInOrder(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	if(!areTreesWithSameInOrder(ptrToFirstTree->left,ptrToSecondTree->left)){
		return false;
	}
	if(ptrToFirstTree->value != ptrToSecondTree->value){
		return false;
	}
	return areTreesWithSameInOrder(ptrToFirstTree->right,ptrToSecondTree->right);
}

bool areTreesWithSamePostOrder(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	if(!areTreesWithSamePostOrder(ptrToFirstTree->left,ptrToSecondTree->left)){
		return false;
	}
	if(!areTreesWithSamePostOrder(ptrToFirstTree->right,ptrToSecondTree->right)){
		return false;
	}
	return ptrToFirstTree->value == ptrToSecondTree->value ?true:false;
}

bool areTwoTreesIdenticalPreInOrderTraversal(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	return areTreesWithSamePreOrder(ptrToFirstTree,ptrToSecondTree) && areTreesWithSameInOrder(ptrToFirstTree,ptrToSecondTree);
}

bool areTwoTreesIdenticalPostInOrderTraversal(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	return areTreesWithSamePostOrder(ptrToFirstTree,ptrToSecondTree) && areTreesWithSameInOrder(ptrToFirstTree,ptrToSecondTree);
}

bool areTwoTreesIdenticalPreInOrderTraversalIterative(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}

	stack<tNode *> auxSpaceForFirstTree,auxSpaceForSecondTree;
	auxSpace.push(ptrToFirstTree);
	tNode *currentNodeFirstTree,*currentNodeSecondTree;
	// Checking for pre order traversal
	while(!auxSpaceForFirstTree.empty() && !auxSpaceForSecondTree.empty()){
		currentNodeFirstTree = auxSpaceForFirstTree.top();
		currentNodeSecondTree = auxSpaceForSecondTree.top();
		auxSpaceForFirstTree.pop();
		auxSpaceForSecondTree.pop();
		if(currentNodeFirstTree->value != currentNodeSecondTree->value){
			return false;
		}
		if(currentNodeFirstTree->right != NULL){
			auxSpaceForFirstTree.push(currentNodeFirstTree->right);
		}
		if(currentNodeFirstTree->left != NULL){
			auxSpaceForFirstTree.push(currentNodeFirstTree->left);
		}
		if(currentNodeSecondTree->right != NULL){
			auxSpaceForSecondTree.push(currentNodeSecondTree->right);
		}
		if(currentNodeSecondTree->left != NULL){
			auxSpaceForSecondTree.push(currentNodeSecondTree->left);
		}
	}
	if(!auxSpaceForFirstTree.empty() || !auxSpaceForSecondTree.empty()){
		return false;
	}

	//Checking for in order traversal
	currentNodeFirstTree = ptrToFirstTree;
	currentNodeSecondTree = ptrToSecondTree;
	while(!auxSpaceForFirstTree.empty() && currentNodeFirstTree != NULL && !auxSpaceForSecondTree.empty() && currentNodeSecondTree != NULL){
		if(currentNodeFirstTree == NULL){
			if(currentNodeSecondTree != NULL){
				return false;
			}
			currentNodeFirstTree = auxSpaceForFirstTree.top();
			currentNodeSecondTree = auxSpaceForSecondTree.top();
			if(currentNodeFirstTree->value != currentNodeSecondTree->value){
				return false;
			}
			auxSpaceForFirstTree.pop();
			currentNodeFirstTree = currentNodeFirstTree->right;
			auxSpaceForSecondTree.pop();
			currentNodeSecondTree = currentNodeSecondTree->right;
		}else{
			if(currentNodeSecondTree == NULL){
				return false;
			}
			auxSpaceForFirstTree.push(currentNodeFirstTree);
			currentNodeFirstTree = currentNodeFirstTree->left;
			auxSpaceForSecondTree.push(currentNodeSecondTree);
			currentNodeSecondTree = currentNodeSecondTree->left;
		}
	}
	return true;
}

bool areTwoTreesIdenticalPostInOrderTraversalIterativeTwoStacks(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	//Checking for post order traversal
	stack<tNode *> primaryAuxSpace,secondaryAuxSpaceFirstTree,secondaryAuxSpaceSecondTree;
	tNode *currentNodeFirstTree,*currentNodeSecondTree;
	primaryAuxSpace.push(ptrToFirstTree);
	while(!primaryAuxSpace.empty()){
		currentNodeFirstTree = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpaceFirstTree.push(currentNodeFirstTree);
		if(currentNodeFirstTree->left != NULL){
			primaryAuxSpace.push(currentNodeFirstTree->left);
		}
		if(currentNodeSecondTree->right != NULL){
			primaryAuxSpace.push(currentNodeFirstTree->right);
		}
	}

	primaryAuxSpace.push(ptrToSecondTree);
	while(!primaryAuxSpace.empty()){
		currentNodeSecondTree = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpaceSecondTree.push(currentNodeSecondTree);
		if(currentNodeSecondTree->left != NULL){
			primaryAuxSpace.push(currentNodeSecondTree->left);
		}
		if(currentNodeSecondTree->right != NULL){
			primaryAuxSpace.push(currentNodeSecondTree->right);
		}
	}

	while(!secondaryAuxSpaceFirstTree.empty() && !secondaryAuxSpaceSecondTree.empty()){
		if(secondaryAuxSpaceFirstTree.front()->value != secondaryAuxSpaceSecondTree.front()->value){
			return false;
		}
		secondaryAuxSpaceFirstTree.pop();
		secondaryAuxSpaceSecondTree.pop();
	}
	if(!secondaryAuxSpaceFirstTree.empty() || !secondaryAuxSpaceSecondTree.empty()){
		return false;
	}
	currentNodeFirstTree = ptrToFirstTree;
	currentNodeSecondTree = ptrToSecondTree;
	while(!secondaryAuxSpaceFirstTree.empty() && currentNodeFirstTree != NULL && !secondaryAuxSpaceSecondTree.empty() && currentNodeSecondTree != NULL){
		if(currentNodeFirstTree == NULL){
			if(currentNodeSecondTree != NULL){
				return false;
			}
			currentNodeFirstTree = secondaryAuxSpaceFirstTree.top();
			secondaryAuxSpaceFirstTree.pop();
			currentNodeSecondTree = secondaryAuxSpaceSecondTree.top();
			secondaryAuxSpaceSecondTree.pop();
			if(currentNodeFirstTree->value != currentNodeSecondTree->value){
				return false;
			}
			currentNodeFirstTree = currentNodeFirstTree->right;
			currentNodeSecondTree = currentNodeSecondTree->right;
		}else{
			if(currentNodeSecondTree == NULL){
				return false;
			}
			secondaryAuxSpaceFirstTree.push(currentNodeFirstTree);
			currentNodeFirstTree = currentNodeFirstTree->left;
			secondaryAuxSpaceSecondTree.push(currentNodeSecondTree);
			currentNodeSecondTree = currentNodeSecondTree->left;
		}

	}
	if(!secondaryAuxSpaceFirstTree.empty() || !secondaryAuxSpaceSecondTree.empty()){
		return false;
	}
	if(currentNodeFirstTree != currentNodeSecondTree){
		return false;
	}
	return true;
}

bool areTwoTreesIdenticalPostInOrderTraversalIterativeOneStack(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	//Checking for post order traversal
	stack<tNode *> auxSpaceFirstTree,auxSpaceSecondTree;
	tNode *currentNodeFirstTree,*currentNodeSecondTree,*tempNodeFirstTree,*tempNodeSecondTree;
	currentNodeFirstTree = ptrToFirstTree;
	currentNodeSecondTree = ptrToSecondTree;
	while(!auxSpaceFirstTree.empty() && currentNodeFirstTree != NULL && !auxSpaceSecondTree.empty() && currentNodeSecondTree != NULL){
		if(currentNodeFirstTree != NULL){
			if(currentNodeSecondTree == NULL){
				return false;
			}
			if(currentNodeFirstTree->right != NULL){
				auxSpaceFirstTree.push(currentNodeFirstTree->right);
			}
			auxSpaceFirstTree.push(currentNodeFirstTree);
			currentNodeFirstTree = currentNodeFirstTree->left;
			if(currentNodeSecondTree->right != NULL){
				auxSpaceSecondTree.push(currentNodeSecondTree->right);
			}
			auxSpaceSecondTree.push(currentNodeSecondTree);
			currentNodeSecondTree = currentNodeSecondTree->left;
		}else{
			if(currentNodeSecondTree != NULL){
				return false;
			}
			currentNodeFirstTree = auxSpaceFirstTree.top();
			auxSpaceFirstTree.pop();
			currentNodeSecondTree = auxSpaceSecondTree.top();
			auxSpaceSecondTree.pop();
			if(currentNodeFirstTree->right == auxSpaceFirstTree.top()){
				tempNodeFirstTree = auxSpaceFirstTree.top();
				auxSpaceFirstTree.pop();
				auxSpaceFirstTree.push(currentNodeFirstTree);
				currentNodeFirstTree = tempNodeFirstTree;
			}else{
				if(currentNodeFirstTree->value != currentNodeSecondTree->value){
					return false;
				}
				currentNodeFirstTree = NULL;
				currentNodeSecondTree = NULL;
			}
		}
	}
	if(!auxSpaceFirstTree.empty() || !auxSpaceSecondTree.empty()){
		return false;
	}
	if(currentNodeFirstTree != currentNodeSecondTree){
		return false;
	}
	currentNodeFirstTree = ptrToFirstTree;
	currentNodeSecondTree = ptrToSecondTree;
	while(!auxSpaceFirstTree.empty() && currentNodeFirstTree != NULL && !auxSpaceSecondTree.empty() && currentNodeSecondTree != NULL){
		if(currentNodeFirstTree != NULL){
			if(currentNodeSecondTree == NULL){
				return false;
			}
			auxSpaceFirstTree.push(currentNodeFirstTree);
			auxSpaceSecondTree.push(currentNodeSecondTree);
			currentNodeFirstTree = currentNodeFirstTree->left;
			currentNodeSecondTree = currentNodeSecondTree->left;
		}else{
			if(currentNodeSecondTree != NULL){
				return false;
			}
			currentNodeFirstTree = auxSpaceFirstTree.top();
			auxSpaceFirstTree.pop();
			currentNodeSecondTree = auxSpaceSecondTree.top();
			auxSpaceSecondTree.pop();
			if(currentNodeFirstTree->value != currentNodeSecondTree->value){
				return false;
			}
			currentNodeFirstTree = currentNodeFirstTree->right;
			currentNodeSecondTree = currentNodeSecondTree->right;
		}

	}
	if(!auxSpaceFirstTree.empty() && !auxSpaceSecondTree.empty()){
		return false;
	}
	if(currentNodeFirstTree != currentNodeSecondTree){
		return false;
	}
	return true;
}

bool areTwoTreesIdenticalMorrisTraversalPreInOrder(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return false;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;

	}
	tNode *currentNodeFirstTree,*currentNodeSecondTree,*tempNodeFirstTree,*tempNodeSecondTree;
	while(currentNodeFirstTree != NULL && currentNodeSecondTree != NULL){
		if(currentNodeFirstTree->left != NULL){
			if(currentNodeSecondTree == NULL){
				return false;
			}
			tempNodeFirstTree = currentNodeFirstTree->left;
			tempNodeSecondTree = currentNodeSecondTree->left;
			while(tempNodeFirstTree->right != NULL && tempNodeFirstTree != currentNodeFirstTree){
				tempNodeFirstTree = tempNodeFirstTree->right;
			}
			if(tempNodeFirstTree->right == currentNodeFirstTree){
				tempNodeFirstTree->right = NULL;
				currentNodeFirstTree = currentNodeFirstTree->right;
			}else{
				if(currentNodeFirstTree->value != currentNodeSecondTree->value){
					return false;
				}
				tempNodeFirstTree->right = currentNodeFirstTree;
				currentNodeFirstTree = currentNodeFirstTree->left;
			}
			if(tempNodeFirstTree->right == currentNodeSecondTree){
				tempNodeFirstTree->right = NULL;
				currentNodeSecondTree = currentNodeSecondTree->right;
			}else{
				if(currentNodeFirstTree->value != currentNodeSecondTree->value){
					return false;
				}
				tempNodeSecondTree->right = currentNodeSecondTree;
				currentNodeSecondTree = currentNodeSecondTree->left;
			}
		}else{
			if(currentNodeSecondTree != NULL){
				return false;
			}
			if(currentNodeFirstTree->value != currentNodeSecondTree->value){
				return false;
			}
			currentNodeFirstTree = currentNodeFirstTree->right;
			currentNodeSecondTree = currentNodeSecondTree->right;
		}
	}
	if(currentNodeFirstTree != currentNodeSecondTree){
		return false;
	}
	currentNodeFirstTree = ptrToFirstTree;
	currentNodeSecondTree = ptrToSecondTree;
	while(currentNodeFirstTree != NULL && currentNodeSecondTree != NULL){
		if(currentNodeFirstTree->left != NULL){
			if(currentNodeSecondTree->left == NULL){
				return false;
			}
			tempNodeFirstTree = currentNodeFirstTree->left;
			tempNodeSecondTree = currentNodeSecondTree->left;
			while(tempNodeFirstTree->right != NULL && tempNodeFirstTree->right != currentNodeFirstTree){
				tempNodeFirstTree = tempNodeFirstTree->right;
			}
			while(tempNodeSecondTree->right != NULL && tempNodeSecondTree->right != currentNodeSecondTree){
				tempNodeSecondTree = tempNodeSecondTree->right;
			}
			if(tempNodeFirstTree->right == currentNodeFirstTree){
				if(currentNodeFirstTree->value != currentNodeSecondTree->value){
					return false;
				}
				tempNodeFirstTree->right = NULL;
				currentNodeFirstTree = currentNodeFirstTree->right;
			}else{
				tempNodeFirstTree->right = currentNodeFirstTree;
				currentNodeFirstTree = currentNodeFirstTree->left;
			}
			if(tempNodeSecondTree->right == currentNodeSecondTree){
				if(currentNodeFirstTree->value != currentNodeSecondTree->value){
					return false;
				}
				tempNodeFirstTree->right = NULL;
				currentNodeSecondTree = currentNodeSecondTree->right;
			}else{
				tempNodeFirstTree->right = currentNodeSecondTree;
				currentNodeSecondTree = currentNodeSecondTree->left;
			}
		}else{
			if(currentNodeSecondTree->left != NULL){
				return false;
			}
			if(currentNodeFirstTree->value != currentNodeSecondTree->value){
				return false;
			}
			currentNodeFirstTree = currentNodeFirstTree->right;
			currentNodeSecondTree = currentNodeSecondTree->right;
		}
	}
	if(currentNodeFirstTree != currentNodeSecondTree){
		return false;
	}
	return true;
}

bool areTwoTreesIdenticalHashMapComparison(tNode *ptrToFirstTree,tNode *ptrToSecondTree){
	if(ptrToFirstTree == NULL && ptrToSecondTree == NULL){
		return true;
	}
	if(ptrToFirstTree == NULL || ptrToSecondTree == NULL){
		return false;
	}
	tHashMap *hashMapFormFirstTree = getHashmapFormOfTree(ptrToFirstTree,1);
	tHashMap *hashMapFormSecondTree = getHashmapFormOfTree(ptrToSecondTree,1);
	hash_map<unsigned int,tNode *>::iterator itToHashMapFirstTree,itToHashMapSecondTree;
	for(itToHashMapFirstTree = hashMapFormFirstTree->indexNodeMap.begin();itToHashMapFirstTree != hashMapFormFirstTree->indexNodeMap.end();itToHashMapFirstTree++){
		if((itToHashMapSecondTree = hashMapFormSecondTree->indexNodeMap.find(itToHashMapFirstTree->first)) == hashMapFormSecondTree->indexNodeMap.end()){
			return false;
		}
		if(itToHashMapFirstTree->second->value != itToHashMapSecondTree->second->value){
			return false;
		}
	}
	return true;
}

#endif /* IDENTICALTREE_H_ */
/************************************************* End code *******************************************************/
