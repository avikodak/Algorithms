/***************************************************************************************************************** 
 *  File Name   		: sort0s1s2s.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page06\sort0s1s2s.h
 *  Created on			: Jan 6, 2014 :: 8:50:13 PM
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

#ifndef SORT0S1S2S_H_
#define SORT0S1S2S_H_

void sort0s1s2sON(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int zeroCounter = 0,oneCounter = 0,twoCounter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		switch (userInput[counter]) {
		case 0:
			zeroCounter += 1;
			break;
		case 1:
			oneCounter +=  1;
			break;
		case 2:
			twoCounter += 1;
			break;
		}
	}
	unsigned int fillCounter = 0;
	while(zeroCounter--){
		userInput[fillCounter++] = 0;
	}
	while(oneCounter--){
		userInput[fillCounter++] = 1;
	}
	while(twoCounter--){
		userInput[fillCounter++] = 2;
	}
}

void sort0s1s2sONLOGN(vector<unsigned int> userInput){
	sort(userInput.begin(),userInput.end());
}

#endif /* SORT0S1S2S_H_ */

/************************************************* End code *******************************************************/
