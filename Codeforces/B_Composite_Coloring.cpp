#include<bits/stdc++.h>
using namespace std;
#define test()  int t;cin>>t;while(t--)
#define For(i,l,r)   for(int i=l;i<=r;i++)

int main() {
    test() {
        int n,temp;
        cin >> n;
        int res[n];
        int c = 1;
        map<int,int> mp;
        for(int i=0;i<=n;i++) {
            cin>>temp;
            for(int j=2;j<=31;j++) {
                if(temp%j==0) {
                    if(mp.count(j)<=0)  mp[j]=c++;
                    res[i]=mp[j];
                    break;
                }
            }
        }
        cout<<c-1<<"\n";
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
       
    }
    return 0;
}