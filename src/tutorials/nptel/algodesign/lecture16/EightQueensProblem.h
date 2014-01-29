/***************************************************************************************************************** 
 *  File Name   		: EightQueensProblem.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\algodesign\lecture16\EightQueensProblem.h
 *  Created on			: Jan 29, 2014 :: 10:19:54 AM
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
#include <numeric>
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
#define NQUEENS 8
/************************************************* Main code  ******************************************************/

#ifndef EIGHTQUEENSPROBLEM_H_
#define EIGHTQUEENSPROBLEM_H_

bool isValidState(vector<vector<bool> > auxSpace,unsigned int queenRowIndex,unsigned int queenColumnIndex){
	//Check for column
	for(unsigned int rowCounter = 0;rowCounter < NQUEENS;rowCounter++){
		if(auxSpace[rowCounter][queenColumnIndex]){
			return false;
		}
	}
	//Check for upper left diagonal
	unsigned int rowCounter = queenRowIndex,columnCounter = queenColumnIndex;
	while(rowCounter >= 0 && columnCounter >= 0){
		if(auxSpace[rowCounter][columnCounter]){
			return false;
		}
		rowCounter -= 1;
		columnCounter -= 1;
	}
	//Check for upper right diagonal
	rowCounter = queenRowIndex;columnCounter = queenColumnIndex;
	while(rowCounter >= 0 && columnCounter < NQUEENS){
		if(auxSpace[rowCounter][columnCounter]){
			return false;
		}
		rowCounter -= 1;
		columnCounter += 1;
	}
	return true;
}

bool isValidConfiguration(const vector<vector<bool> > &auxSpace){
	for(unsigned int rowCounter = 0;rowCounter < NQUEENS;rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < NQUEENS;columnCounter++){
			if(auxSpace[rowCounter][columnCounter]){
				if(!isValidState(auxSpace,rowCounter,columnCounter)){
					return false;
				}
			}
		}
	}
	return true;
}

void solveNQueensBruteForce(vector<vector<bool> > auxSpace,unsigned int queenRowIndex){
	if(queenRowIndex > NQUEENS){
		return;
	}
	if(queenRowIndex == NQUEENS){
		if(isValidConfiguration(auxSpace)){
			printf("\n");
			for(unsigned int outerCounter = 0;outerCounter < NQUEENS;outerCounter++){
				for(unsigned int innerCounter = 0;innerCounter < NQUEENS;innerCounter++){
					printf("%b \t",auxSpace[outerCounter][innerCounter]);
				}
				printf("\n");
			}
		}
		return;
	}
	for(unsigned int queenColumnIndex = 0;queenColumnIndex < NQUEENS;queenColumnIndex++){
		auxSpace[queenRowIndex][queenColumnIndex] = true;
		solveNQueensBruteForce(auxSpace,queenRowIndex+1);
		auxSpace[queenRowIndex][queenColumnIndex]= false;
	}
}

void solveNQueensBB(vector<vector<bool> > auxSpace,unsigned int queenRowIndex){
	if(queenRowIndex > NQUEENS){
		return;
	}
	if(queenRowIndex == NQUEENS){
		printf("\n");
		for(unsigned int outerCounter = 0;outerCounter < NQUEENS;outerCounter++){
			for(unsigned int innerCounter = 0;innerCounter < NQUEENS;innerCounter++){
				printf("%b \t",auxSpace[outerCounter][innerCounter]);
			}
			printf("\n");
		}
		return;
	}
	for(unsigned int queenColumnIndex = 0;queenColumnIndex < NQUEENS;queenColumnIndex++){
		if(isValidState(auxSpace,queenRowIndex,queenColumnIndex)){
			auxSpace[queenRowIndex][queenColumnIndex] = true;
			solveNQueens(auxSpace,queenRowIndex+1);
			auxSpace[queenRowIndex][queenColumnIndex] = false;
		}
	}
}

#endif /* EIGHTQUEENSPROBLEM_H_ */

/************************************************* End code *******************************************************/
