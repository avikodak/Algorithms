/***************************************************************************************************************** 
 *  File Name   		: acyclicGraphDfs.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture28\acyclicGraphDfs.h
 *  Created on			: Jan 25, 2014 :: 2:52:38 AM
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

#ifndef ACYCLICGRAPHDFS_H_
#define ACYCLICGRAPHDFS_H_

bool isGraphAcyclic(vector<vector<unsigned int> > adjacencyList,unsigned int nodeCounter){
	if(adjacencyList.size() == 0 || counter >= adjacencyList.size()){
		return true;
	}
	static vector<unsigned int> arrivalTimes = {UINT_MAX};
	static vector<unsigned int> departureTimes = {UINT_MAX};
	static unsigned int timeCounter = 0;
	arrivalTimes[nodeCounter] = timeCounter++;
	for(unsigned int counter = 0;counter < adjacencyList[nodeCounter].size();counter++){
		if(arrivalTimes[adjacencyList[nodeCounter][counter]] ==UINT_MAX){
			if(!isGraphAcyclic(adjacencyList,counter)){
				return false;
			}
		}else{
			return false;
		}
	}
	departureTimes[counter] == timeCounter++;
	return true;
}

#endif /* ACYCLICGRAPHDFS_H_ */

/************************************************* End code *******************************************************/
