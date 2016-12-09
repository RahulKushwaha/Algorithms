class Solution {
public:
    int trap(vector<int>& height) {
    if(height.size() <= 2)
    {
        return 0;
    }

    int left = 0;
    int right = height.size() - 1;
    int total = 0;
    int i = left;
    int j = right;
    while(i <= j)
    {
        // Get the maximum seen so far from the LHS.
        if(height[left] < height[i])
        {
            left = i;
        }

        if(height[left] <= height[right])
        {
            if(height[i] <= height[left])
            {
                total += height[left] - height[i];
            }
            i ++;
            continue;
        }

        // Get the maximum seen so far from the RHS.
        if(height[right] < height[j])
        {
            right = j;
        }

        if(height[right] <= height[left])
        {
            if(height[j] <= height[right])
            {
                total += height[right] - height[j];
            }
            j--;
            continue;
        }
    }

    return total;
    }
};