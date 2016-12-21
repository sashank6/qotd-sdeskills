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

int count(node *root, string &str) {
	if (root == 0)
		return 0;
	int ct = 0;
	string mstr = "";
	for (int i = 0; i < 26; i++) {
		string s = "";
		int value = 1 + count(root->links[i], s);
		if (value > ct) {
			ct = value;
			mstr = s;
		}
	}
	str = root->c + mstr;
	return ct;
}

string max_suffix(node *root, string str) {
	node *t = root;
	for (int k = 0; k < str.length(); k++)
		t = t->links[str[k] - 'a'];
	string suffix = "";
	count(t, suffix);
	suffix = suffix.substr(1);
	//cout<<"String: "<<str<<", "<<"Suffix: "<<suffix<<"Suffix length: "<<suffix.length()<<endl;
	if (suffix.length() > 0)
		return str + suffix;
	return "";
}

string findLongestPrefix(node *root, string str) {
	node *t = root;
	string prefix = "";
	string tmp = "";
	for (int j = 0; j < str.length() - 1; j++) {
		t = t->links[str[j] - 'a'];
		tmp += t->c;
		if (t->isEnd)
			prefix = tmp;
	}
	return prefix;
}
string findLongestSuffix(node *root, string str) {
	node *t = root;
	string suffix = "";
	string tmp = "";
	for (int j = 0; j < str.length(); j++) {
		t = t->links[str[j] - 'a'];
		if (t == 0)
			break;
		tmp += t->c;
		if (t->isEnd)
			suffix = tmp;
	}
	return suffix;
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
		list.push_back("walker");
		list.push_back("dogwalker");
		node *root = buildTrie(list);
		string max_word = "";
		for (int i = 0; i < list.size(); i++) {
			string prefix = findLongestPrefix(root, list[i]);
			string suffix = "";
			if (prefix.length() > 0)
				suffix = findLongestSuffix(root,
						list[i].substr(prefix.length()));
			if (prefix + suffix == list[i]) {
				if (max_word.length() < list[i].length())
					max_word = list[i];

			}
		}
		cout << max_word << endl;

	}

	{ //Test2 ‘cat’, ‘cats’, ‘catsdogcats’, ‘catxdogcatsrat’, ‘dog’, ‘dogcatsdog’, ‘hippopotamuses’, ‘rat’, ‘ratcat’, ‘ratcatdog’, ‘ratcatdogcat’
		vector<string> list;
		list.push_back("cat");
		list.push_back("cats");
		list.push_back("catsdogcats");
		list.push_back("catxdogcatsrat");
		list.push_back("dog");
		list.push_back("dogcatsdog");
		list.push_back("hippopotamuses");
		list.push_back("rat");
		list.push_back("ratcat");
		list.push_back("ratcatdog");
		list.push_back("ratcatdogcat");
		node *root = buildTrie(list);
		string max_word = "";
		for (int i = 0; i < list.size(); i++) {
			string prefix = findLongestPrefix(root, list[i]);
			string suffix = "";
			if (prefix.length() > 0)
				suffix = findLongestSuffix(root,
						list[i].substr(prefix.length()));
			if (prefix + suffix == list[i]) {
				if (max_word.length() < list[i].length())
					max_word = list[i];

			}
		}
		cout << max_word << endl;
	}
	return 0;
}

