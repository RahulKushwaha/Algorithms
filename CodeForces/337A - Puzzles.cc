#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int * input = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> input[i];
	}

	sort(input, input + m);

	int output = INT_MAX;
	for (int i = 0; i <= m - n; i++) {
		output = min(input[i + n - 1] - input[i], output);
	}

	cout << output << endl;

	return 0;
}