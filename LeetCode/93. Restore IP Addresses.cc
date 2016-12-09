class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> output;
        if(s.size() >= 4 && s.size() <= 12)
        {
            string currentIp = "";
            GenerateAllCombinations(s, output, currentIp, 0);
        }
        
        return output;
    }
    
    void GenerateAllCombinations(string s, vector<string>& output, string ip, int partitions)
    {
        if(partitions > 4)
        {
            return;
        }

        if(s.size() == 0 && partitions == 4)
        {
            output.push_back(ip.substr(1));
            return;
        }

        int num = 0;

        for(int i = 0; i < 3 && i < s.size(); i ++)
        {
            num = (num * 10) + (s[i] - '0');
            if(num <= 255)
            {
                GenerateAllCombinations(s.substr(i + 1), output, ip + "." + s.substr(0, i + 1), partitions + 1);
            }

            if(num == 0 && i == 0)
            {
                break;
            }
        }
    }
};