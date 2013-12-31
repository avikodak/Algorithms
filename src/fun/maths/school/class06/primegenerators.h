/***************************************************************************************************************** 
 *  File Name   		: primegenerators.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class06\primegenerators.h
 *  Created on			: Dec 27, 2013 :: 1:36:34 AM
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
#ifndef PRIMEGENERATORS_H_
#define PRIMEGENERATORS_H_

vector<unsigned int> generatePrimeNumbersSieveOfErathones(unsigned int lowerLimit,unsigned int upperLimit){
	vector<bool> primeNumbers;
	unsigned int primeMultiple;
	for(unsigned int counter = 2;counter < upperLimit;counter++){
		if(primeNumbers[counter]){

		}
	}
}

bool isNumberPrimeNaive(unsigned int userInput){

}

bool isNumberPrime(unsigned int userInput){

}

vector<unsigned int> generatePrimeNumbersNaive(unsigned int lowerLimit,unsigned int upperLimit){

}

#endif /* PRIMEGENERATORS_H_ */
/************************************************* End code *******************************************************/
