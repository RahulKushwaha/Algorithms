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

#define SIZE 100001
using namespace std;
typedef long long ll;

pair<long long, long long> input[SIZE];

long long inline orientation(pair<long long, long long>& a, pair<long long, long long>& b, pair<long long, long long>& c) {
	return (c.second - b.second) * (b.first - a.first) - (b.second - a.second) * (c.first - b.first);
}

int main()
{
	//cin.tie(NULL);
	long long n;
	pair<long long, long long> a, b, c, d;
	long long counter = 2, i, o1, o2, o3, o;
	long long output[3];
	output[0] = 0;
	output[1] = 1;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> input[i].first >> input[i].second;
	}

	a = input[0], b = input[1];
	int thirdIndex = -1;

	for (i = 2; i < n && counter < 3; i++) {
		c = input[i];
		o = orientation(a, b, c);
		if (o != 0) {
			output[2] = i;
			thirdIndex = i;

			if (o < 0) {
				swap(b, c);
				output[2] = output[1];
				output[1] = i;
			}

			counter++;
		}
	}

	for (i = 2; i < n; i++) {
		if (i == thirdIndex) {
			continue;
		}

		d = input[i];
		o1 = orientation(a, b, d);
		o2 = orientation(b, c, d);
		o3 = orientation(c, a, d);

		if (o1 >= 0 & o2 >= 0 && o3 >= 0) {
			if (o1 != 0) {
				c = d;
				output[2] = i;
			}
			else if (o2 != 0) {
				a = d;
				output[0] = i;
			}
			else if (o3 != 0) {
				b = d;
				output[1] = i;
			}
		}
	}

	for (long long j = 0; j < 3; j++) {
		cout << output[j] + 1 << ' ';
	}

	return 0;
}