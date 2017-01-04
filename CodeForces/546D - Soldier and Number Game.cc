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

#define SIZE 5000001

using namespace std;
typedef long long ll;
//dp = number of prime factors of a number. Not DISTINCT but all of them => 20 = COUNT(2 X 2 X 5)
//pd = random prime divisor of a number.
int dp[SIZE] = { 0 }, pd[SIZE] = { 0 };

int inline sieve(int n) {
	if (n == 0 || n == 1) {
		return 0;
	}

	if (dp[n]) {
		return dp[n];
	}

	dp[n] = sieve(n / pd[n]) + 1;
	return dp[n];
}

int main() {
	// This causes the INPUT Stream to go out of SYNC with the OUTPUT Stream. As a result when you input something, the 
	// output buffer does not flush the stream. Basically none of the streams flush due to any operation on the other stream. 
	cin.tie(NULL); 

	int limit = sqrt(SIZE), j, t, a, b, i;

	for (i = 2; i <= limit; i++) {
		if (!pd[i]) {
			for (j = i; i * j < SIZE; j++) {
				pd[i * j] = i;
			}
		}
	}

	for (i = 2; i < SIZE; i++) {
		if (!pd[i]) {
			pd[i] = i;
		}
	}

	for (i = 2; i < SIZE; i++) {
		if (dp[i] == 0) {
			sieve(i);
		}
	}

	for (i = 1; i < SIZE; i++) {
		dp[i] += dp[i - 1];
	}

	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> a >> b;
		cout << (dp[a] - dp[b]) << '\n';
	}

	return 0;
}