#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string input;
	cin >> input;

	int length = input.size();
	stringstream ss;

	for (int i = 0; i < length; i++)
	{
		char ch = tolower(input[i]);
		switch (ch)
		{
		case 'a':
		case'e':
		case'i':
		case 'o':
		case 'u':
		case 'y':
			break;

		default:
			ss << "." << ch;
			break;
		}
	}

	cout << ss.str() << endl;

	return 0;
}