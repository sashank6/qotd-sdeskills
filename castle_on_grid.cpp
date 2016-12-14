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
#define POINT pair<int,int>
using namespace std;

struct point {
	int x;
	int y;
	point(int a, int b) :
			x(a), y(b) {
	}
	;
};

int main() {

	int n;
	cin >> n;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	struct point ip(0, 0), gp(0, 0);
	cin >> ip.x;
	cin >> ip.y;
	cin >> gp.x;
	cin >> gp.y;

	vector<vector<int> > cost(n, vector<int>(n, INT_MAX));
	cost[ip.x][ip.y] = 0;
	queue<point> q;
	q.push(ip);

	while (!q.empty()) {
		struct point t = q.front();
		int pcost = cost[t.x][t.y];
		for (int x = t.x + 1; x < n; x++) {
			if (grid[x][t.y] == 'X')
				break;
			struct point p(x, t.y);
			if (cost[x][t.y] == INT_MAX) {
				cost[x][t.y] = min(cost[x][t.y], pcost + 1);
				q.push(p);
			}
		}
		for (int x = t.x - 1; x >= 0; x--) {
			if (grid[x][t.y] == 'X')
				break;
			struct point p(x, t.y);
			if (cost[x][t.y] == INT_MAX) {
				cost[x][t.y] = min(cost[x][t.y], pcost + 1);
				q.push(p);
			}
		}
		for (int y = t.y - 1; y >= 0; y--) {
			if (grid[t.x][y] == 'X')
				break;
			struct point p(t.x, y);
			if (cost[t.x][y] == INT_MAX) {
				cost[t.x][y] = min(cost[t.x][y], pcost + 1);
				q.push(p);
			}
		}
		for (int y = t.y + 1; y < n; y++) {
			if (grid[t.x][y] == 'X')
				break;
			struct point p(t.x, y);
			if (cost[t.x][y] == INT_MAX) {
				cost[t.x][y] = min(cost[t.x][y], pcost + 1);
				q.push(p);
			}
		}
		q.pop();

	}

	cout << cost[gp.x][gp.y] << endl;

	return 0;
}
