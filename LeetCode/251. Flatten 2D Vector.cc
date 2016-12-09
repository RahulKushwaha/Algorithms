class Vector2D {
public:
    vector<vector<int>> elements;
    int i, j;
    int x;
    
    Vector2D(vector<vector<int>>& vec2d) {
        elements = vec2d;
        i = 0; 
        j = 0;
        x = vec2d.size();
    }

    int next() {
        return elements[i][j++];
    }

    bool hasNext() {
        int b = j;
        for(int a = i; a < x; a ++)
        {
            if(b < elements[a].size())
            {
                i = a; 
                j = b;
                return true;
            }
            
            b = 0;
        }
        
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */