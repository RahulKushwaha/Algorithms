#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {
	int n; 
	cin >> n;

	int total = 0;
	for (; n; n = n ^ (n & -n), total++);

	cout << total << endl;

	return 0;
}