class ZigzagIterator {
public:
    vector<vector<int>::iterator> iterators;
    vector<vector<int>::iterator> endMarkers;
    int currentIndex;
    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iterators.push_back(v1.begin());
        iterators.push_back(v2.begin());
        
        endMarkers.push_back(v1.end());
        endMarkers.push_back(v2.end());
        
        currentIndex = -1;
    }

    int next() {
        currentIndex ++;
        for(int i = currentIndex; i < currentIndex + iterators.size(); i ++)
        {
            int index = i % iterators.size();
            if(iterators[index] != endMarkers[index])
            {
                currentIndex = index; 
                int result = *iterators[index];
                iterators[index] ++;
                return result;
            }
        }
        
        return 0;
    }

    bool hasNext() {
        for(int i = 0; i < iterators.size(); i ++)
        {
            if(iterators[i] != endMarkers[i])
            {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */