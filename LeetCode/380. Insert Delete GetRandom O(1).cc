class RandomizedSet {
public:
    unordered_map<int, int> usedNumbers;
    vector<int> input;
    int index;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        usedNumbers.rehash(10000);
        input.resize(10000);
        index = -1;
        srand (time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        //cout<<"Insert"<<endl;
        unordered_map<int, int>::iterator itr = usedNumbers.find(val);
        if(itr == usedNumbers.end())
        {
            index ++;
            input[index] = val;
            usedNumbers.insert(make_pair(val, index));
            
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //cout<<"Remove"<<endl;
        unordered_map<int, int>::iterator itr = usedNumbers.find(val);
        if(itr != usedNumbers.end())
        {
            usedNumbers[input[index]] = itr->second;
            input[itr->second] = input[index];
            usedNumbers.erase(itr);
            index --;
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //cout<<"GetRandom"<<endl;
         if(index >= 0)
         {
             int randomNumber = rand() % (index + 1);
             return input[randomNumber];
         }
         
         return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */