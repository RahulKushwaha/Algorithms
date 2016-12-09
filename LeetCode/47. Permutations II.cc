class Solution {
public:
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void reverse(vector<int>& a, int l, int h)
{
    if(l > h)
    {
        return;
    }

    while(l < h)
    {
        swap(a[l], a[h]);
        l ++;
        h --;
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums)
{
    int size = nums.size();
    vector<vector<int> > output;
    if(size == 0)
    {
        return output;
    }

    output.push_back(nums);
    if(size == 1)
    {
        return output;
    }

    int increasingIndex = size - 2;

    while(increasingIndex != 0)
    {
        increasingIndex = size - 1;
        for(int i = size - 1; i >= 0; i --)
        {
            if(nums[i] >= nums [increasingIndex])
            {
                increasingIndex = i;
            }
            else
            {
                break;
            }
        }

        int pivot = increasingIndex - 1;
        int swapIndex = - 1;
        for(int i = increasingIndex; i < size; i ++)
        {
            if(nums[i] >= nums[pivot])
            {
                swapIndex = i;
            }
        }
        
        swap(nums[pivot], nums[swapIndex]);
        reverse(nums, increasingIndex, size - 1);
        output.push_back(nums);
    }

    return output;
}
};