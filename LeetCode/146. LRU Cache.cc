class LRUCache{
public:
    list<pair<int, int> > elements;
    unordered_map<int, list<pair<int, int> >::iterator> lookup;
    int maxSize;

    LRUCache(int capacity) {
        maxSize = capacity;
    }

    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator itr = lookup.find(key);
        if(itr == lookup.end())
        {
            return -1;
        }

        int value = itr->second->second;
        elements.erase(itr->second);
        elements.push_front(make_pair(key, value));

        lookup[key] = elements.begin();
        return elements.begin()->second;
    }

    void set(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator itr = lookup.find(key);
        if(itr != lookup.end())
        {
            elements.erase(itr->second);
        }
        else
        {
            if(lookup.size() == maxSize)
            {
                lookup.erase(elements.crbegin()->first);
                elements.pop_back();
            }
        }

        elements.push_front(make_pair(key, value));
        lookup[key] = elements.begin();
    }
};
