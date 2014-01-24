/***************************************************************************************************************** 
 *  File Name   		: NextRound.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codeforces\NextRound.h
 *  Created on			: Jan 24, 2014 :: 11:35:07 AM
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
#define MAX_SIZE 51
/************************************************* Main code  ******************************************************/

#ifndef NEXTROUND_H_
#define NEXTROUND_H_

int main(){
	unsigned int scores,participants,counter,nextRound=0;
	scanf("%d",&participants);
	unsigned int userInputs[MAX_SIZE];
	scanf("%d",&scores);
	for(counter = 0;counter < participants;counter++){
		scanf("%d",&userInputs[counter]);
	}
	for(counter = 0;counter < participants;counter++){
		if(userInputs[counter] >= userInputs[scores-1] && userInputs[counter] !=0){
			nextRound++;
		}
	}
	printf("%d",nextRound);
}
/************************************************* End code *******************************************************/


#endif /* NEXTROUND_H_ */
