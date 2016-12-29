#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	int last = input[0];
	int maxLength = 1;
	int currentLength = 1;
	for (int i = 1; i < n; i++) {
		if (input[i] >= last) {
			currentLength++;
			maxLength = max(currentLength, maxLength);
		}
		else {
			currentLength = 1;
		}

		last = input[i];
	}

	cout << maxLength << endl;

	return 0;
}