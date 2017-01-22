#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <stack>
#include <list>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;

#define ceil_(x, y) ((x / y) + (x % y ? 1 : 0))

int main()
{
	cin.tie(NULL);
	int n;
	cin >> n;

	int maxOffDays = (n / 7) * 2;
	int remainder = n % 7;
	maxOffDays += remainder >= 2 ? 2 : remainder;

	int maxWorkingDays = (n / 7) * 5;
	maxWorkingDays += remainder >= 5 ? 5 : remainder;

	cout << (n - maxWorkingDays) << " " << maxOffDays;

	return 0;
}