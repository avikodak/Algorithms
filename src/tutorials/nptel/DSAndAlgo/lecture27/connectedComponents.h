/***************************************************************************************************************** 
 *  File Name   		: connectedComponents.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture27\connectedComponents.h
 *  Created on			: Jan 24, 2014 :: 10:37:30 PM
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

#ifndef CONNECTEDCOMPONENTS_H_
#define CONNECTEDCOMPONENTS_H_

unsigned int findNoOfConnectedComponents(vector<vector<unsigned int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return 0;
	}
	queue<unsigned int> auxSpace;
	unsigned int currentIndex,counter;
	vector<unsigned int> connectedComponent(adjacencyList.size(),UINT_MAX);
	unsigned int componentCounter = 1;
	for(unsigned int nodeCounter = 0;nodeCounter < adjacencyList.size();nodeCounter++){
		if(connectedComponent[nodeCounter] == UINT_MAX){
			auxSpace.push(nodeCounter);
			connectedComponent[nodeCounter] = componentCounter++;
			while(!auxSpace.empty()){
				currentIndex = auxSpace.front();
				auxSpace.pop();
				for(counter = 0;counter < adjacencyList[currentIndex].size();counter++){
					if(connectedComponent[adjacencyList[currentIndex][counter]] == UINT_MAX){
						connectedComponent[adjacencyList[currentIndex][counter]]=connectedComponent[currentIndex];
						auxSpace.push(adjacencyList[currentIndex][counter]);
					}
				}
			}
		}
	}
	return max_element(connectedComponent.begin(),connectedComponent.end());
}

#endif /* CONNECTEDCOMPONENTS_H_ */

/************************************************* End code *******************************************************/
