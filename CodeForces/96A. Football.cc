#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;
	
	input = input + "$";
	int length = input.size();
	int maxConsecutive = 0, current = 1;
	char lastCh = input[0];

	for (int i = 1; i < length; i++) {
		char ch = input[i];
		if (ch != lastCh) {
			maxConsecutive = max(current, maxConsecutive);
			current = 1;
		}
		else {
			current++;
		}

		lastCh = ch;
	}

	cout << (maxConsecutive >= 7 ? "YES" : "NO") << endl;
	return 0;
}