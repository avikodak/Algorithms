/***************************************************************************************************************** 
 *  File Name   		: dfsDirected.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture29\dfsDirected.h
 *  Created on			: Jan 25, 2014 :: 2:50:47 AM
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

#ifndef DFSDIRECTED_H_
#define DFSDIRECTED_H_

void dfsDirected(vector<vector<unsigned int> > adjacencyList,unsigned int nodeCounter,vector<unsigned int> &arrivalTimes,vector<unsigned int> &departureTimes){
	if(adjacencyList.size() == 0 || nodeCounter >= adjacencyList.size()){
		return;
	}
	static unsigned int timeCounter = 0;
	arrivalTimes[nodeCounter] = timeCounter++;
	for(unsigned int counter = 0;counter < adjacencyList[nodeCounter].size();counter++){
		if(arrivalTimes[adjacencyList[nodeCounter][counter]] == UINT_MAX){
			dfsDirected(adjacencyList,adjacencyList[nodeCounter][counter],arrivalTimes,departureTimes);
		}
	}
	departureTimes[nodeCounter]  = timeCounter++;
}

#endif /* DFSDIRECTED_H_ */

/************************************************* End code *******************************************************/
