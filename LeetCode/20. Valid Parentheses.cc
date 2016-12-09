class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() == 0)
        {
            return false;
        }
        
        stack<char> elements;
        
        for(int i = 0; i < s.size(); i ++)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                elements.push(s[i]);
                break;
                
                case ']':
                if(elements.empty() == false)
                {
                    char top = elements.top();
                    if(top == '[')
                    {
                        elements.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                
                break;
                
                case '}':
                if(elements.empty() == false)
                {
                    char top = elements.top();
                    if(top == '{')
                    {
                        elements.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                   return false;
                }
                
                break;
                
                case ')':
                if(elements.empty() == false)
                {
                    char top = elements.top();
                    if(top == '(')
                    {
                        elements.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                
                break;
            }
        }
        
        return elements.empty();
    }
};class Solution {
public:
    int search(vector<int>& nums, int key, int l, int u, int& a, int& b)
    {
        while(l < u)
        {
            int sum = nums[l] + nums[u];
            if(sum == key)
            {
                a = l;
                b = u;
                return 1;
            }
            
            if(sum < key)
            {
                l ++;
            }
            else 
            {
                u --;
            }
        }
        
        return -1;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> output;
        if(length < 4)
        {
            return output;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < length;)
        {
            int a = nums[i];
            for(int j = i + 1; j < length;)
            {
                int b = nums[j];
                int k, l;
                int key = target + (-1) *(a + b);
                int flag = search(nums, key, j + 1, length - 1, k, l);
                while(flag != -1)
                {
                    vector<int> result; 
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    result.push_back(nums[k]);
                    result.push_back(nums[l]);
                    output.push_back(result);
                    
                    int x = nums[k];
                    while(k < length)
                    {
                        if(nums[k] == x)
                        {
                            k ++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    
                    flag = search(nums, key, k, l, k, l);
                }
                
                while(j < length)
                {
                    if(nums[j] == b)
                    {
                        j ++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
            while(i < length)
            {
                if(nums[i] == a)
                {
                    i ++;
                }
                else
                {
                    break;
                }
            }
        }
        
        return output;  
    }
};