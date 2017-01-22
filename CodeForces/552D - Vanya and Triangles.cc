#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <stack>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
#include <functional>

#define SIZE 100000
using namespace std;
typedef long long ll;

pair<int, int> input[SIZE];
map<pair<int, int>, int> lookup;

#define ceil_(x, y) ((x / y) + (x % y ? 1 : 0))
#define lineA(y2, y1) y2 - y1
#define lineB(x2, x1) x1 - x2
#define lineC(x1, x2, y1, y2) lineA(y2, y1) * x1 + lineB(x2, x1) * y1

int inline orientation(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
	return -(c.second - b.second) * (b.first - a.first) + (b.second - a.second) * (c.first - b.first);
}

int main()
{
	//cin.tie(NULL);
	int n, x, y, x1, x2, y1, y2;
	pair<int, int> a, b, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i].first >> input[i].second;
	}

	ll output = 0;
	for (int i = 0; i < n; i++) {
		a = input[i];

		for (int j = i + 1; j < n; j++) {
			b = input[j];

			for (int k = j + 1; k < n; k++) {
				c = input[k];

				if (orientation(a, b, c) != 0) {
					output++;
				}
			}
		}
	}

	cout << output << endl;

	return 0;
}