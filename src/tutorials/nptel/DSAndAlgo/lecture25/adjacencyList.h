/***************************************************************************************************************** 
 *  File Name   		: adjacencyList.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture25\adjacencyList.h
 *  Created on			: Jan 24, 2014 :: 10:34:10 PM
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

#ifndef ADJACENCYLIST_H_
#define ADJACENCYLIST_H_

vector<vector<unsigned int> > createAdjacencyListUndirected(){
	vector<vector<unsigned int> > adjacencyList;
	unsigned int noOfEdges;
	unsigned int adjacentIndex[2];
	scanf("%u",&noOfEdges);
	while(noOfEdges--){
		scanf("%u %u",&adjacentIndex[0],&adjacentIndex[1]);
		adjacencyList[adjacentIndex[0]].push_back(adjacentIndex[1]);
		adjacencyList[adjacentIndex[1]].push_back(adjacentIndex[0]);
	}
	return adjacencyList;
}

vector<vector<unsigned int> > createAdjacencyListDirected(){
	vector<vector<unsigned int> > adjacencyList;
	unsigned int noOfEdges;
	unsigned int adjacentIndex[2];
	scanf("%u",&noOfEdges);
	while(noOfEdges--){
		scanf("%u %u",&adjacentIndex[0],&adjacentIndex[1]);
		adjacencyList[adjacentIndex[0]].push_back(adjacentIndex[1]);
	}
	return adjacencyList;
}

#endif /* ADJACENCYLIST_H_ */

/************************************************* End code *******************************************************/
