/***************************************************************************************************************** 
 *  File Name   		: PrintUnqiueRowsInBooleanMatrix.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page03\PrintUnqiueRowsInBooleanMatrix.h
 *  Created on			: Jan 8, 2014 :: 2:23:27 PM
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

#ifndef PRINTUNQIUEROWSINBOOLEANMATRIX_H_
#define PRINTUNQIUEROWSINBOOLEANMATRIX_H_

void printUniqueRowsInBooleanMatrixNaive(vector<vector<bool> > userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int currentRowCounter,rowCounter,columnCounter;
	bool isRowUnique;
	for(currentRowCounter = 0;currentRowCounter < userInput.size();currentRowCounter++){
		isRowUnique = true;
		for(rowCounter = currentRowCounter+1;rowCounter < userInput.size();rowCounter++){
			for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
				if(userInput[currentRowCounter][columnCounter] != userInput[rowCounter][columnCounter]){
					isRowUnique = false;
					break;
				}
			}
			if(!isRowUnique){
				break;
			}
		}
		if(isRowUnique){
			for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
				printf("%d\t",userInput[currentRowCounter][columnCounter]);
			}
			printf("\n");
		}
	}
}

void printUniqueRowsInBooleanMatrixON(vector<vector<bool> > userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int rowCounter,columnCounter,decimalEquivalent;
	hash_map<unsigned int,unsigned int> frequencyMap;
	hash_map<unsigned int,unsigned int>::iterator itToFrequencyMap;
	for(rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		decimalEquivalent = 0;
		for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			decimalEquivalent += pow(2,columnCounter);
		}
		if((itToFrequencyMap = frequencyMap.find(decimalEquivalent)) != frequencyMap.end()){
			frequencyMap[decimalEquivalent] += 1;
		}else{
			for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
				printf("%d\t",userInput[rowCounter][columnCounter]);
			}
			printf("\n");
			frequencyMap.insert(pair<unsigned int,unsigned int>(decimalEquivalent,1));
		}
	}
}

#endif /* PRINTUNQIUEROWSINBOOLEANMATRIX_H_ */

/************************************************* End code *******************************************************/
