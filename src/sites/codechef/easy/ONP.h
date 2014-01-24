/***************************************************************************************************************** 
 *  File Name   		: ONP.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codechef\easy\ONP.h
 *  Created on			: Jan 23, 2014 :: 6:28:09 PM
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
#define MAX_SIZE 401
/************************************************* Main code  ******************************************************/

#ifndef ONP_H_
#define ONP_H_

void ONP(){
	unsigned int testCases = 0,counter,lengthOfUserInput;
	char userInput[MAX_SIZE];
	map<char,unsigned int> operatorPrecedence;
	operatorPrecedence.insert(pair<char,unsigned int>('-',0));
	operatorPrecedence.insert(pair<char,unsigned int>('+',1));
	operatorPrecedence.insert(pair<char,unsigned int>('*',2));
	operatorPrecedence.insert(pair<char,unsigned int>('/',3));
	operatorPrecedence.insert(pair<char,unsigned int>('^',4));
	scanf("%u",&testCases);
	stack<char> auxSpaceOperators;

	while(testCases--){
		scanf("%s",userInput);
		lengthOfUserInput = strlen(userInput);
		for(counter = 0;counter < lengthOfUserInput;counter++){
			if(userInput[counter] == '*' || userInput[counter] == '+' || userInput[counter] == '-' || userInput[counter] == '/' || userInput[counter] == '^' || userInput[counter] == '(' || userInput[counter] == ')'){
				if(userInput[counter] == ')'){
					while(auxSpaceOperators.top() != '('){
						printf("%c",auxSpaceOperators.top());
						auxSpaceOperators.pop();
					}
					auxSpaceOperators.pop();
				}else{
					if(userInput[counter] == '('){
						auxSpaceOperators.push('(');
					}else{
						while(operatorPrecedence[auxSpaceOperators.top()] > operatorPrecedence[userInput[counter]]){
							printf("%c",auxSpaceOperators.top());
							auxSpaceOperators.pop();
						}
						auxSpaceOperators.push(userInput[counter]);
					}
				}
			}else{
				printf("%c",userInput[counter]);
			}
		}
		printf("\n");
	}
}

#endif /* ONP_H_ */

/************************************************* End code *******************************************************/
