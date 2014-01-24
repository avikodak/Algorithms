/***************************************************************************************************************** 
 *  File Name   		: adjacencyMatrix.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture25\adjacencyMatrix.h
 *  Created on			: Jan 24, 2014 :: 10:34:21 PM
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

#ifndef ADJACENCYMATRIX_H_
#define ADJACENCYMATRIX_H_

bool *createAdjacencyMatrixUndirected(unsigned int noOfVertices){
	bool adjacencyMatrix[noOfVertices][noOfVertices] = {false};
	unsigned int noOfEdges;
	scanf("%u",&noOfEdges);
	unsigned int adjacentVertices[2];
	while(noOfEdges--){
		scanf("%u",adjacentVertices[0]);
		scanf("%u",adjacentVertices[1]);
		adjacencyMatrix[adjacentVertices[0]][adjacentVertices[1]] = true;
		adjacencyMatrix[adjacentVertices[1]][adjacentVertices[0]] = true;
	}
	return adjacencyMatrix;
}

bool *createAdjacencyMatrixDirected(unsigned int noOfVertices){
	bool adjacencyMatrix[noOfVertices][noOfVertices] = {false};
	unsigned int noOfEdges;
	scanf("%u",&noOfEdges);
	unsigned int adjacentVertices[2];
	while(noOfEdges--){
		scanf("%u",adjacentVertices[0]);
		scanf("%u",adjacentVertices[1]);
		adjacencyMatrix[adjacentVertices[0]][adjacentVertices[1]] = true;
	}
	return adjacencyMatrix;
}
#endif /* ADJACENCYMATRIX_H_ */

/************************************************* End code *******************************************************/
