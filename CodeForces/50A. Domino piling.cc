
 #include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long n, m, a = 2;
	cin >> n >> m;

	long long rows = n / a;
	long long cols = m;
	long long tiles = rows * cols;
	if (n % a) {
		tiles += m / a;
	}

	cout << tiles << endl;

	return 0;
}