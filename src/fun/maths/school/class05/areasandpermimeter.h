/***************************************************************************************************************** 
 *  File Name   		: areasandpermimeter.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\areasandpermimeter.h
 *  Created on			: Dec 26, 2013 :: 11:50:13 PM
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

#ifndef AREASANDPERMIMETER_H_
#define AREASANDPERMIMETER_H_

double getAreaOfSquare(unsigned int side){
	return side * side;
}

double getPerimeterOfSquare(unsigned int side){
	return 4 * side;
}

double getAreaOfRectangle(unsigned int length,unsigned int breadth){
	return length * breadth;
}

double getPerimeterOfRectangle(unsigned int length,unsigned int breadth){
	return 2 * (length + breadth);
}
#endif /* AREASANDPERMIMETER_H_ */

/************************************************* End code *******************************************************/
