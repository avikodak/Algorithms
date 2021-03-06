/***************************************************************************************************************** 
 *  File Name   		: dfsDirectedEdge.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture29\dfsDirectedEdge.h
 *  Created on			: Jan 25, 2014 :: 2:50:57 AM
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

#ifndef DFSDIRECTEDEDGE_H_
#define DFSDIRECTEDEDGE_H_

/**
 * 0 - Tree edges
 * 1 - Back edges
 * 2 - Front edges
 * 3 - Cross edges
 */

void edgesInDirectedGraph(vector<vector<unsigned int> > adjacencyList,unsigned int nodeCounter,hash_map<unsigned int,vector<pair<unsigned int,unsigned int> > > &edges){
	if(adjacencyList.size() == 0 || nodeCounter >= adjacencyList.size()){
		return;
	}
	static vector<unsigned int> arrivalTimes(adjacencyList.size(),UINT_MAX);
	static vector<unsigned int> departureTimes(adjacencyList.size(),UINT_MAX);
	static unsigned int timeCounter = 0;
	arrivalTimes[nodeCounter] = timeCounter++;
	for(unsigned int counter = 0;counter < adjacencyList[nodeCounter].size();counter++){
		if(arrivalTimes[adjacencyList[nodeCounter][counter]] == UINT_MAX){

		}else{

		}
	}
	departureTimes[nodeCounter] = timeCounter++;
}

#endif /* DFSDIRECTEDEDGE_H_ */

/************************************************* End code *******************************************************/
