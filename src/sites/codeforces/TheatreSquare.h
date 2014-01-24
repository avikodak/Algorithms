/***************************************************************************************************************** 
 *  File Name   		: TheatreSquare.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\codeforces\TheatreSquare.h
 *  Created on			: Jan 24, 2014 :: 10:16:04 AM
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

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef THEATRESQUARE_H_
#define THEATRESQUARE_H_

int main(){
	long long int m,n,a;
	scanf("%I64d %I64d %I64d",&m,&n,&a);
	cout << ((m+a-1)/a)*((n+a-1)/a);
}

#endif /* THEATRESQUARE_H_ */

/************************************************* End code *******************************************************/
