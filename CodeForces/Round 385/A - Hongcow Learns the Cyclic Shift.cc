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
	string input;
	cin >> input;

	int length = input.size();

	unordered_set<string> newStrings;
	for (int i = 0; i < length; i++) {
		newStrings.insert(input);

		char ch = input[length - 1];
		input.pop_back();

		input = ch + input;
	}

	cout << newStrings.size() << endl;

	return 0;
}

