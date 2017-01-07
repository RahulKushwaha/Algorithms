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

int main()
{
	cin.tie(NULL);
	int n;
	cin >> n;

	int limit = sqrt(n);
	int diff = INT_MAX;
	int a, b;

	for (int i = 1; i <= limit; i++) {
		if (n % i == 0) {
			if (n - i < diff) {
				diff = n - i;
				a = i;
				b = n / i;
			}
		}
	}

	cout << a << " " << b << endl;

	return 0;
}

