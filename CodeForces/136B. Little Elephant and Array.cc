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

#define SIZE 100000
using namespace std;
typedef long long ll;


int input[SIZE];
int output[SIZE];
pair<pair<int, int>, int> queries[SIZE];
int blockSize;

#define ceil_(x, y) ((x / y) + (x % y ? 1 : 0))

bool mo_compare(pair<pair<int, int>, int>& x, pair<pair<int, int>, int>& y) {
	int firstBlockIndex = x.first.first / blockSize;
	int secondBlockIndex = y.first.first / blockSize;

	if (firstBlockIndex == secondBlockIndex) {
		return x.first.second < y.first.second;
	}

	return firstBlockIndex < secondBlockIndex;
}

void inline removeElement(unordered_map<int, int>& lookup, int val, int& result) {
	unordered_map<int, int>::iterator itr = lookup.find(val);
	if (itr != lookup.end()) {
		if (itr->first == itr->second) {
			result--;
		}

		itr->second--;

		if (itr->first == itr->second) {
			result++;
		}
	}
	else {
		lookup[val]--;
	}
}

void inline addElement(unordered_map<int, int>& lookup, int val, int& result) {
	unordered_map<int, int>::iterator itr = lookup.find(val);
	if (itr != lookup.end()) {
		if (itr->first == itr->second) {
			result--;
		}

		itr->second++;

		if (itr->first == itr->second) {
			result++;
		}
	}
	else {
		lookup[val]++;
		if (val == 1) {
			result++;
		}
	}
}

int main()
{
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	blockSize = static_cast<int>(sqrt(n));

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < m; i++) {
		pair<pair<int, int>, int>& query = queries[i];
		cin >> query.first.first >> query.first.second;
		query.first.first--;
		query.first.second--;
		query.second = i;
	}

	sort(queries, queries + m, mo_compare);

	unordered_map<int, int> lookup;
	int result = 0;
	int prev_l = 0, prev_r = -1, left, right, index;
	unordered_map<int, int>::iterator itr;

	for (int i = 0; i < m; i++) {
		left = queries[i].first.first;
		right = queries[i].first.second;
		index = queries[i].second;

		while (left > prev_l) {
			removeElement(lookup, input[prev_l], result);
			prev_l++;
		}

		while (left < prev_l) {
			prev_l--;
			addElement(lookup, input[prev_l], result);
		}

		while (right < prev_r) {
			removeElement(lookup, input[prev_r], result);
			prev_r--;
		}

		while (right > prev_r) {
			prev_r++;
			addElement(lookup, input[prev_r], result);
		}

		output[index] = result;
	}

	for (int i = 0; i < m; i++) {
		cout << output[i] << '\n';
	}

	return 0;
}