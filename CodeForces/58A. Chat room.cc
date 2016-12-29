#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;

	string word("hello");

	int length = input.size(), i = 0, j = 0;
	for (; i < length; i++) {
		if (input[i] == word[j]) {
			j++;
		}
	}

	cout << (j == 5 ? "YES" : "NO") << endl;

	return 0;
}