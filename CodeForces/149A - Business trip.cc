#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int k;
	cin >> k;

	if (k == 0)
	{
		cout << "0" << endl;
		return 0;
	}

	int *input = new int[12];
	for (int i = 0; i < 12; i++) {
		cin >> input[i];
	}

	sort(input, input + 12);
	int output = 0;
	for (int i = 11; i >= 0 && k > 0; k -= input[i], i--, output++);

	cout << (k <= 0 ? output : -1) << endl;

	return 0;
}