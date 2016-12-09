class Solution {
public:
    unordered_map<int, string> lookup;
    map<int, string> factors;
    Solution()
    {
        lookup.insert(make_pair(0, "Zero"));
        lookup.insert(make_pair(1, "One"));
        lookup.insert(make_pair(2, "Two"));
        lookup.insert(make_pair(3, "Three"));
        lookup.insert(make_pair(4, "Four"));
        lookup.insert(make_pair(5, "Five"));
        lookup.insert(make_pair(6, "Six"));
        lookup.insert(make_pair(7, "Seven"));
        lookup.insert(make_pair(8, "Eight"));
        lookup.insert(make_pair(9, "Nine"));
        lookup.insert(make_pair(10, "Ten"));
        lookup.insert(make_pair(11, "Eleven"));
        lookup.insert(make_pair(12, "Twelve"));
        lookup.insert(make_pair(13, "Thirteen"));
        lookup.insert(make_pair(14, "Fourteen"));
        lookup.insert(make_pair(15, "Fifteen"));
        lookup.insert(make_pair(16, "Sixteen"));
        lookup.insert(make_pair(17, "Seventeen"));
        lookup.insert(make_pair(18, "Eighteen"));
        lookup.insert(make_pair(19, "Nineteen"));

        factors.insert(make_pair(20, "Twenty"));
        factors.insert(make_pair(30, "Thirty"));
        factors.insert(make_pair(40, "Forty"));
        factors.insert(make_pair(50, "Fifty"));
        factors.insert(make_pair(60, "Sixty"));
        factors.insert(make_pair(70, "Seventy"));
        factors.insert(make_pair(80, "Eighty"));
        factors.insert(make_pair(90, "Ninety"));
        
        factors.insert(make_pair(100, "Hundred"));
        factors.insert(make_pair(1000, "Thousand"));
        factors.insert(make_pair(1000000, "Million"));
        factors.insert(make_pair(1000000000, "Billion"));
    }
    
    
    
    string numberToWords(int num) {
        unordered_map<int, string>::iterator wordsItr = lookup.find(num);
        if(wordsItr != lookup.end())
        {
            return wordsItr->second;
        }
        
        string output;
        if(num != 0)
        {
            for(map<int, string>::reverse_iterator itr = factors.rbegin(); itr != factors.rend(); itr ++)
            {
                if(num >= itr->first)
                {
                    int quotient = num / itr->first;
                    
                    num %= itr->first;
                    if(itr->first / 10 >= 10)
                    {
                        output += numberToWords(quotient) + ' ';    
                    }
                    
                    output += itr->second;
                    
                    if(num > 0)
                    {
                        output += ' ' + numberToWords(num);
                    }
                    break;
                }
            }
        }
        
        return output;
    }
};