/***************************************************************************************************************** 
 *  File Name   		: bfs.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture26\bfs.h
 *  Created on			: Jan 24, 2014 :: 10:37:01 PM
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

#ifndef BFS_H_
#define BFS_H_

/**
 * Assuming graph is connected
 */
void bfs(vector<vector<unsigned int> > adjacencyList,unsigned int startIndex){
	if(adjacencyList.size() == 0 || startIndex >= adjacencyList.size()){
		return;
	}
	queue<unsigned int> auxSpace;
	vector<unsigned int> levels(adjacencyList.size(),UINT_MAX);
	auxSpace.push(startIndex);
	levels[startIndex] = 0;
	unsigned int currentIndex,counter;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(levels[adjacencyList[currentIndex][counter]] == UINT_MAX){
				levels[adjacencyList[currentIndex][counter]] = levels[currentIndex] + 1;
				auxSpace.push(adjacencyList[currentIndex][counter]);
			}
		}
	}
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		printf("%d %d\n",counter,levels[counter]);
	}
}

#endif /* BFS_H_ */

/************************************************* End code *******************************************************/
