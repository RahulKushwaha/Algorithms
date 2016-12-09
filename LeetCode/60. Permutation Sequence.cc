class Solution {
public:
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    
    void reverse(int *input, int l, int h)
    {
        while(l < h)
        {
            swap(input[l], input[h]);
            l ++; 
            h --;
        }
    }
    
    int increasingSeq(int* input, int n)
    {
        int index = n - 1;
        for(int i = n - 1; i >= 0; i --)
        {
            if(input[i] < input[index])
            {
                break;
            }
            
            index = i;
        }
        
        return index;
    }
    
    string getPermutation(int n, int k) {
        string output;
        if(n == 0)
        {
            return output;
        }
        
        if(n == 1)
        {
            return "1";
        }
        
        int input[n];
        for(int i = 1; i <= n; i ++)
        {
            input[i - 1] = i;
        }
        
        for(int i = 0; i < k - 1; i ++)
        {
            int seqIndex = increasingSeq(input, n);
            
            if(seqIndex == 0)
            {
                break;
            }
            
            int pivotIndex = seqIndex - 1;
            int swapIndex = n - 1;
            
            for(int j = n - 1; j >= 0; j --)
            {
                if(input[pivotIndex] < input[swapIndex])
                {
                    break;
                }
                
                swapIndex = j;
            }
            
            swap(input[pivotIndex], input[swapIndex]);
            reverse(input, seqIndex, n - 1);
        }
        
        stringstream str;
        for(int i = 0; i < n; i ++)
        {
            str<<input[i];
        }
        
        return str.str();
    }
};