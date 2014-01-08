/***************************************************************************************************************** 
 *  File Name   		: TripletForGivenSum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\arrays\page04\TripletForGivenSum.h
 *  Created on			: Jan 8, 2014 :: 1:14:04 PM
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

#ifndef TRIPLETFORGIVENSUM_H_
#define TRIPLETFORGIVENSUM_H_

bool findTripletForGivenSumON3(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return false;
	}
	unsigned int firstCounter,secondCounter,thirdCounter;
	for(firstCounter = 0;firstCounter < userInput.size()-2;firstCounter++){
		for(secondCounter = firstCounter+1;secondCounter < userInput.size()-1;secondCounter++){
			for(thirdCounter = secondCounter+1;thirdCounter < userInput.size();thirdCounter++){
				if(userInput[firstCounter] + userInput[secondCounter] + userInput[thirdCounter] == sum){
					return true;
				}
			}
		}
	}
	return false;
}

bool findTripletForGivenSum(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler,backCrawler;
	int sum = 0;
	for(unsigned int crawler = 0;crawler < userInput.size()-2;crawler++){
		frontCrawler = crawler + 1;
		backCrawler = userInput.size()-1;
		sum = userInput[crawler];
		while(frontCrawler < backCrawler){
			sum = userInput[frontCrawler]  + userInput[backCrawler];
			if(sum == key){
				return true;
			}
			if(sum > key){
				backCrawler--;
			}else{
				frontCrawler++;
			}
		}
	}
}

#endif /* TRIPLETFORGIVENSUM_H_ */

/************************************************* End code *******************************************************/
