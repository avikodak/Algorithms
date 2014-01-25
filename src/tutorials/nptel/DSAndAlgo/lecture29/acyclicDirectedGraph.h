/***************************************************************************************************************** 
 *  File Name   		: acyclicDirectedGraph.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture29\acyclicDirectedGraph.h
 *  Created on			: Jan 25, 2014 :: 2:51:24 AM
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

#ifndef ACYCLICDIRECTEDGRAPH_H_
#define ACYCLICDIRECTEDGRAPH_H_

bool isDirectedGraphAcyclic(vector<vector<unsigned int> > adjacencyList,unsigned int nodeCounter){
	if(adjacencyList.size() == 0 || nodeCounter >= adjacencyList.size()){
		return true;
	}
	static vector<unsigned int> arrivalTimes(adjacencyList.size(),UINT_MAX);
	static vector<unsigned int> departureTimes(adjacencyList.size(),UINT_MAX);
	static unsigned int timeCounter;
	arrivalTimes[nodeCounter] = timeCounter++;
	for(unsigned int counter = 0;counter < adjacencyList[nodeCounter].size();counter++){
		if(arrivalTimes[adjacencyList[nodeCounter][counter]] == UINT_MAX){
			if(!isDirectedGraphAcyclic(adjacencyList,adjacencyList[nodeCounter][counter])){
				return false;
			}
		}else{
			if(arrivalTimes[adjacencyList[nodeCounter][counter]] > arrivalTimes[nodeCounter]){
				return false;
			}
		}
	}
	departureTimes[nodeCounter] = timeCounter++;
	return true;
}

#endif /* ACYCLICDIRECTEDGRAPH_H_ */

/************************************************* End code *******************************************************/
