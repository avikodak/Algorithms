/***************************************************************************************************************** 
 *  File Name   		: TSORT.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\TSORT.h
 *  Created on			: Jan 19, 2014 :: 7:34:01 PM
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
#define SIZE 10001
/************************************************* Main code  ******************************************************/

#ifndef TSORT_H_
#define TSORT_H_

void TSORT(){
	unsigned int totalnumbers;
	scanf("%d",&totalnumbers);
	int frequencyCounter[SIZE] = {0};
	int userInput;
	while(totalnumbers){
		scanf("%d",&userInput);
		frequencyCounter[userInput]+=1;
		totalnumbers--;
	}
	for(unsigned int counter = 0;counter < SIZE;counter++){
		while(frequencyCounter[counter]--){
			printf("%d\n",counter);
		}
	}
}

#endif /* TSORT_H_ */

/************************************************* End code *******************************************************/
