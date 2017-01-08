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

#define SIZE 100001

using namespace std;
typedef long long ll;


int main() {
	// This causes the INPUT Stream to go out of SYNC with the OUTPUT Stream. As a result when you input something, the 
	// output buffer does not flush the stream. Basically none of the streams flush due to any operation on the other stream. 
	cin.tie(NULL);

	int a1, a2, b1, b2, c1, c2, x, y;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

	cout << "3" << '\n';

	// This problem can be solved by taking each point in turn as the origin of the tail of the vector.
	// Then the 4 point can be found by using A = B + C (Vector Addition)

	x = (b1 - a1) + (c1);
	y = (b2 - a2) + (c2);

	cout << x << ' ' << y << '\n';

	x = (a1 - b1) + (c1);
	y = (a2 - b2) + (c2);

	cout << x << ' ' << y << '\n';

	x = (b1 - c1) + (a1);
	y = (b2 - c2) + (a2);

	cout << x << ' ' << y << '\n';

	return 0;
}