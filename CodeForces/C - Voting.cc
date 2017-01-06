#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main()
{
	int n;
	cin >> n;

	string input;
	cin >> input;

	list<int> r, d;
	for (int i = 0; i < n; i++) {
		if (input[i] == 'R') {
			r.push_back(i);
		}
		else {
			d.push_back(i);
		}
	}

	while (!(r.size() == 0 || d.size() == 0)) {
		int rIndex = r.front(), dIndex = d.front();

		if (rIndex < dIndex) {
			d.pop_front();
			r.pop_front();
			r.push_back(rIndex + n);
		}
		else {
			d.pop_front();
			r.pop_front();
			d.push_back(dIndex + n);
		}
	}

	cout << (r.size() == 0 ? "D" : "R") << endl;

	return 0;
}

