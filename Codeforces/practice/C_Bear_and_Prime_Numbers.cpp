#include<bits/stdc++.h>
using namespace std;
#define  _IO    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
int freq[10000001];
ll prime[10000001];
int main() {
    _IO
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        freq[temp]++;
    }

//Sieve //precomputation
    for(int i=2;i<=10000000;i++) {
        int cnt = 0;
        if(prime[i]==0) {
            for(int p = i;p<=10000000;p+=i) {
                if(p!=i)
                prime[p] = -1;
                if(freq[p]!=0)
                cnt+=freq[p];
            }
        }
        prime[i] = cnt;
    }
    for(int i=2;i<=10000000;i++) {
        if(prime[i]>=0) {
            prime[i] +=prime[i-1]; 
        } else {
            prime[i] = prime[i-1];
        }
    }
    


    //Queries start
    int m;
    cin>>m;
    while(m--) {
        int l,r;
        cin>>l>>r;
        l = min(l,10000000);
        r = min(r,10000000);
        cout<<prime[r]-prime[l-1]<<"\n";
    }
    return 0;
}