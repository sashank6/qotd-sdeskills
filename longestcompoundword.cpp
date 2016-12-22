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
#include<unordered_set>
#define INTPAIR pair<int,int>
#define LONGPAIR pair<long,long>
#define MOD 1000000007
#define INV -1
#define LONG long long
#define POINT pair<int,int>
using namespace std;

struct node {
	char c;
	bool isEnd;
	node *links[26];
	node(char a, bool x) :
			c(a), isEnd(x) {
		for (int i = 0; i < 26; i++)
			links[i] = 0;
	}

};

void dfs(node *r, string str) {
	if (r == 0)
		return;
	str += r->c;
	if (r->isEnd == true)
		cout << str << endl;
	for (int i = 0; i < 26; i++) {
		if (r->links[i] != 0)
			dfs(r->links[i], str);
	}
}

vector<string> findPrefixes(node *root, string str) {
	vector<string> prefixes;
	node *t = root;
	string tmp = "";
	for (int j = 0; j < str.length(); j++) {
		t = t->links[str[j] - 'a'];
		if (t == 0)
			break;
		tmp += t->c;
		if (t->isEnd)
			prefixes.push_back(tmp);
	}
	return prefixes;
}

node *buildTrie(vector<string> list) {
	node *root = new node(';', false);
	for (int i = 0; i < list.size(); i++) {
		string k = list[i];
		node *t = root;
		for (int j = 0; j < k.length(); j++) {
			int cvalue = k[j] - 'a';
			if (t->links[cvalue] == 0) {
				t->links[cvalue] = new node(k[j], false);
			}
			t = t->links[cvalue];
		}
		t->isEnd = true;
	}
	return root;
}

int main() {
	{ //Test1
		vector<string> list;
		list.push_back("cat");
		list.push_back("banana");
		list.push_back("dog");
		list.push_back("nana");
		list.push_back("walk");
		list.push_back("walkers");
		list.push_back("dogwalker");
		list.push_back("dogwalk");
		list.push_back("doge");
		list.push_back("dogecatwalkers");
//		list.push_back("cat");
//		list.push_back("cats");
//		list.push_back("catsdogcats");
//		list.push_back("catxdogcatsrat");
//		list.push_back("dog");
//		list.push_back("dogcatsdog");
//		list.push_back("hippopotamuses");
//		list.push_back("rat");
//		list.push_back("ratcat");
//		list.push_back("ratcatdog");
//		list.push_back("ratcatdogcat");
		node *root = buildTrie(list);
		string max_word = "";
		queue<pair<string, string> > q;
		for (int i = 0; i < list.size(); i++) {
			vector<string> prefixes = findPrefixes(root, list[i]);
			for (int j = 0; j < prefixes.size(); j++) {
				if (prefixes[j] != list[i]) {
					pair<string, string> tt = make_pair(list[i],
							list[i].substr(prefixes[j].length()));
					q.push(tt);
				}

			}
		}
		string maxword = "";
		while (!q.empty()) {
			pair<string, string> t = q.front();
			if (t.second.length() == 0) {
				if (maxword.length() < t.first.length())
					maxword = t.first;
			} else {
				vector<string> prefixes = findPrefixes(root, t.second);
				for (int j = 0; j < prefixes.size(); j++) {
					q.push(
							make_pair(t.first,
									t.second.substr(prefixes[j].length())));
				}
			}
			q.pop();
		}
		cout << maxword << endl;

	}

	return 0;
}

