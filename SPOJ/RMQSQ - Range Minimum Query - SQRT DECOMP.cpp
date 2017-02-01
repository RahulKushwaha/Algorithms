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
#include <map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <functional>
 
#define SIZE 100001
using namespace std;
typedef long long ll;
 
int input[SIZE];
 
class RMQ {
private:
	int blocks[SIZE];
	int size;
 
public:
	RMQ(int n) : size(ceil(sqrt(n))) {
 
		for (int i = 0; i <= size; i++) {
			int answer = 2147483647;
			int limit = i * size + size;
			for (int j = i * size; j < limit && j < n; j++) {
				answer = min(answer, input[j]);
			}
 
			blocks[i] = answer;
		}
	}
 
	int query(int l, int r) {
		int answer = input[l];
		int leftIndex = l / size, rightIndex = r / size;
 
		if (l != leftIndex * size) {
			int limit = leftIndex * size + size;
			for (int i = l; i < limit && i <= r; i++) {
				answer = min(answer, input[i]);
			}
 
			leftIndex++;
		}
 
		if (rightIndex * size + size - 1 != r) {
			for (int i = max(rightIndex * size, l); i <= r; i++) {
				answer = min(answer, input[i]);
			}
 
			rightIndex--;
		}
 
		for (int i = leftIndex; i <= rightIndex; i++) {
			answer = min(blocks[i], answer);
		}
 
		return answer;
	}
};
 
int main()
{
	cin.tie(NULL);
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
 
	RMQ rmq(n);
 
	int q, l, r;
	cin >> q;
 
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		cout << rmq.query(l, r) << '\n';
	}
 
	return 0;
} 