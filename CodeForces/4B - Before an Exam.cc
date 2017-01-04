#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <list>
#include <unordered_map>

#define SIZE 500

using namespace std;

int main() {
	int d, sumTime;
	cin >> d >> sumTime;

	vector<int> days(d, 0);
	vector<int> maxTime(d);
	int totalExcessTime = 0;

	for (int i = 0; i < d; i++) {
		int dayMinTime, dayMaxTime;
		cin >> dayMinTime >> dayMaxTime;
		days[i] = dayMinTime;
		maxTime[i] = dayMaxTime;
		totalExcessTime += dayMaxTime - dayMinTime;
		sumTime -= dayMinTime;
	}

	if (sumTime < 0) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < d && sumTime >= 0 && totalExcessTime > 0; i++) {
		int diff = min(maxTime[i] - days[i], sumTime);
		totalExcessTime -= diff;
		days[i] += diff;
		sumTime -= diff;
	}

	if (sumTime <= 0) {
		cout << "YES" << endl;
		for (int i = 0; i < d; i++) {
			cout << days[i] << " ";
		}

		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}