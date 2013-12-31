/***************************************************************************************************************** 
 *  File Name   		: comparingNumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\fun\maths\school\class05\comparingNumbers.h
 *  Created on			: Dec 26, 2013 :: 11:02:59 PM
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
#ifndef COMPARINGNUMBERS_H_
#define COMPARINGNUMBERS_H_

bool getFirstGreaterThanSecond(unsigned int firstNumber,unsigned int secondNumber){
	return firstNumber - secondNumber > 0?true:false;
}

bool getFirstGreaterThanSecondNaive(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 && secondNumber == 0){
		return false;
	}
	if(firstNumber == 0 || secondNumber == 0){
		return firstNumber != 0?true:false;
	}
	stack<unsigned int> digitsFirstNumber,digitsSecondNumber;
	unsigned int copyOfFirstNumber = firstNumber,copyOfSecondNumber = secondNumber,remainder;
	while(copyOfFirstNumber > 0){
		remainder = copyOfFirstNumber % 10;
		digitsFirstNumber.push(remainder);
		copyOfFirstNumber /= 10;
	}
	while(copyOfSecondNumber > 0){
		remainder = copyOfSecondNumber %10;
		digitsSecondNumber.push(remainder);
		copyOfSecondNumber /= 10;
	}
	while(digitsFirstNumber.top() == 0){
		digitsFirstNumber.pop();
	}
	while(digitsSecondNumber.top() == 0){
		digitsSecondNumber.pop();
	}
	if(digitsFirstNumber.size() != digitsSecondNumber.size()){
		return digitsFirstNumber.size() > digitsSecondNumber.size()?true:false;
	}else{
		while(!digitsFirstNumber.empty()){ // since two stacks sizes are same no need to add second stack empty constraint
			if(digitsFirstNumber.top() != digitsSecondNumber.top()){
				return digitsFirstNumber.top() > digitsSecondNumber.top()?true:false;
			}
			digitsFirstNumber.pop();
			digitsSecondNumber.pop();
		}
	}
	return false;
}
#endif /* COMPARINGNUMBERS_H_ */
/************************************************* End code *******************************************************/
