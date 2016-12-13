//#include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define INTPAIR pair<int,int>
#define LONGPAIR pair<long,long>
#define MOD 1000000007
#define INV -1
#define LONG long long
using namespace std;

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}

};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*

Time Complexity is O(K*M) where m is the length of longest list.
Space complexity is O(1)
*/


class Solution {
public:
	ListNode *merge(ListNode* l1, ListNode* l2) {
		if (l1 == 0 || l2 == 0)
			return (l1 == 0) ? l2 : l1;
		if (l1->val <= l2->val) {
			l1->next = merge(l1->next, l2);
			return l1;
		} else {
			l2->next = merge(l1, l2->next);
			return l2;
		}
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		int N = lists.size();
		if (N == 0)
			return 0;
		while(N>1){
			for(int i=0;i<N/2;i++)
				lists[i] = merge(lists[i],lists[N-i-1]);
			N=(N+1)/2;
		}
		return lists[0];
	}
};
