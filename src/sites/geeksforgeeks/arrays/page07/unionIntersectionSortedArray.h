/***************************************************************************************************************** 
 *  File Name   		: unionIntersectionSortedArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\unionIntersectionSortedArray.h
 *  Created on			: Jan 5, 2014 :: 11:55:40 PM
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

#ifndef UNIONINTERSECTIONSORTEDARRAY_H_
#define UNIONINTERSECTIONSORTEDARRAY_H_

void moveAheadForSameValue(vector<int> userInput,unsigned int &crawler){
	if(userInput.size() == 0){
		return;
	}
	while(crawler < userInput.size() && crawler + 1  < userInput.size() && userInput[crawler] == userInput[crawler+1]){
		crawler += 1;
	}
	crawler += 1;
}

vector<vector<int> > unionIntersectionSortedArrayON(vector<int> firstArray,vector<int> secondArray){
	vector<vector<int> > unionIntersection;
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return unionIntersection;
	}
	vector<int> unionArray,intersectionArray;
	unsigned int firstArrayCrawler = 0,secondArrayCrawler = 0;
	while(firstArrayCrawler < firstArray.size() && secondArrayCrawler < secondArray.size()){
		if(firstArray[firstArrayCrawler] == secondArray[secondArrayCrawler]){
			unionArray.push_back(firstArray[firstArrayCrawler]);
			while(firstArray[firstArrayCrawler] == secondArray[secondArrayCrawler]){
				intersectionArray.push_back(firstArray[firstArrayCrawler]);
				firstArrayCrawler += 1;
				secondArrayCrawler += 1;
			}
			moveAheadForSameValue(firstArray,firstArrayCrawler);
			moveAheadForSameValue(secondArray,secondArrayCrawler);
		}else{
			if(firstArray[firstArrayCrawler] < secondArray[secondArrayCrawler]){
				unionArray.push_back(firstArray[firstArrayCrawler]);
				moveAheadForSameValue(firstArray,firstArrayCrawler);
			}else{
				unionArray.push_back(secondArray[secondArrayCrawler]);
				moveAheadForSameValue(secondArray,secondArrayCrawler);
			}
		}
	}
	unionIntersection.push_back(unionArray);
	unionIntersection.push_back(intersectionArray);
	return unionIntersection;
}

struct tBstTwoFrequency{
	int value;
	unsigned int firstVectorFrequency;
	unsigned int secondVectorFrequency;
	bstTwoFrequency *left;
	bstTwoFrequency *right;
};

tBstTwoFrequency *createNewTwoFrequencyNode(int userInput){
	tBstTwoFrequency *currentNode = (tBstTwoFrequency *)malloc(sizeof(tBstTwoFrequency));
	currentNode->value = userInput;
	currentNode->firstVectorFrequency = 0;
	currentNode->secondVectorFrequency = 0;
	currentNode->left = NULL;
	currentNode->right = NULL;
	return currentNode;
}

void createTwoFrequencyBST(tBstTwoFrequency **ptr,tBstTwoFrequency *currentNode,vector<int> userInput,unsigned int currentIndex,bool isFirstVector){
	if(*ptr == NULL){
		(*ptr) = createNewTwoFrequencyNode(userInput[currentIndex]);
		if(isFirstVector){
			(*ptr)->firstVectorFrequency = 1;
		}else{
			(*ptr)->secondVectorFrequency = 1;
		}
		createTwoFrequency(ptr,*ptr,userInput,currentIndex+1,isFirstVector);
	}else{
		if(currentNode->value == userInput[currentIndex]){
			if(isFirstVector){
				currentNode->firstVectorFrequency += 1;
			}else{
				currentNode->secondVectorFrequency += 1;
			}
			createTwoFrequency(ptr,*ptr,userInput,currentIndex+1,isFirstVector);
		}else{
			if(currentNode->value > userInput[currentIndex]){
				if(currentNode->left == NULL){
					currentNode->left = createNewTwoFrequencyNode(userInput[currentIndex]);
					createTwoFrequency(ptr,currentNode->left,userInput,currentIndex+1,isFirstVector);
				}else{
					createTwoFrequency(ptr,*ptr,userInput,currentIndex+1,isFirstVector);
				}
			}else{
				if(currentNode->right == NULL){
					currentNode->right = createNewTwoFrequencyNode(userInput[currentIndex]);
					createTwoFrequency(ptr,currentNode->right,userInput,currentIndex+1,isFirstVector);
				}else{
					createTwoFrequency(ptr,*ptr,userInput,currentIndex+1,isFirstVector);
				}
			}
		}
	}
}

void fillUnionAndIntersectionForFBST(tBstTwoFrequency *ptr,vector<int> &unionArray,vector<int> &intersectionArray){
	if(ptr == NULL){
		return;
	}
	unionArray.push_back(ptr->value);
	unsigned int firstArrayCounter = ptr->firstVectorFrequency,secondArrayCounter = ptr->secondVectorFrequency;
	while(firstArrayCounter == secondArrayCounter){
		intersectionArray.push_back(ptr->value);
		firstArrayCounter--;
		secondArrayCounter--;
	}
	fillUnionAndIntersectionForFBST(ptr->left,unionArray,intersectionArray);
	fillUnionAndIntersectionForFBST(ptr->right,unionArray,intersectionArray);
}

vector<vector<int> > unionIntersectionBSTON(vector<int> firstArray,vector<int> secondArray){
	vector<vector<int> > unionIntersection;
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return unionIntersection;
	}
	vector<int> unionArray,intersectionArray;
	tBstTwoFrequency *rootBST;
	createTwoFrequencyBST(&rootBST,NULL,firstArray,0,true);
	createTwoFrequencyBST(&rootBST,NULL,secondArray,0,false);
	fillUnionAndIntersectionForFBST(rootBST,unionArray,intersectionArray);
	unionIntersection.push_back(unionArray);
	unionIntersection.push_back(intersectionArray);
	return unionIntersection;
}


#endif /* UNIONINTERSECTIONSORTEDARRAY_H_ */

/************************************************* End code *******************************************************/
