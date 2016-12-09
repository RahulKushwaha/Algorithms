struct Trie{
    Trie* next[2];
    bool isLeaf;
    int value;
    
    Trie(): isLeaf(false){
        next[0] = next[1] = NULL;
    }
};

class Solution {
public:
    void add(Trie* root, int num)
    {
        Trie* currentNode = root;
        int value = num;
        bitset<32> bits (num);
        for(int i = 30; i >= 0; i --)
        {
            int child = bits[i];
            if(currentNode->next[child] == NULL)
            {
                currentNode->next[child] = new Trie();
            }
            
            currentNode = currentNode->next[child];
        }
        
        currentNode->isLeaf = true;
        currentNode->value = value;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int length = nums.size();
        Trie root;
        int output = 0;

        for(int i = 0; i < length; i ++)
        {
            add(&root, nums[i]);
        }
        
        for(int i = 0; i < length; i ++)
        {
            Trie* currentNode = &root;
            Trie* prev = currentNode;
            bitset<32> bits (nums[i]);
            for(int i = 30; i >= 0 && currentNode; i --)
            {
                int child = bits[i];
                int alternate = child ? 0 : 1;
                prev = currentNode;
                
                if(currentNode->next[alternate])
                {
                    currentNode = currentNode->next[alternate];
                }
                else
                {
                    currentNode = currentNode->next[child];
                }
            }
            
            int largestSecond = getLargest(prev);
            //cout<<nums[i]<<" "<<largestSecond<<endl;
            output = max(output, largestSecond^nums[i]);
        }
        
        return output;
    }
    
    int getLargest(Trie* node)
    {
        Trie* prev = node;
        while(node)
        {
            prev = node;
            if(node->next[1])
            {
                node = node->next[1];
            }
            else
            {
                node = node->next[0];
            }
        }
        
        return prev->value;
    }
};