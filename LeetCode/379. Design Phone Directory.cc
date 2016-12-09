class PhoneDirectory {
public:
    bool* usedNumbers;
    queue<int> newNumbers;
    int capacity;
    
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        capacity = maxNumbers;
        usedNumbers = new bool[2000];
        
        for(int i = 0; i < capacity; i ++)
        {
            newNumbers.push(i);
            usedNumbers[i] = false;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(newNumbers.empty())
        {
            return -1;
        }
        
        int num = newNumbers.front();
        newNumbers.pop();
        usedNumbers[num] = true;
        
        return num;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !usedNumbers[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        bool & current = usedNumbers[number];
        if(current)
        {
            current = false;
            newNumbers.push(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */