/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        
        return gcd(b, a % b);
    }
    
    pair<int, int> getSlope(Point& p1, Point& p2)
    {
        int num = p2.y - p1.y;
        int deno = p2.x - p1.x;
        //cout<<num<<" "<<deno<<endl;
        
        bool numNegative = false;
        bool denoNegative = false;
        
        if(num < 0)
        {
            num = -num;
            numNegative = true;
        }
        
        if(deno < 0)
        {
            deno = -deno;
            denoNegative = true;
        }
        
        if(deno != 0)
        {
            int hcf = gcd(num, deno);
        
            num /= hcf;
            deno /= hcf;
        }
        
        if((num == 0 && deno != 0))
        {
            return make_pair(0, 1);
        }
        else if(num != 0 && deno == 0)
        {
            return make_pair(1, 0);
        }
        
        if((numNegative && denoNegative == false) || (numNegative == false && denoNegative))
        {
            num = -num;
        }
        
        return make_pair(num, deno);
    }

    int maxPoints(vector<Point>& points) {
        int length = points.size();
        if(length == 0 || length == 1)
        {
            return length;
        }
        
        int ans = 0;
        map<pair<int, int>, int> freq;
        
        for(int i = 0; i < length; i ++)
        {
            int count = ++freq[make_pair(points[i].x, points[i].y)];  
            ans = max(ans, count);
        }
        
        for(int i = 0; i < length; i ++)
        {
            map<pair<pair<int, int>, int>, int> lookup;
            
            for(int j = 0; j < length; j ++)
            {
                Point p1 = points[i];
                Point p2 = points[j];
                
                if(p1.x == p2.x && p1.y == p2.y)
                {
                    continue;
                }

                if(p2.x < p1.x)
                {
                    swap(p2, p1);
                }
                else if(p2.x == p1.x && p2.y < p1.y)
                {
                    swap(p2, p1);
                }
                
                pair<int, int> slope = getSlope(p1, p2);
                
                int a = -(slope.first);
                int b = slope.second;
                int c = p1.x * (slope.first) - p1.y * (slope.second);
                
                pair<pair<int, int>, int> key = make_pair(make_pair(a, b), c);
                
                map<pair<pair<int, int>, int>, int>::iterator itr = lookup.find(key);
                
                if(itr == lookup.end())
                {
                    lookup[key] = freq[make_pair(points[i].x, points[i].y)] + 1;
                }
                else
                {
                    lookup[key] ++;
                }
            }
            
            for(map<pair<pair<int, int>, int>, int>::iterator itr = lookup.begin(); itr != lookup.end(); itr ++)
            {
                ans = max(ans, itr->second);
            }
        }
        
        return ans;
    }
};