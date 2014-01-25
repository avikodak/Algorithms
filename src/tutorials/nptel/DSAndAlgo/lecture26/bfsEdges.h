/***************************************************************************************************************** 
 *  File Name   		: bfsEdges.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture26\bfsEdges.h
 *  Created on			: Jan 25, 2014 :: 12:02:40 AM
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

#ifndef BFSEDGES_H_
#define BFSEDGES_H_

/**
 * 0 - Tree edges
 * 1 - back edges
 * 2 - level edges
 */
hash_map<unsigned int,vector<pair<unsigned int,unsigned int> > > classifyEdgesInBFS(const vector<vector<unsigned int> > adjacencyList){
	hash_map<unsigned int,vector<pair<unsigned int,unsigned int> > > edges;
	if(adjacencyList.size() == 0){
		return edges;
	}
	vector<unsigned int> levels(adjacencyList.size(),UINT_MAX);
	queue<unsigned int> auxSpace;
	unsigned int currentIndex,currentLevel;
	auxSpace.push(0);levels[0] = 0;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		currentLevel = levels[currentIndex];
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(levels[adjacencyList[currentIndex][counter]] == UINT_MAX){

			}else{

			}
		}
	}
}


#endif /* BFSEDGES_H_ */

/************************************************* End code *******************************************************/
