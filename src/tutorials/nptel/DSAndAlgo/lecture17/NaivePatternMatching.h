/***************************************************************************************************************** 
 *  File Name   		: NaivePatternMatching.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\tutorials\nptel\DSAndAlgo\lecture17\NaivePatternMatching.h
 *  Created on			: Jan 15, 2014 :: 1:44:56 AM
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

#ifndef NAIVEPATTERNMATCHING_H_
#define NAIVEPATTERNMATCHING_H_

vector<unsigned int> searchForPattern(char *text,char *pattern){
	vector<unsigned int> indexes;
	char *textCrawler = text,*patternCrawler = pattern,*innerTextCrawler;
	while(textCrawler != NULL){
		patternCrawler = pattern;
		innerTextCrawler = textCrawler;
		while(innerTextCrawler != NULL && patternCrawler != NULL){
			innerTextCrawler++;
			patternCrawler++;
		}
		if(innerTextCrawler == patternCrawler){

		}
		textCrawler++;
	}
}


#endif /* NAIVEPATTERNMATCHING_H_ */

/************************************************* End code *******************************************************/
