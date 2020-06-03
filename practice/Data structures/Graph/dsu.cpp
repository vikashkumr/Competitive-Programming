#include<bits/stdc++.h>
using namespace std;
class dsu {
    vector<int>parent, rank;
    int totalComponents;
public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        totalComponents = n;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]); //path compression 
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(rank[a] < rank[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) 
                rank[a]++;
            totalComponents--;
        }
    }
};


int main(){
    
}