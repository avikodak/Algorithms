/***************************************************************************************************************** 
 *  File Name   		: connectivity.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture27\connectivity.h
 *  Created on			: Jan 24, 2014 :: 10:37:39 PM
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

/************************************************* Main code  ******************************************************/

#ifndef CONNECTIVITY_H_
#define CONNECTIVITY_H_

bool isGraphConnected(vector<vector<unsigned int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	queue<unsigned int> auxSpace;
	vector<unsigned int> level(adjacencyList.size(),UINT_MAX);
	unsigned int currentIndex,counter;
	auxSpace.push(0);
	level[0] = 0;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(level[adjacencyList[currentIndex][counter]] == UINT_MAX){
				auxSpace.push(level[adjacencyList[currentIndex][counter]]);
				level[adjacencyList[currentIndex][counter]] = level[currentIndex] + 1;
			}
		}
	}
	for(counter = 0;counter < adjacencyList.size();counter++){
		if(level[counter] == UINT_MAX){
			return false;
		}
	}
	return true;
}

#endif /* CONNECTIVITY_H_ */

/************************************************* End code *******************************************************/
