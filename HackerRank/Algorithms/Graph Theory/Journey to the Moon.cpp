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
    
    vector<long long> getTreeSizesInForest(){
        vector<long long> output;
        long long singleNodes = 0;
        for(int i = 0; i < numberOfNodes; i++){
            if(links[i] == i){
                output.push_back(ranks[i]);
            }            
        }
        
        return output;
    }
};



int main() {
    int n, m;
    cin>>n>>m;
    
    UnionFind uf(n);
    
    for(int i = 0; i < m; i ++){
        int x, y;
        cin>>x>>y;

        uf.connect(x, y);
    }
    
    vector<long long> treeSizes = uf.getTreeSizesInForest();
    long long output = 0, limit = treeSizes.size(), last = treeSizes[0];
    for(int i = 1; i < limit; i ++){
        output += last * treeSizes[i];
        last += treeSizes[i];
    }
    
    cout<<output<<endl;
    
    return 0;
}
