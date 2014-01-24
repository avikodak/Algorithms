/***************************************************************************************************************** 
 *  File Name   		: ERROR.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\ERROR.h
 *  Created on			: Jan 17, 2014 :: 7:43:01 PM
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
#define MAX_SIZE 100000
/************************************************* Main code  ******************************************************/

#ifndef ERROR_H_
#define ERROR_H_

void ERROR(){
	unsigned int testCases = 0,lengthOfUserInput;
	char userInput[MAX_SIZE];
	bool isFound;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%s",userInput);
		lengthOfUserInput = strlen(userInput);
		isFound = false;
		for(unsigned int counter = 1;counter < lengthOfUserInput-1;counter++){
			if(userInput[counter] == '0'){
				if(userInput[counter-1]== '1' && userInput[counter+1] == '1'){
					isFound = true;
					break;
				}
			}else{
				if(userInput[counter-1] == '0' && userInput[counter+1] == '0'){
					isFound = true;
					break;
				}
			}
		}
		if(isFound){
			printf("Good\n");
		}else{
			printf("Bad\n");
		}
	}
}


#endif /* ERROR_H_ */

/************************************************* End code *******************************************************/
