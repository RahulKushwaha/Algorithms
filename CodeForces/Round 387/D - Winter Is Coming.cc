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

/*
At first let's process the case when there is no solution — when the number of days with negative temperature cnt more than k. Now we need to subtract from k the number of days cnt.

If we will use winter rubber only in days with negative temperature we will get the maximum value of answer: it is the number of segments where all days have negative temperature multiply by 2.

Between the segments with negative temperatures there are segments which we ride on the summer rubber. Let's put in set the lengths of this segments (not include the segments with first and last days if thеy have non-negative temperatures, this cases we need to process separately from the main solution).

After that we need to delete from the set smallest lengths of segments one by one, decrease k on this value and decrease answer on 2. We can make it until k >  = 0 and the set is not empty.

Now we only need to check if we can ride on winter rubber the last segment of days with non-negative temperature. If it is possible we need decrease the answer on 1, in the other case the answer remains unchanged.
*/
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

	int n, k;
	cin >> n >> k;

	int temp;
	int last = -1, prev = 0, winterdays = 0, changes = 0, lastSpan;
	vector<pair<int, int>> spans;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < 0) {
			if (last != -1 && prev >= 0) {
				spans.push_back(make_pair(last + 1, i - 1));
			}

			last = i;

			winterdays++;

			if (prev >= 0) {
				changes++;
			}
		}
		else {
			if (prev < 0) {
				changes++;
			}
		}

		prev = temp;
	}

	if (k < winterdays) {
		cout << "-1\n";
		return 0;
	}

	if (last != -1 && prev >= 0) {
		lastSpan = n - last - 1;
	}

	sort(spans.begin(), spans.end(), compare);

	k -= winterdays;
	for (int i = 0; i < spans.size() && k > 0; i++) {
		pair<int, int>& span = spans[i];
		int diff = span.second - span.first + 1;
		if (diff <= k) {
			k -= diff;
			changes -= 2;
		}
		else {
			break;
		}
	}

	if (k > 0 && lastSpan != 0 && k >= lastSpan) {
		changes--;
	}

	cout << changes << endl;

	return 0;
}