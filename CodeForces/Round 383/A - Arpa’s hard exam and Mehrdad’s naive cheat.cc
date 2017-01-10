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
	int n;
	cin >> n;

	if (n == 0) {
		cout << "1" << endl;
		return 0;
	}

	int product = 1;
	unordered_set<int> digitsLookup;
	vector<int> digits;
	for (int i = 1; i <= n; i++) {
		product *= 1378;
		product %= 10;

		pair<unordered_set<int>::iterator, bool> ret = digitsLookup.insert(product);
		if (ret.second == false) {
			break;
		}

		digits.push_back(product);
	}

	int index = (n - 1) % (digits.size());

	cout << digits[index] << endl;

	return 0;
}