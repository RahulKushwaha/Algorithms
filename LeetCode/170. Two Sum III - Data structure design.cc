class TwoSum {
public:
    multiset<int> numbers;
    // Add the number to an internal data structure.
	void add(int number) {
	    numbers.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    if(numbers.size() == 0)
	    {
	        return false;
	    }
	    
	    multiset<int>::iterator l = numbers.begin();
	    multiset<int>::iterator h = numbers.end();
	    h--;
	    
	    int sum = 0;
	    while(l != h)
	    {
	        sum = *l + *h;
	        if(sum == value)
	        {
	            return true;
	        }
	        
	        if(sum < value)
	        {
	            l ++;
	        }
	        else
	        {
	            h --;
	        }
	    }
	    
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);