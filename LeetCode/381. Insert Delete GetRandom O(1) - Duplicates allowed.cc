class RandomizedCollection {
public:
    unordered_map<int, set<int>> usedNumbers;
    vector<int> input;
    int index;
    int totalCount;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        usedNumbers.rehash(10000);
        input.resize(10000);
        index = -1;
        totalCount = -1;
        srand (time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, set<int>>::iterator itr = usedNumbers.find(val);
        bool result = false;
        if(itr == usedNumbers.end())
        {
            result = true;
        }
        
        index ++;
        totalCount ++;
        input[index] = val;
        usedNumbers[val].insert(index);
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        unordered_map<int, set<int>>::iterator itr = usedNumbers.find(val);
        if(itr != usedNumbers.end())
        {
            int freedIndex = *(itr->second.begin());
            itr->second.erase(freedIndex);
            if(itr->second.size() == 0)
            {
                usedNumbers.erase(itr);
            }
            
            totalCount --;
            
            itr = usedNumbers.find(input[index]);
            if(itr != usedNumbers.end())
            {
                itr->second.erase(index);
                itr->second.insert(freedIndex);
                input[freedIndex] = input[index];
            }
            
            index --;
            
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
         if(index >= 0)
         {
             int randomNumber = rand() % (index + 1);
             return input[randomNumber];
         }
         
         return -1;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */