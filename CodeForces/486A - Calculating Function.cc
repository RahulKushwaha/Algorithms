#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	long long n;
	cin >> n;

	if (n % 2) {
		cout << (-(n + 1) / 2) << endl;
	}
	else {
		cout << (n / 2) << endl;
	}

	return 0;
}