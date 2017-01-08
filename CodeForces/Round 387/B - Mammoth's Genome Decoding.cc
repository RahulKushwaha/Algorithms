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
	int n;
	cin >> n;

	string input;
	cin >> input;

	int length = input.size(), unknowns = 0;
	unordered_map<char, int> lookup = { {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} };
	for (char& ch : input) {
		if (ch == '?') {
			unknowns++;
		}
		else {
			lookup[ch] ++;
		}
	}

	char maxCh;
	int maxCount = 0;
	for (auto p : lookup) {
		if (p.second >= maxCount) {
			maxCount = p.second;
			maxCh = p.first;
		}
	}

	int i = 0;
	for (auto p : lookup) {
		if (p.first == maxCh) {
			continue;
		}

		for (; i < length && p.second < maxCount; i++) {
			if (input[i] == '?') {
				input[i] = p.first;
				p.second++;
				unknowns--;
			}
		}

		if (i == length && p.second != maxCount) {
			cout << "===" << endl;
			return 0;
		}
	}

	if (unknowns % 4 == 0) {
		char ch[4] = { 'A', 'C', 'G', 'T' };
		for (int j = 0; i < length; i++) {
			if (input[i] == '?') {
				if (j == 4) {
					j = 0;
				}

				input[i] = ch[j++];
			}
		}

		cout << input << endl;
	}
	else {
		cout << "===" << endl;
	}

	return 0;
}