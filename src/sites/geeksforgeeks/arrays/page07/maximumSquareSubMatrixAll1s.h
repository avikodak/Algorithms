/***************************************************************************************************************** 
 *  File Name   		: maximumSquareSubMatrixAll1s.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page07\maximumSquareSubMatrixAll1s.h
 *  Created on			: Jan 6, 2014 :: 12:04:12 AM
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

#ifndef MAXIMUMSQUARESUBMATRIXALL1S_H_
#define MAXIMUMSQUARESUBMATRIXALL1S_H_

int maximumSquareSubMatrixAllOneON2(vector<vector<int> > userInput){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int rowCrawler = userInput.size(),columnCrawler = userInput[0].size();
	for(unsigned int rowCrawler = 0;rowCrawler < userInput.size();rowCrawler++){
		for(unsigned int columnCrawler = 0;columnCrawler < userInput.size();columnCrawler++){
			for(unsigned int sizeCrawler = 1;sizeCrawler < min(userInput[0].size()-columnCrawler,userInput.size()-rowCrawler);sizeCrawler++){

			}
		}
	}
}

int maximumSquareSubMatrixAllOneON(vector<vector<int> > userInput){
	if(userInput.size() == 0){
		return 0;
	}
	int auxArray[userInput.size()][userInput[0].size()];
	unsigned int rowCounter,columnCounter;
	for(rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		auxArray[rowCounter][0] = userInput[rowCounter][0];
	}
	for(columnCounter = 0;columnCounter < userInput.size();columnCounter++){
		auxArray[0][columnCounter] = userInput[0][columnCounter];
	}
	unsigned int rowIndex,columnIndex;
	unsigned int maxSize = INT_MIN;
	for(rowCounter = 1;rowCounter < userInput.size();rowCounter++){
		for(columnCounter = 1;columnCounter < userInput[0].size();columnCounter++){
			userInput[rowCounter][columnCounter] = min(userInput[rowCounter-1][columnCounter-1],min(userInput[rowCounter-1][columnCounter],userInput[rowCounter][columnCounter-1]))+1;
			maxSize = max(userInput[rowCounter][columnCounter],maxSize);
			columnIndex = columnCounter - maxSize;
			rowCounter = rowCounter - maxSize;
		}
	}
	int *result[3] = {rowCounter,columnCounter,maxSize};
	return result;
}
#endif /* MAXIMUMSQUARESUBMATRIXALL1S_H_ */

/************************************************* End code *******************************************************/
