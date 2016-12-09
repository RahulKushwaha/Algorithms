/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    bool getNextVal(string& data, int & val)
    {
        int totalLength = data.size();
        if(totalLength == 0)
        {
            return false;
        }
        
        int index = 0;
        if(data[index] == ',')
        {
            index ++;
        }
        
        if(index < totalLength)
        {
            if(data[index] == '#')
            {
                index ++;
                data = data.substr(index);
                return false;
            }
        }
        
        int num = 0;
        
        bool negative = false;
        
        if(data[index] == '+' || data[index] == '-')
        {
            negative = data[index] == '-';
            index ++;
        }
        
        for(index; index < data.size(); index ++)
        {
            int digit = data[index] - '0';
            if(digit < 0 || digit > 9)
            {
                break;
            }
            
            num *= 10;
            num += digit;
        }
        
        if(negative)
        {
            num *= -1;
        }
        
        val = num;
        data = data.substr(index);
        return true;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
        {
            return "#";
        }
        
        string output; 
        string left = serialize(root->left);
        string right = serialize(root->right);
        output = to_string(root->val) + "," + left + "," + right;
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
        {
            return NULL;
        }
        
        return deserializeTree(data);
    }
    
    TreeNode* deserializeTree(string & data)
    {
        int val;
        if(getNextVal(data, val))
        {
            TreeNode * root = new TreeNode(val);
            root->left = deserializeTree(data);
            root->right = deserializeTree(data);
            
            return root;
        }
        
        return NULL;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));