/***************************************************************************************************************** 
 *  File Name   		: shortestPath.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture26\shortestPath.h
 *  Created on			: Jan 24, 2014 :: 10:37:18 PM
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

#ifndef SHORTESTPATH_H_
#define SHORTESTPATH_H_

/**
 * This works only when the edge weights on graph are equal
 */
unsigned int shortestPath(vector<vector<unsigned int> > adjacencyList,unsigned int startIndex,unsigned int endIndex){
	if(adjacencyList.size() == 0 || startIndex >= adjacencyList.size() || endIndex >= adjacencyList.size()){
		return UINT_MAX;
	}
	unsigned int counter,currentIndex;
	queue<unsigned int> auxSpace;
	vector<unsigned int> levels(adjacencyList.size(),UINT_MAX);
	auxSpace.push(startIndex);
	levels[startIndex] = 0;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(levels[adjacencyList[currentIndex][counter]] == UINT_MAX){
				levels[adjacencyList[currentIndex][counter]] = levels[currentIndex]+1;
				if(adjacencyList[currentIndex][counter] == endIndex){
					return levels[currentIndex]+1;
				}
				auxSpace.push(adjacencyList[currentIndex][counter]);
			}
		}
	}
	return UINT_MAX;
}


#endif /* SHORTESTPATH_H_ */

/************************************************* End code *******************************************************/
