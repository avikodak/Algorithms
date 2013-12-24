/***************************************************************************************************************** 
 *  File Name   		: DeleteNodeForGivenPtr.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Programming\src\sites\geeksforgeeks\linkedlist\page05\DeleteNodeForGivenPtr.h
 *  Created on			: Dec 17, 2013 :: 11:47:51 PM
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
#include <programming/utils/treeutils.h>

/************************************************ User defined constants *******************************************/
#define null NULL

/************************************************* Main code  ******************************************************/

#ifndef DELETENODEFORGIVENPTR_H_
#define DELETENODEFORGIVENPTR_H_

void deleteNodeForGivenPtr(llNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->next  == NULL){
		printf("Cannot delete node as this is a tail node");
		return;
	}
	llNode *tempNode = ptr->next;
	ptr->value = ptr->next->value;
	ptr->next = ptr->next->next;
	free(tempNode);
}

#endif /* DELETENODEFORGIVENPTR_H_ */
/************************************************* End code *******************************************************/
