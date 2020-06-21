#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
#define sz 100005
const int inf = 1e16;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//
vector<pii> gr[sz], rgr[sz];
int distN2H[sz], distH2N[sz];
int n, m, x, q;
void H2N() {
    //dijkshtra
    priority_queue<pii, vector<pii>, greater<pii>> pq; // <dist, node>

    //assigning all dist inf initially
    for(int i=0;i<=n;i++) distH2N[i] = inf;
    distH2N[x] = 0;
    pq.push({0,x});
    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        for(auto child: gr[node.second]) {
            if(distH2N[node.second] + child.second < distH2N[child.first]) {
                distH2N[child.first] = distH2N[node.second] + child.second;
                pq.push({distH2N[child.first], child.first});
            }
        }
    }
}

void N2H() {
    //on transpose graph
    priority_queue<pii, vector<pii>, greater<pii>> pq; // <dist, node>

    //assigning all dist inf initially
    for(int i=0;i<=n;i++) distN2H[i] = inf;
    distN2H[x] = 0;

    pq.push({0,x});
    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        for(auto child: rgr[node.second]) {
            if(distN2H[node.second] + child.second < distN2H[child.first]) {
                distN2H[child.first] = distN2H[node.second] + child.second;
                pq.push({distN2H[child.first], child.first});
            }
        }
    }
}



int32_t main(){
    fast;
    int cnt = 1;
    test() {
        cin >> n >> m >> x >> q;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;v--;
            gr[u].push_back({v,w});
            rgr[v].push_back({u,w});
        }
        x--;
        N2H();
        H2N();
        cout << "Case "<< cnt++ <<":" << endl;
        while(q--) {
            int s, t;
            cin>>s>>t;
            s--;t--;
            if(distN2H[s] + distH2N[t] < inf) {
                cout << distN2H[s] + distH2N[t] << endl;
            } else {
                cout << "Be seeing ya, John" << endl;
            }
        }
    }
    return 0;
}