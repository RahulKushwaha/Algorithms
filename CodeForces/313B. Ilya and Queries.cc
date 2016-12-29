#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

struct bit {
};

int main() {
	string s;
	cin >> s;

	int length = s.size();
	int dp[100001] = { 0 };
	int count = 0;
	for (int i = 1; i < length; i++) {
		if (s[i] == s[i - 1]) {
			count++;
		}

		dp[i] = count;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		int output = dp[r - 1] - dp[l - 1];
		cout << output << endl;
	}

	return 0;
}