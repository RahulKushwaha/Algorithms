#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numberOfOffBits(unsigned long long n){
    int total = 0;
    while(n){
        if(!(n&1)){
            total++;
        }
        
        n = n >> 1;
    }
    
    return total;
}

int main() {
    /*We need to find the number of integers which are smaller than and satisfy this property.
      1. The numbers which statisfy this property are the ones which have the same bit pattern as n on all the places 
         where n has the bit set. 
      2. The only places where we can set the bit are the ones which have bit off as adding those bits will not lead to overflow.
      3. The total number of such numbers equal to the number of ways those "OFF Bits" can be combined(which is equal to the total number of combinations.)
    */
    unsigned long long n;
    cin>>n;
    
    int offBitsCount = numberOfOffBits(n);
    cout<<((unsigned long long)1 << offBitsCount)<<endl;
    
    return 0;
}
