#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		int length = input.size();
		stringstream ss;
		if (length > 10) {
			ss << input[0] << (length - 2) << input[length - 1];
			cout << ss.str() << endl;
		}
		else {
			cout << input << endl;
		}
	}

	return 0;
}