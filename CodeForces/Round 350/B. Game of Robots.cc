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

using namespace std;
typedef long long ll;

#define ceil_(x, y) ((x / y) + (x % y ? 1 : 0))

int main()
{
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	vector<int> ids(n);
	for (int i = 0; i < n; i++) {
		cin >> ids[i];
	}

	ll sum = 0, current = 0, prev = 0;
	for (int i = 1; i <= n; i++) {
		if (current + i >= k) {
			cout << ids[k - current - 1] << endl;
			return 0;
		}

		current += i;
	}

	return 0;
}