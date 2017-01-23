#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <stack>
#include <list>
#include <set>
#include <unordered_map>
#include <functional>
#include <queue>
#define SIZE 100001

using namespace std;
typedef long long ll;

bool compare(pair<int, int>& x, pair<int, int>&y) {
	int diff1 = x.second - x.first + 1;
	int diff2 = y.second - y.first + 1;

	return diff1 < diff2;
}

int main() {
	// This causes the INPUT Stream to go out of SYNC with the OUTPUT Stream. As a result when you input something, the 
	// output buffer does not flush the stream. Basically none of the streams flush due to any operation on the other stream. 
	//cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;

	int ans = 0;
	for (;;) {
		a--;
		b -= 2;
		c -= 4;

		if (a >= 0 && b >= 0 && c >= 0) {
			ans += 7;
		}
		else {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}