#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool divide(int n, int divisor) {
	int mod = n % divisor;
	if (mod == 0) {
		return true;
	}

	if (divisor > n) {
		return false;
	}

	divisor *= 10;
	return divide(n, divisor + 4) | divide(n, divisor + 7);
}

int main() {
	int n;
	cin >> n;
	bool output = divide(n, 4) | divide(n, 7);
	cout << (output ? "YES" : "NO") << endl;;

	return 0;
}