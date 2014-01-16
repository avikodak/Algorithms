/***************************************************************************************************************** 
 *  File Name   		: printMatrixInSpiralForm.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page05\printMatrixInSpiralForm.h
 *  Created on			: Jan 7, 2014 :: 12:18:43 PM
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

#ifndef PRINTMATRIXINSPIRALFORM_H_
#define PRINTMATRIXINSPIRALFORM_H_

void printMatrixInSpiralFormIterative(vector<vector<int> > userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int minRow = 0,maxRow = userInput.size(),minColumn = 0,maxColumn = userInput[0].size();
	while(minRow <= maxRow && minColumn <= maxColumn){
		for(unsigned int columnCounter = minColumn;columnCounter < maxColumn;columnCounter++){
			printf("%d\t",userInput[minRow][columnCounter]);
		}

		for(unsigned int rowCounter = minRow;rowCounter < maxRow;rowCounter++){
			printf("%d\t",userInput[rowCounter][maxColumn]);
		}

		for(unsigned int columnCounter = maxColumn;columnCounter >= minColumn;columnCounter--){
			printf("%d\t",userInput[maxRow][columnCounter]);
		}

		for(unsigned int rowCounter = maxRow;rowCounter >= minRow;rowCounter--){
			printf("%d\t",userInput[rowCounter][minColumn]);
		}
		minRow += 1;
		minColumn += 1;
		maxRow -= 1;
		maxColumn -= 1;
	}
}

void printMatriInSpiralForm(vector<vector<int> > userInput,unsigned int minRow,unsigned int maxRow,unsigned int minColumn,unsigned int maxColumn){
	if(userInput.size() == 0){
		return;
	}
	if(minRow > maxRow || minColumn > maxColumn){
		return;
	}
	for(unsigned int columnCounter = minColumn;columnCounter < maxColumn;columnCounter++){
		printf("%d\t",userInput[minRow][columnCounter]);
	}

	for(unsigned int rowCounter = minRow;rowCounter < maxRow;rowCounter++){
		printf("%d\t",userInput[rowCounter][maxColumn]);
	}

	for(unsigned int columnCounter = maxColumn;columnCounter >= minColumn;columnCounter--){
		printf("%d\t",userInput[maxRow][columnCounter]);
	}

	for(unsigned int rowCounter = maxRow;rowCounter >= minRow;rowCounter--){
		printf("%d\t",userInput[rowCounter][minColumn]);
	}
	printMatriInSpiralForm(userInput,minRow+1,maxRow-1,minColumn+1,maxColumn-1);
}

#endif /* PRINTMATRIXINSPIRALFORM_H_ */

/************************************************* End code *******************************************************/
