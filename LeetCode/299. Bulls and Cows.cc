class Solution {
public:
    string getHint(string secret, string guess) {
        int cows = 0;
        int bulls = 0;
        
        int freqS[256] = {0}, freqG[256] = {0};
        
        for(int i = 0; i < secret.size(); i ++)
        {
            char g = guess[i];
            char s = secret[i];
            if(g == s)
            {
                bulls ++;
            }
            else
            {
                freqS[s] ++;
                freqG[g] ++;
            }
        }
        
        for(int i = 0; i < 256; i ++)
        {
            cows += min(freqS[i], freqG[i]);
        }
        
        stringstream output;
        
        output<<bulls<<"A"<<cows<<"B";
        
        return output.str();
    }
};