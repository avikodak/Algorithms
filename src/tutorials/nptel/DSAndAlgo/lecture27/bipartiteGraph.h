/***************************************************************************************************************** 
 *  File Name   		: bipartiteGraph.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture27\bipartiteGraph.h
 *  Created on			: Jan 24, 2014 :: 10:41:17 PM
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

#ifndef BIPARTITEGRAPH_H_
#define BIPARTITEGRAPH_H_

bool isGraphBipartite(vector<vector<unsigned int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	queue<unsigned int> auxSpace;
	unsigned int counter,currentNode,currentNodeLevel;
	vector<unsigned int> level(adjacencyList.size(),UINT_MAX);
	auxSpace.push(0);
	level[0] = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		currentNodeLevel = level[currentNode];
		for(counter = 0;counter < adjacencyList[currentNode].size();counter++){
			if(level[adjacencyList[currentNode][counter]] == UINT_MAX){
				auxSpace.push(adjacencyList[currentNode][counter]);
				level[adjacencyList[currentNode][counter]] = counter+1;
			}else{
				if(level[adjacencyList[currentNode][counter]] == level[adjacencyList[currentNode]]){
					return false;
				}
			}
		}
	}
	return true;
}

#endif /* BIPARTITEGRAPH_H_ */

/************************************************* End code *******************************************************/
