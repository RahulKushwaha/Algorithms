#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct SuffixArray {
    string str;
    vector<int> ranks;
    int length;

    SuffixArray(string& input) : length(input.size()), str(input) {
        for (int i = 0; i < length + 1; i++) {
            ranks.push_back(i - 1);
        }
    }

    void build() {
        vector<int> aux(length + 1);
        msbSort(&ranks[0], &aux[0], 0, length, 0);
    }

    int distinctSubstr(long index) {
        if (length == 0) {
            return 0;
        }

        build();

        int total = 0;
        string last = "";
        for (int i = 1; i < length + 1; i++) {
            string current = str.substr(ranks[i]);
            int minLength = min(last.size(), current.size());

            for (int j = 0; j <= minLength; j++) {
                if (j == current.size()) {
                    break;
                }

                if (last[j] != current[j]) {
                    for (int k = j; k < current.size(); k++)
                    {
                        if (index <= k) {
                            return current[index];
                        }

                        index -= k + 1;
                    }

                    break;
                }
            }
            
            last = current;
        }

        return total;
    }

    void msbSort(int* ranks, int* aux, int low, int high, int offset) {
        if (low >= high) {
            return;
        }

        // 256 + 1
        // when the string is shorter than the offset, we assign a special negative value which also needs to be accomodated in the count array.
        int count[256 + 1] = { 0 };

        for (int i = low; i <= high; i++) {
            int ch = ranks[i] == -1 | ranks[i] + offset >= length ? -1 : str[ranks[i] + offset];
            count[ch + 1] ++;
        }

        for (int i = 1; i < 256 + 1; i++) {
            count[i] += count[i - 1];
        }

        for (int i = low; i <= high; i++) {
            int ch = ranks[i] == -1 | ranks[i] + offset >= length ? -1 : str[ranks[i] + offset];
            // 1 is added to every charater so that '-1' can also be accomodated.
            int index = --count[ch + 1];
            aux[index] = ranks[i];
        }

        for (int i = low; i <= high; i++) {
            ranks[i] = aux[i - low];
        }

        for (int i = 0; i < 256; i++) {
            if (count[i + 1] - count[i] <= 1) {
                continue;
            }

            msbSort(ranks, aux, low + count[i], low + count[i + 1] - 1, offset + 1);
        }
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string input;
        long index;
        cin >> input >> index;

        SuffixArray sa(input);
        cout << sa.distinctSubstr(index - 1) << endl;
    }

    return 0;
}