/***************************************************************************************************************** 
 *  File Name   		: topologicalSort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture29\topologicalSort.h
 *  Created on			: Jan 25, 2014 :: 12:14:13 PM
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

#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_

void topologicalSort(const vector<vector<unsigned int> > adjacencyList,unsigned int nodeIndex,vector<unsigned int> &sortOrder){
	if(adjacencyList.size() == 0 || nodeIndex >= adjacencyList.size()){
		return;
	}
	static unsigned int arrivalTimes[adjacencyList.size()];
	static unsigned int timeCounter = 0;
	arrivalTimes[nodeIndex] = timeCounter++;
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		if(arrivalTimes[adjacencyList[nodeIndex][counter]] == UINT_MAX){
			topologicalSort(adjacencyList,adjacencyList[nodeIndex][counter],sortOrder);
		}
	}
	sortOrder.push_back(nodeIndex);
}

#endif /* TOPOLOGICALSORT_H_ */

/************************************************* End code *******************************************************/
