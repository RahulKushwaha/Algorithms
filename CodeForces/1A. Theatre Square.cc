#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long n, m, a;
	cin >> n >> m >> a;

	long long rows = n / a + (n % a ? 1 : 0);
	long long cols = m / a + (m % a ? 1 : 0);

	cout << rows * cols << endl;

	return 0;
}