/***************************************************************************************************************** 
 *  File Name   		: DiameterOfTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\trees\page06\DiameterOfTree.h
 *  Created on			: Dec 23, 2013 :: 11:59:52 AM
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

#ifndef DIAMETEROFTREE_H_
#define DIAMETEROFTREE_H_

unsigned int diameterOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	unsigned int leftHeight = heightOfTree(ptr->left);
	unsigned int rightHeight = heightOfTree(ptr->right);
	return max(leftHeight+rightHeight + 1,max(diameterOfTree(ptr->left),diameterOfTree(ptr->right)));
}

#endif /* DIAMETEROFTREE_H_ */

/************************************************* End code *******************************************************/
