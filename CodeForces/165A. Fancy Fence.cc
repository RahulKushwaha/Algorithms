#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main()
{
	cin.tie(NULL);
	int n, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;

		if (360 % (180 - a) == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}

