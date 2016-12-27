#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int increment = 0;
	int decrement = 0;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (input.compare("X++") == 0 || input.compare("++X") == 0) {
			increment++;
		}
		else {
			decrement++;
		}
	}

	cout << (increment - decrement) << endl;

	return 0;
}