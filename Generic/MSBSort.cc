#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

inline int charAt(string& str, int offset) {
    int length = str.size();
    if (offset >= length) {
        return -1;
    }

    return str[offset];
}

void msb_sort(vector<string>& input, int low, int high, int offset) {
    if (low >= high) {
        return;
    }

    vector<string> aux(high - low + 1);
    // 256 + 1
    // when the string is shorter than the offset, we assign a special negative value which also needs to be accomodated in the count array.
    int count[256 + 1] = { 0 };

    for (int i = low; i <= high; i++) {
        char ch = charAt(input[i], offset);
        count[ch + 1] ++;
    }

    for (int i = 1; i < 256 + 1; i++) {
        count[i] += count[i - 1];
    }

    for (int i = low; i <= high; i++) {
        char ch = charAt(input[i], offset);
        // 1 is added to every charater so that '-1' can also be accomodated.
        int index = --count[ch + 1];
        aux[index] = input[i];
    }

    for (int i = low; i <= high; i++) {
        input[i] = aux[i - low];
    }

    for (int i = 0; i < 256; i++) {
        if (count[i + 1] - count[i] <= 1) {
            continue;
        }

        msb_sort(input, low + count[i], low + count[i + 1] - 1, offset + 1);
    }
}
int main()
{
    vector<string> words = { "she", "his", "he", "hers", "hello", "a", "ax", "ac", "axc", "b" };

    msb_sort(words, 0, words.size() - 1, 0);

    for (string word : words) {
        cout << word.c_str() << " ";
    }

    cout << endl;
    return 0;
}

