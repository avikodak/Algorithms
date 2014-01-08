/***************************************************************************************************************** 
 *  File Name   		: booleanMatrix.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\booleanMatrix.h
 *  Created on			: Jan 7, 2014 :: 1:49:55 PM
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

#ifndef BOOLEANMATRIX_H_
#define BOOLEANMATRIX_H_

void booleanMatrixNaive(vector<vector<bool> > userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int rowCounter,columnCounter;
	bool rowFlags[userInput.size()],columnFlags[userInput[0].size()];
	for(rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			if(userInput[rowCounter][columnCounter]){
				rowFlags[rowCounter] = true;
				columnFlags[columnCounter] = true;
			}
		}
	}

	for(rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			userInput[rowCounter][columnCounter] = rowFlags[rowCounter] || columnFlags[columnCounter];
		}
	}
}

void booleanMatrix(vector<vector<bool> > userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int rowCounter,columnCounter;
	for(rowCounter = 1;rowCounter < userInput.size();rowCounter++){
		for(columnCounter = 1;columnCounter < userInput[0].size();columnCounter++){
			if(userInput[rowCounter][columnCounter]){
				userInput[0][columnCounter] = true;
				userInput[rowCounter][0] = true;
			}
		}
	}
	for(rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			userInput[rowCounter][columnCounter] = userInput[rowCounter][0] || userInput[0][columnCounter];
		}
	}
}

#endif /* BOOLEANMATRIX_H_ */
/************************************************* End code *******************************************************/
