#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int* input = new int[m + 1];
	for (int i = 0; i <= m; i++) {
		cin >> input[i];
	}

	int fredArmy = input[m];
	int friends = 0;
	for (int i = 0; i < m; i++) {
		int armyDiff = input[i] ^ fredArmy;
		int difference = 0;
		for (; armyDiff; armyDiff = armyDiff ^ (armyDiff & -armyDiff), difference++);

		if (difference <= k) {
			friends++;
		}
	}

	cout << friends << endl;

	return 0;
}