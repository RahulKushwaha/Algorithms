enum State {one, two, three, four, none};

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int length = data.size();
        
        if(length == 0)
        {
            return true;
        }
        
        int remaining = 0;
        State state = none;
        
        for(int i = 0; i < length; i ++)
        {
            int singleMask = 0x80;
            int twoMask = 0xc0;
            int thirdMask = 0xe0;
            int fourMask = 0xf0;
            
            int byte = data[i];
            if((fourMask & byte) == 0xf0)
            {
                //cout<<"Four Bytes"<<endl;
                if(remaining != 0)
                {
                    return false;
                }
                
                remaining += 3;
            }
            else if((thirdMask & byte) == 0xe0)
            {
                //cout<<"Three Bytes"<<endl;
                if(remaining != 0)
                {
                    return false;
                }
                
                remaining += 2;
            }
            else if((twoMask & byte) == 0xc0)
            {
                //cout<<"Two Bytes"<<endl;
                if(remaining != 0)
                {
                    return false;
                }
                
                remaining += 1;
            }
            else if((singleMask & byte) == 0x80)
            {
                //cout<<"Continuation Byte"<<endl;
                remaining--;
            }
            else
            {
                //cout<<"One Byte"<<endl;
                if(remaining != 0)
                {
                    return false;
                }
                
                remaining;
            }
        }
        
        return remaining == 0;
    }
};