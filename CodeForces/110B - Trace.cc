#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>

#define SIZE 100000
const double PI = 3.14159265358979323846;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int input[SIZE];

int main()
{
	cin.tie(NULL);

	int n;
	cin >> n;

	input[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> input[i + 1];
	}

	sort(input, input + n + 1);

	long double totalArea = 0;
	for (int i = n; i > 0; i -= 2) {
		totalArea += (input[i] - input[i - 1]) * (input[i] + input[i - 1]);
	}

	long double answer = totalArea * PI;

	printf("%0.10Lf\n", answer);
	return 0;
}

