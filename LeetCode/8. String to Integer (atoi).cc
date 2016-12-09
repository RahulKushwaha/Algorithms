class Solution {
public:
    int myAtoi(string str) {
        
        if(str.size() == 0 )
        {
            return 0;
        }
        
        int index = str.find_first_not_of(' ');
        if (index != std::string::npos)
            str = str.substr(index);
        
        index = str.find_last_not_of(' ');
        if (index !=std::string::npos)
            str = str.substr(0, index + 1);
        
        bool negative = false;
        if(str[0] == '-' || str[0] == '+')
        {
            if(str[0] == '-')
            {
                negative = true;
            }
            
            str = str.substr(1);
        }
        
        int num =  0 ;
        int multiplier = 1;
        
        for (int i = str.size() - 1; i >= 0; i --, multiplier *= 10)
        {
            if(str[i] - '0' < 0 || str[i] - '0' > 9)
            {
                return 0;
            }
            
            num += ((str[i] - '0') * multiplier);
        }
        
        if(negative)
        {
            num *= -1;
        }
        
        return num;
    }
};