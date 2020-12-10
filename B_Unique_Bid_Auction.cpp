#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<int,int>m;
void print(int *a, int ans, int n) {

    for(int i=0;i<n;i++){
        if(a[i]==ans){
            cout<<i+1<<endl;
            break;
        }
    }
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        m.clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        int ans=0;
        for(auto it: m){
            if(it.second==1){
                ans=it.first;
                break;
            }
        }
        print(a, ans, n);
        if(ans==0){
            cout<<-1<<endl;
        }
     
    }
}

int main() {
    solve();
}