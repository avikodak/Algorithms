/***************************************************************************************************************** 
 *  File Name   		: dfs.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture28\dfs.h
 *  Created on			: Jan 24, 2014 :: 10:40:18 PM
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

#ifndef DFS_H_
#define DFS_H_

void dfs(vector<vector<unsigned int> > adjacencyList,unsigned int nodeCounter){
	if(adjacencyList.size() == 0 || counter >= adjacencyList.size()){
		return;
	}
	static vector<unsigned int> arrivalTimes(adjacencyList.size(),UINT_MAX);
	static vector<unsigned int> departureTimes(adjacencyList.size(),UINT_MAX);
	static unsigned int arrivalTimes = 0;
	arrivalTimes[nodeCounter] = arrivalTimes++;
	for(unsigned int counter = 0;counter < adjacencyList[nodeCounter].size();counter++){
		if(adjacencyList[nodeCounter][counter] == UINT_MAX){
			dfs(adjacencyList,adjacencyList[nodeCounter][counter]);
		}
	}
	departureTimes[nodeCounter] = arrivalTimes++;
}

#endif /* DFS_H_ */

/************************************************* End code *******************************************************/
