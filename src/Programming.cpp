//============================================================================
// Name        : Programming.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/******************User Includes*******************************/
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

#define null NULL
#define MM 1
#define CMS 1000 * MM
#define METER 100 * CMS
using namespace std;

bool sortFunc(pair<int,unsigned> it1,pair<int,unsigned int> it2){
	return it1.second > it2.second?true:false;
}

int main() {
	map<int,unsigned int> frequencyMap;
	map<int,unsigned int>::iterator itToFrequencyMap;
	frequencyMap[1] = 1;
	frequencyMap[3] = 4;
	frequencyMap[5] = 2;
	vector<pair<int,unsigned int> > pairs;
	pair<int,unsigned int> singlePair;
	copy(frequencyMap.begin(),frequencyMap.end(),back_inserter(pairs));
	sort(pairs.begin(),pairs.end(),sortFunc);
	frequencyMap.clear();

	for(unsigned int counter = 0;counter < pairs.size();counter++){
		singlePair = pairs[counter];
		printf("%d %d",singlePair.first,singlePair.second);
		frequencyMap.insert(pairs[counter]);
	}
	printf("\n");
	//sort(frequencyMap.begin(),frequencyMap.end(),sortFunc);


	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		printf("%d %d",itToFrequencyMap->first,itToFrequencyMap->second);
	}
}
