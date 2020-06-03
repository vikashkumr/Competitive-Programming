//bfs implimentation of graph template type

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
    unordered_map<T,list<T> >adj;
    public:
    Graph(){ 
    }
    void addEdge(T u,T v,bool bidir){
        if(!bidir){
            adj[u].push_back(v);    
        }
        else{
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    void topologicalSort(){
       queue<T>q;
       unordered_map<T,int>indegree;
       for(auto i:adj){
           indegree[i.first]=0;
       }

        // Init the degree of all node
        for(auto it:adj){
            T node = it.first;
            for(T child:adj[node]){
                indegree[child]++;
            }
        }

        //store element having indegree 0 in to the q

        for(auto it:indegree){
            if(indegree[it.first]==0) q.push(it.first);
        }
    //performing steps
        while(!q.empty()){
            T temp = q.front();
            cout<<temp<<" ";
            q.pop();
            for(T it:adj[temp]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
    }
};

int main(){

    Graph<char> g;
    g.addEdge('d','x',false);
    g.addEdge('a','d',false);
    g.addEdge('a','t',false);
    g.addEdge('a','m',false);
    g.addEdge('x','m',false);
    g.topologicalSort();
    //g.dfs('a');
    //cout<<"\n";
    //g.vis.clear();
    //g.bfs();
    return 0;
}