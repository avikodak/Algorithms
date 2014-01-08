/***************************************************************************************************************** 
 *  File Name   		: productArrayPuzzle.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\productArrayPuzzle.h
 *  Created on			: Jan 6, 2014 :: 8:49:37 PM
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

#ifndef PRODUCTARRAYPUZZLE_H_
#define PRODUCTARRAYPUZZLE_H_

vector<int> productArrayPuzzle(vector<int> userInput){
	vector<int> productArray;
	if(userInput.size() == 0){
		return productArray;
	}
	vector<int> leftProduct;
	vector<int> rightProduct;
	leftProduct.push_back(1);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftProduct.push_back(leftProduct[counter-1] * userInput[counter-1]);
	}
	rightProduct[userInput.size()-1] = 1;
	for(unsigned int counter = userInput.size()-2;counter >= 0;counter--){
		rightProduct[counter] = rightProduct[counter+1] * userInput[counter+1];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		productArray[counter] = leftProduct[counter] * rightProduct[counter];
	}
	return productArray;
}

#endif /* PRODUCTARRAYPUZZLE_H_ */

/************************************************* End code *******************************************************/
