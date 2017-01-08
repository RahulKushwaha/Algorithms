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

#define SIZE 100001

using namespace std;
typedef long long ll;
int nums[SIZE] = { 0 }, primes[SIZE] = { 0 }, dp[SIZE] = { 0 }, primesList[SIZE];


int main() {
	// This causes the INPUT Stream to go out of SYNC with the OUTPUT Stream. As a result when you input something, the 
	// output buffer does not flush the stream. Basically none of the streams flush due to any operation on the other stream. 
	cin.tie(NULL);

	int limit = sqrt(SIZE), n, i, j;
	int primesCount = 0;

	for (i = 2; i <= limit; i++) {
		if (!nums[i]) {
			primesCount++;

			for (j = i; i * j < SIZE; j++) {
				nums[i * j] = 1;
			}
		}
	}

	for (i = 2, j = 0; i < SIZE; i++) {
		if (!nums[i]) {
			primes[j++] = i;
		}
	}

	for (i = 0; i < SIZE; i++) {
		primesList[i] = -1;
	}

	cin >> n;

	dp[1] = -1;
	for (i = 2; i <= n; i++) {
		int current = -1;
		int index = -1;
		for (j = 0; primes[j] <= i && j < primesCount; j++) {
			int prev = dp[i - primes[j]];
			if (current < prev + 1) {
				current = prev + 1;
				index = j;
			}
		}

		dp[i] = current;
		primesList[i] = index;
	}

	cout << dp[n] << '\n';
	while (true) {
		if (primesList[n] == -1) {
			break;
		}

		cout << primes[primesList[n]] << ' ';
		n -= primes[primesList[n]];
	}

	return 0;
}