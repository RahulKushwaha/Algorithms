#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

class UnionFind{
    int * links; 
    int * ranks;
    int numberOfNodes;

    public:
    int find(int node){
        int parent = node;
        if(links[node] != node){
            parent = find(links[node]);
            links[node] = parent;
        }
        
        return parent; 
    }
    
    bool connect(int a, int b){
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1 == p2){
            return false;
        }
        
        int p, c;
        
        if(ranks[p1] < ranks[p2]){
            p = p1;
            c = p2;
        }else{
            p = p2;
            c = p1;
        }
        
        links[c] = p;
        ranks[p] += ranks[c];
        
        return true;
    }
    
    UnionFind(int n): numberOfNodes(n){
        if(n == 0){
            return;
        }
        
        links = new int[n];
        ranks = new int[n];
        
        for(int i = 0; i < n; i ++){
            links[i] = i;
            ranks[i] = 1;
        }
    }
};

int main() {
    
    int n, m;
    cin>>n>>m;
    
    unordered_map<int, list<pair<int, int>>> lookup;
    lookup.rehash(n);
    vector<int> distances(m);
    
    for(int i = 0; i < m; i ++){
        int x, y, d;
        cin>>x>>y>>d;
        
        distances[i] = d;
        lookup[d].push_back(make_pair(x, y));
    }
    
    priority_queue<int, vector<int>, greater<int>> pq(distances.begin(), distances.end());
    int output = 0;
    UnionFind uf(n);
        
    while(pq.empty() == false){
        int d = pq.top();
        unordered_map<int, list<pair<int, int>>>::iterator itr = lookup.find(d);
        if(itr != lookup.end() && itr->second.size() != 0){
            pair<int, int> point = *(itr->second.begin());
            itr->second.pop_front();
            
            if(uf.connect(point.first - 1, point.second -1)){
                output += d;
            }            
        }
        
        pq.pop();
    }
    
    cout<<output<<endl;
    
    return 0;
}
