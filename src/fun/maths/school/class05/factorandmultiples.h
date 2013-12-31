/***************************************************************************************************************** 
 *  File Name   		: factorandmultiples.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\factorandmultiples.h
 *  Created on			: Dec 26, 2013 :: 11:39:30 PM
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
#ifndef FACTORANDMULTIPLES_H_
#define FACTORANDMULTIPLES_H_

bool isFactorGivenNumber(unsigned int factor,unsigned int userInput){
	return userInput % factor == 0?true:false;
}

bool isMultipleOfGivenNumber(unsigned int multiple,unsigned int userInput){
	return multiple % userInput == 0?true:false;
}

vector<unsigned int> facorsOfGivenNumber(unsigned int userInput){
	vector<unsigned int> factors;
	if(userInput == 0){
		factors.push_back(0);
		return factors;
	}
	factors.push_back(1);
	for(unsigned int counter = 2;counter <= userInput/2;counter++){
		if(userInput%counter == 0){
			factors.push_back(counter);
		}
	}
	return factors;
}

void printMultiples(unsigned int startNumber,unsigned int userInput,unsigned int noOfMultiples){
	unsigned multipleCounter = startNumber + (userInput - (startNumber % userInput));
	for(unsigned int counter = 0;counter < noOfMultiples;counter++){
		printf("%d\t",multipleCounter);
		multipleCounter += userInput;
	}
	return;
}

void printMultiplesNaive(unsigned int startNumber,unsigned int userInput,unsigned int noOfMultiples){
	unsigned int numberCounter = userInput;
	for(unsigned int counter = 0;counter < noOfMultiples;counter++){
		while(numberCounter % userInput != 0){
			numberCounter++;
		}
		printf("%d\t",numberCounter);
		numberCounter++;
	}
}
#endif /* FACTORANDMULTIPLES_H_ */
/************************************************* End code *******************************************************/
