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
#include <set>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int levelChildren[500000] = { 0 };

void parse(string& input, stringstream* output, int& index, int level, int length, int& maxLevel) {
	while (true)
	{
		if (index >= length || level < 0) {
			break;
		}

		maxLevel = max(level + 1, maxLevel);
		stringstream& ss = output[level];
		for (; ; index++) {
			if (index < length && input[index] != ',') {
				ss << input[index];
			}
			else {
				ss << ' ';
				index++;
				int children = 0;
				for (; index < length && input[index] != ','; index++) {
					children *= 10;
					children += input[index] - '0';
				}

				levelChildren[level] = children;
				index++;
				break;
			}
		}

		levelChildren[level - 1]--;

		while (levelChildren[level] == 0) {
			level--;
		}

		if (levelChildren[level]) {
			level++;
		}

	}
}

int main()
{
	cin.tie(NULL);
	string input;
	cin >> input;

	stringstream* output = new stringstream[500000];
	int index = 0, level = 1, maxLevel = 0, length = input.size();
	parse(input, output, index, level, length, maxLevel);

	cout << maxLevel - 1 << '\n';
	for (int i = 1; i < maxLevel; i++) {
		cout << output[i].str() << '\n';
	}

	return 0;
}

