/***************************************************************************************************************** 
 *  File Name   		: lengthConversions.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\lengthConversions.h
 *  Created on			: Dec 26, 2013 :: 11:21:26 PM
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
#define MM 1
#define CMS 1000 * MM
#define METER 100 * CMS
#define KMS 1000 * METER

/************************************************* Main code  ******************************************************/
#ifndef LENGTHCONVERSIONS_H_
#define LENGTHCONVERSIONS_H_

long long int convertIntoMM(unsigned int kilometer,unsigned int meters,unsigned int cms,unsigned int mm){
	long long int resultInMM;
	resultInMM += kilometer * KMS;
	resultInMM += meters * METER;
	resultInMM += cms * CMS;
	resultInMM += mm;
	return resultInMM;
}

hash_map<string,unsigned int> simplifyLength(long long int givenMM){
	unsigned int noKms,noMeter,noCentimeters,noMM;
	noKms = givenMM / KMS;
	givenMM -= givenMM - noKms * KMS;
	noMeter = givenMM / METER;
	givenMM -= givenMM - noMeter * METER;
	noCentimeters = givenMM / CMS;
	givenMM -= givenMM - noCentimeters * CMS;
	noMM = givenMM;
	hash_map<string,unsigned int> respectiveUnits;
	respectiveUnits.insert(pair<string,unsigned int>("kilometers",noKms));
	respectiveUnits.insert(pair<string,unsigned int>("meters",noMeter));
	respectiveUnits.insert(pair<string,unsigned int>("centimeters",noCentimeters));
	respectiveUnits.insert(pair<string,unsigned int>("millimeters",noMM));
	return respectiveUnits;
}

#endif /* LENGTHCONVERSIONS_H_ */
/************************************************* End code *******************************************************/
