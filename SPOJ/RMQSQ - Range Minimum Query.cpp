#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
	int n;
	vector<int> nums;

public:
	SegmentTree() {}

	SegmentTree(vector<int>& input) : n(input.size()) {
		if (n == 0) {
			return;
		}

		build(input);
	}

	void build(vector<int>& input) {
		n = input.size();
		nums.clear();
		nums.resize(n << 1);

		for (int i = n; i < n << 1; i++) {
			nums[i] = input[i - n];
		}

		for (int i = n - 1; i; i--) {
			nums[i] = min(nums[i << 1], nums[i << 1 | 1]);
		}
	}

	void modify(int index, int value) {
		nums[index + n] = value;
		index <<= 1;

		for (int i = index; i > 1; i >>= 1) {
			nums[i] = min(nums[i << 1], nums[i << 1 | 1]);
		}
	}

	int query(int left, int right) {
		left = left < 0 ? -left : left;
		int output = nums[left + n];
		for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
			if (left & 1) {
				output = min(nums[left++], output);
			}

			if (right & 1) {
				output = min(nums[--right], output);
			}
		}

		return output;
	}
};


int main() {
	int N, Q, left, right;
	cin >> N;
	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	SegmentTree segmentTree(input);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> left >> right;
		cout << segmentTree.query(left, right + 1) << endl;
	}

	return 0;
}