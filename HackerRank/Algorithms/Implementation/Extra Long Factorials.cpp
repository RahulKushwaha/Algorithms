#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string multiply(string num1, int num) {
        int length1 = num1.size();
        int length = 200000;
        int output[length] = {0};
        
        int counter = 0;
        for(int i = length1 - 1, k = length - 1; i >= 0; i --)
        {
            output[k --] += (num1[i] - '0') * (num);
        }

        int carry = 0;
        for(int l = length - 1; l >= 0; l --)
        {
            output[l] += carry;
            carry = output[l] / 10;
            output[l] %= 10;
        }
        
        stringstream str;
        int i = 0;
        for(; i < length; i++ )
        {
            if(output[i] != 0)
            {
                break;
            }
        }
        
        for(; i < length; i ++)
        {
            str<<output[i];
        }
        
        return str.str();
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    string output("1");
    for(int i = 1; i <= n; i ++){
        output = sol.multiply(output, i);
    }
    
    cout<<output;
    
    return 0;
}
