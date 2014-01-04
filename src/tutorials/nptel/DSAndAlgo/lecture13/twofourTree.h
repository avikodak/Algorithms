/***************************************************************************************************************** 
 *  File Name   		: twofourTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture13\twofourTree.h
 *  Created on			: Jan 2, 2014 :: 7:36:53 PM
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
#define CHILDREN 4
#define FIRST_CHILD_INDEX 0
#define LAST_CHILD_INDEX 2
#define FIRST_CHILD_PTR_INDEX 0
#define LAST_CHILD_PTR_INDEX 3
#define FIRST_SPLIT_NODE 0
#define SECOND_SPLIT_NODE 1
/************************************************* Main code  ******************************************************/

#ifndef TWOFOURTREE_H_
#define TWOFOURTREE_H_

struct t24Node{
	int value[CHILDREN-1];
	t24Node *children[CHILDREN];
	t24Node *parent;
	unsigned int noChildren;
};

t24Node *createNew24Node(int userInput){
	t24Node *newNode = (t24Node *)malloc(sizeof(t24Node));
	newNode->value[FIRST_CHILD_INDEX] = userInput;
	for(unsigned int counter = 0;counter < CHILDREN;counter++){
		newNode->children[counter] = NULL;
	}
	newNode->noChildren = 1;
	newNode->parent = NULL;
	return newNode;
}

bool doesValueExists(t24Node *ptr,int value){
	if(ptr == NULL){
		return false;
	}
	t24Node *crawler = ptr;
	if(ptr->value[FIRST_CHILD_INDEX] > value){
		return doesValueExists(ptr->children[FIRST_CHILD_PTR_INDEX],value);
	}
	if(ptr->value[LAST_CHILD_INDEX] < value){
		return doesValueExists(ptr->children[LAST_CHILD_PTR_INDEX],value);
	}
	for(unsigned int counter = 0;counter < CHILDREN-2;counter++){
		if(ptr->value[counter] == value){
			return true;
		}
		if(ptr->value[counter] > value && ptr->value[counter+1] < value){
			return doesValueExists(ptr->children[counter+1]);
		}
	}
	return false;
}

t24Node *searchForNode(t24Node *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value[FIRST_CHILD_INDEX] > value){
		return searchForNode(ptr->children[FIRST_CHILD_PTR_INDEX],value);
	}
	if(ptr->value[LAST_CHILD_INDEX] < value){
		return searchForNode(ptr->children[LAST_CHILD_PTR_INDEX],value);
	}
	for(unsigned int counter = 0;counter < CHILDREN-2;counter++){
		if(ptr->value[counter] == value){
			return ptr;
		}
		if(ptr->value[counter] > value && ptr->value[counter+1] < value){
			return searchForNode(ptr->children[counter+1]);
		}
	}
	return NULL;
}

t24Node *getNodeForInsertion(t24Node *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value[FIRST_CHILD_INDEX] > value){
		if(ptr->children[FIRST_CHILD_PTR_INDEX] == NULL){
			return ptr;
		}
		return getNodeForInsertion(ptr->children[FIRST_CHILD_PTR_INDEX]);
	}
	if(ptr->value[LAST_CHILD_INDEX] < value){
		if(ptr->children[LAST_CHILD_PTR_INDEX] == NULL){
			return ptr;
		}
		return getNodeForInsertion(ptr->children[LAST_CHILD_PTR_INDEX]);
	}
	for(unsigned int counter = 0;counter < CHILDREN - 2;counter++){
		if(ptr->value[counter] == value){
			return NULL;
		}
		if(ptr->value[counter] > value && ptr->value[counter+1] < value){
			if(ptr->children[counter+1] == NULL){
				return ptr->children[counter+1];
			}
			return getNodeForInsertion(ptr->children[counter+1],value);
		}
	}
}

unsigned int insertIntoNodeBySort(t24Node *ptr,int userInput){
	unsigned int counter;
	for(counter = nodeforinsertion->noChildren;counter >= 0;counter--){
		if(ptr->value[counter] > value){
			ptr->value[counter+1] = ptr->value[counter];
		}else{
			break;
		}
	}
	ptr->value[counter+1] = value;
	ptr->noChildren += 1;
	return counter+1;
}

t24Node *getSplitNodes(t24Node *ptr,int userInput){
	t24Node *splitNodes[2];
	splitNodes[FIRST_SPLIT_NODE] = createNew24Node(ptr->value[FIRST_CHILD_INDEX]);
	splitNodes[SECOND_SPLIT_NODE] = createNew24Node(ptr->value[FIRST_CHILD_INDEX]);
	vector<int> values;
	values.push_back(userInput);
	for(unsigned int counter = 0;counter < CHILDREN-1;counter++){
		values.push_back(ptr->value[counter]);
	}
	sort(values.front(),values.back());

	splitNodes[FIRST_SPLIT_NODE]->value[0] = values[0];
	splitNodes[FIRST_SPLIT_NODE]->value[1] = values[1];
	splitNodes[SECOND_SPLIT_NODE]->value[0] = values[2];
	splitNodes[SECOND_SPLIT_NODE]->value[1] = values[3];
	return splitNodes;
}

bool insertWithSplit(t24Node *ptr,int userInput){
	t24Node *splitNodesChildren = getSplitNodes(ptr,userInput);
	t24Node *crawler = ptr;
	if(crawler->parent != NULL){
		if(crawler->parent->noChildren == CHILDREN - 1){

		}else{

		}
	}else{
		t24Node *newRoot = createNew24Node(splitNodesChildren[FIRST_SPLIT_NODE]->value[1]);
		newRoot->children[0] = splitNodesChildren[FIRST_SPLIT_NODE];
		newRoot->children[1] = splitNodesChildren[SECOND_SPLIT_NODE];
		return newRoot;
	}
}

void insertInto24Tree(t24Node **ptr,int value){
	if(*ptr == NULL){
		(*ptr) = createNew24Node(value);
	}else{
		t24Node *nodeforinsertion = getNodeForInsertion(*ptr,value);
		if(nodeforinsertion->noChildren == CHILDREN-1){
			value = insertWithSplit(nodeforinsertion,value);
		}else{
			insertIntoNodeBySort(nodeforinsertion,value);
		}
	}
}

void deleteFrom24Tree(t24Node **ptr,int value){

}

void inOrderTraversal24Tree(t24Node *ptr){

}


#endif /* TWOFOURTREE_H_ */
/************************************************* End code *******************************************************/
