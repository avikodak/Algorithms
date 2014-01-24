/***************************************************************************************************************** 
 *  File Name   		: Watermelon4A.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codeforces\Watermelon4A.h
 *  Created on			: Jan 24, 2014 :: 11:03:44 AM
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

#ifndef WATERMELON4A_H_
#define WATERMELON4A_H_

void watermelon(){
	long long int weight;
	scanf("%I64d",&weight);
	if(weight > 2 && weight%2 == 0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}

#endif /* WATERMELON4A_H_ */

/************************************************* End code *******************************************************/
