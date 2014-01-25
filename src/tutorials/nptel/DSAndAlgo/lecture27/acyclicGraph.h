/***************************************************************************************************************** 
 *  File Name   		: acyclicGraph.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture27\acyclicGraph.h
 *  Created on			: Jan 24, 2014 :: 10:40:00 PM
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

#ifndef ACYCLICGRAPH_H_
#define ACYCLICGRAPH_H_

bool isGraphAcyclic(const vector<vector<unsigned int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	vector<unsigned int> flags(adjacencyList.size(),UINT_MAX);
	queue<unsigned int> auxSpace;
	unsigned int currentIndex;
	auxSpace.push(0);
	flags[0] = true;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(flags[adjacencyList[currentIndex][counter]]){
				return false;
			}
			auxSpace.push(adjacencyList[currentIndex][counter]);
		}
	}
	return true;
}

#endif /* ACYCLICGRAPH_H_ */

/************************************************* End code *******************************************************/
