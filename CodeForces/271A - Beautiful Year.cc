#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool generateYear(int n, int baseYear, int& output, vector<bool>& visited) {
	if (n >= output || n > 10000) {
		return false;
	}

	if (n > baseYear) {
		output = min(output, n);
		return true;
	}


	for (int i = 0; i < 10; i++) {
		if (n == 0 && i == 0) {
			continue;
		}

		if (visited[i] == false)
		{
			visited[i] = true;
			if (generateYear(n * 10 + i, baseYear, output, visited)) {
				return true;
			}

			visited[i] = false;
		}
	}

	return false;
}

int main() {
	int year;
	cin >> year;

	int output = INT_MAX;
	vector<bool> visited(10, false);
	generateYear(0, year, output, visited);

	cout << output << endl;

	return 0;
}