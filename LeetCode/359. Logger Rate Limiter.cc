
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    unordered_map<string, int> lookup;
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        unordered_map<string, int>::iterator itr = lookup.find(message);
        
        if(itr == lookup.end())
        {
            lookup[message] = timestamp;
            return true;
        }
        
        if(timestamp - itr->second >= 10)
        {
            lookup[message] = timestamp;
            return true;
        }
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */