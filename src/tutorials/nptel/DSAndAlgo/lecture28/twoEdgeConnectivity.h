/***************************************************************************************************************** 
 *  File Name   		: twoEdgeConnectivity.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture28\twoEdgeConnectivity.h
 *  Created on			: Jan 25, 2014 :: 2:47:50 AM
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

#ifndef TWOEDGECONNECTIVITY_H_
#define TWOEDGECONNECTIVITY_H_

unsigned int isGraphTwoEdgeConnected(vector<vector<unsigned int> > adjacencyList,unsigned int nodeCounter){
	if(adjacencyList.size() == 0 || nodeCounter >= adjacencyList.size()){
		return true;
	}
	static vector<unsigned int> predecessor(adjacencyList.size(),UINT_MAX);
	static vector<unsigned int> arrivalTimes(adjacencyList.size(),UINT_MAX);
	static vector<unsigned int> departureTimes(adjacencyList.size(),UINT_MAX);
	static unsigned int timeCounter = 0;
	unsigned int minAncestorArrivalTime = timeCounter,initTime = timeCounter;
	arrivalTimes[nodeCounter] = timeCounter++;
	for(unsigned int counter = 0;counter < adjacencyList[nodeCounter].size();counter++){
		if(!adjacencyList[nodeCounter][counter] == predecessor[nodeCounter]){
			if(arrivalTimes[adjacencyList[nodeCounter][counter]] == UINT_MAX){
				predecessor[adjacencyList[nodeCounter][counter]] = nodeCounter;
				minAncestorArrivalTime = min(minAncestorArrivalTime,isGraphTwoEdgeConnected(adjacencyList,adjacencyList[nodeCounter][counter]));
			}else{
				minAncestorArrivalTime = min(minAncestorArrivalTime,arrivalTimes[adjacencyList[nodeCounter][counter]]);
			}
		}
	}
	if(nodeCounter == 0){
		return minAncestorArrivalTime;
	}
	if(minAncestorArrivalTime == UINT_MAX || minAncestorArrivalTime == initTime){
		return UINT_MAX;
	}
	departureTimes[nodeCounter] = timeCounter++;
	return minAncestorArrivalTime;
}

#endif /* TWOEDGECONNECTIVITY_H_ */

/************************************************* End code *******************************************************/
