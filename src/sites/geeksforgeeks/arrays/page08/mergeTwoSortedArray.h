/***************************************************************************************************************** 
 *  File Name   		: mergeTwoSortedArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page08\mergeTwoSortedArray.h
 *  Created on			: Jan 2, 2014 :: 10:09:04 PM
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

#ifndef MERGETWOSORTEDARRAY_H_
#define MERGETWOSORTEDARRAY_H_

vector<int> mergeTwoSortedArrayBySorting(vector<int> sortedFirstArray,vector<int> sortedSecondArray){
	if(sortedFirstArray.size() == 0 && sortedSecondArray.size() == 0){
		return sortedFirstArray;
	}
	if(sortedFirstArray.size() == 0 || sortedSecondArray.size() == 0){
		if(sortedFirstArray.size() != 0){
			return sortedFirstArray;
		}else{
			return sortedSecondArray;
		}
	}
	vector<int> mergedArray;
	merge(sortedFirstArray.begin(),sortedFirstArray.end(),sortedSecondArray.begin(),sortedSecondArray.end(),mergedArray.begin());
	sort(mergedArray.begin(),mergedArray.end());
	return mergedArray;
}

vector<int> mergeTwoSortedArray(vector<int> sortedFirstArray,vector<int> sortedSecondArray){
	if(sortedFirstArray.size() == 0 && sortedSecondArray.size() == 0){
		return sortedFirstArray;
	}
	if(sortedFirstArray.size() == 0 || sortedSecondArray.size() == 0){
		if(sortedFirstArray.size() != 0){
			return sortedFirstArray;
		}else{
			return sortedSecondArray;
		}
	}
	vector<int> mergedArray;
	unsigned int firstCounter=0,secondCounter=0;
	while(firstCounter < sortedFirstArray.size() && secondCounter < sortedSecondArray.size()){
		if(sortedFirstArray[firstCounter] < sortedSecondArray[secondCounter]){
			mergedArray.push_back(sortedFirstArray[firstCounter]);
			firstCounter += 1;
		}else{
			mergedArray.push_back(sortedSecondArray[secondCounter]);
			secondCounter += 1;
		}
	}
	while(firstCounter < sortedFirstArray.size()){
		mergedArray.push_back(sortedFirstArray[firstCounter]);
		firstCounter++;
	}
	while(secondCounter < sortedSecondArray.size()){
		mergedArray.push_back(sortedSecondArray[secondCounter]);
		secondCounter++;
	}
	return mergedArray;
}

#endif /* MERGETWOSORTEDARRAY_H_ */

/************************************************* End code *******************************************************/
