#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> input(n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		total += input[i];
	}

	sort(input.begin(), input.end());

	int counter = 0;
	int subsetSum = 0;
	for (vector<int>::reverse_iterator itr = input.rbegin(); itr != input.rend(); itr++) {
		subsetSum += *itr;
		total -= *itr;
		counter++;

		if (subsetSum > total) {
			break;
		}
	}

	cout << counter << endl;;

	return 0;
}