class Solution {
public:
    
    int findMedian(vector<int>& input, int k)
    {
        int length = input.size();
        
        int left = 0, right = length - 1;
        int partitionIndex = partition(input, left, right);
        while(partitionIndex != k)
        {
            if(partitionIndex < k)
            {
                left = partitionIndex + 1;
            }
            else
            {
                right = partitionIndex - 1;
            }
            
            partitionIndex = partition(input, left, right);
        }
        
        return partitionIndex;
    }
    
    int partition(vector<int>& input, int left, int right)
    {
        int pivot = input[right];
        int lastIndex = left - 1;
        int index = left;
        
        while(index < right)
        {
            if(input[index] < pivot)
            {
                lastIndex ++;
                swap(input[index], input[lastIndex]);
            }
            
            index ++;
        }
        
        lastIndex ++;
        swap(input[lastIndex], input[right]);
        
        return lastIndex;
    }
    
    void accumulateMedian(vector<int>& input, int partitionIndex, int right)
    {
        int pivot = input[partitionIndex];
        int j = partitionIndex - 1;
        int i = partitionIndex;
        while(i <= right)
        {
            if(input[i] == pivot)
            {
                j ++ ;
                swap(input[j], input[i]);
            }
            
            i ++;
        }
    }

    void wiggleSort(vector<int>& nums) {
        int length = nums.size();
        
        if(length < 2)
        {
            return;
        }
        
        int medianIndex = findMedian(nums, (length - 1) / 2);
        accumulateMedian(nums, medianIndex, length - 1);
        
        vector<int> output;
        output.resize(length);
        
        int i = length - 1; 
        int j = (length - 1) / 2;
        for(int k = 0; k < length; k ++)
        {
            if(k % 2 == 0)
            {
                output[k] = nums[j --];
            }
            else
            {
                output[k] = nums[i --];
            }
        }
        
        nums = output;
    }
};