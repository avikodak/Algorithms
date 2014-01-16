/***************************************************************************************************************** 
 *  File Name   		: huffmanCoding.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture19\huffmanCoding.h
 *  Created on			: Jan 15, 2014 :: 1:18:56 AM
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

#ifndef HUFFMANCODING_H_
#define HUFFMANCODING_H_

struct tHuffmanNode{
	char character;
	unsigned int frequency;
	tHuffmanNode *left;
	tHuffmanNode *right;
};

hash_map<char,vector<bool> > getHuffManCodes(tHuffmanNode *root){

}

vector<bool> encodeIntoHuffmanCode(char *userInput){
	vector<bool> huffmanCodeOfInput;
	if(userInput == NULL){
		return huffmanCodeOfInput;
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < strlen(userInput);counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap.insert(pair<char,unsigned int>(userInput[counter],1));
		}
	}
	hash_map<unsigned int,tHuffmanNode *> frequencyNodeMap;
	hash_map<unsigned int,tHuffmanNode *>::iterator itToFrequencyNodeMap,itToFirstMinNode,itToSecondMinNode;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		tHuffmanNode *newNode = (tHuffmanNode *)malloc(sizeof(tHuffmanNode));
		newNode->character = itToFrequencyMap->first;
		newNode->frequency = itToFrequencyMap->second;
		newNode->left = NULL;
		newNode->right = NULL;
		frequencyNodeMap.insert(pair<unsigned int,tHuffmanNode *>(itToFrequencyMap->second,newNode));
	}
	unsigned int minFrequency = UINT_MAX,secondMinFrequency = UINT_MAX;
	while(frequencyNodeMap.size() != 1){
		for(itToFrequencyNodeMap = frequencyNodeMap.begin();itToFrequencyNodeMap != frequencyNodeMap.end();itToFrequencyNodeMap++){
			if(minFrequency > itToFrequencyNodeMap->first){
				secondMinFrequency = minFrequency;
				itToSecondMinNode = itToFirstMinNode;
				minFrequency = itToFrequencyNodeMap->first;
				itToFirstMinNode = itToFrequencyNodeMap;
			}else{
				if(secondMinFrequency > itToFrequencyNodeMap->first){
					secondMinFrequency = itToFrequencyNodeMap->first;
					itToSecondMinNode = itToFrequencyNodeMap;
				}
			}
		}
		tHuffmanNode *newNode = (tHuffmanNode *)malloc(sizeof(tHuffmanNode));
		newNode->character = '\0';
		newNode->frequency = minFrequency + secondMinFrequency;
		newNode->left = itToFirstMinNode->second;
		newNode->right = itToSecondMinNode->second;
		frequencyNodeMap.insert(pair<unsigned int,tHuffmanNode *>(newNode->frequency,newNode));
		frequencyNodeMap.erase(itToFirstMinNode);
		frequencyNodeMap.erase(itToSecondMinNode);
	}
	tHuffmanNode *huffmanTreeRoot = frequencyNodeMap.begin()->second;
	hash_map<char,vector<bool> > huffmanCodeForChar= getHuffManCodes(huffmanTreeRoot);
	hash_map<char,vector<bool> >::iterator itToHuffmanCodeForChar;
	for(unsigned int counter = 0;counter < strlen(userInput);counter++){
		if((itToHuffmanCodeForChar = huffmanCodeForChar.find(userInput[counter])) != huffmanCodeForChar.end()){
			huffmanCodeOfInput.insert(huffmanCodeOfInput.end(),itToHuffmanCodeForChar->second.begin(),itToHuffmanCodeForChar->second.end());
		}else{
			cout << "Something went wrong" << endl;
			return;
		}
	}
}

#endif /* HUFFMANCODING_H_ */

/************************************************* End code *******************************************************/
