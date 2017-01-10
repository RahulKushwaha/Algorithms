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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main()
{
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;

	int target;
	unordered_map<int, vector<int>>::iterator itr;
	unordered_map<int, vector<int>> distinctNums;
	vector<int>::iterator up;

	int* nums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		distinctNums[nums[i]].push_back(i);
	}

	ll output = 0;
	for (int i = 0; i < n; i++) {
		target = x ^ nums[i];
		itr = distinctNums.find(target);

		if (itr != distinctNums.end()) {
			up = upper_bound(itr->second.begin(), itr->second.end(), i);
			output += (itr->second.size() - (up - itr->second.begin()));
		}
	}

	cout << output << endl;

	return 0;
}

