#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int capacity = 0;
	int maxCapacity = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		capacity += b - a;
		maxCapacity = max(capacity, maxCapacity);
	}

	cout << maxCapacity << endl;

	return 0;
}