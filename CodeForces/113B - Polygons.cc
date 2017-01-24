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
#include <queue>
#include <functional>

#define SIZE 100001
using namespace std;
typedef long long ll;

pair<ll, ll> inputA[SIZE];
pair<ll, ll> inputB[SIZE / 2];

ll inline orientation(pair<ll, ll>& a, pair<ll, ll>& b, pair<ll, ll>& c) {
	return (c.second - b.second) * (b.first - a.first) - (b.second - a.second) * (c.first - b.first);
}

int binsearch(pair<ll, ll>& point, int h) {
	int l = 0;
	int result = -1;
	while (l <= h) {
		int mid = ((h - l) / 2) + l;

		if (orientation(inputA[0], inputA[mid + 1], point) <= 0) {
			result = mid;

			if (l == h) {
				break;
			}

			l = mid + 1;
		}
		else {
			h = mid - 1;
		}
	}

	return result;
}

int main()
{
	//cin.tie(NULL);
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inputA[i].first >> inputA[i].second;
	}

	inputA[n] = inputA[0];

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> inputB[i].first >> inputB[i].second;
	}

	ll o1, o2, o3;
	int triangleIndex;
	pair<ll, ll> a = inputA[0], b, c, d;

	bool flag = true;
	for (int j = 0; j < m; j++) {
		d = inputB[j];
		triangleIndex = binsearch(d, n - 1);
		if (triangleIndex < 0 || triangleIndex >= n - 1) {
			flag = false;
			break;
		}

		b = inputA[triangleIndex + 1];
		c = inputA[triangleIndex + 2];
		o1 = orientation(a, b, d);
		o2 = orientation(b, c, d);
		o3 = orientation(c, a, d);
		if ((triangleIndex == 0 && (o1 >= 0 || o2 >= 0)) || (triangleIndex == n - 2 && (o2 >= 0 || o3 >= 0)) || (o2 >= 0)) {
			flag = false;
			break;
		}
	}


	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}