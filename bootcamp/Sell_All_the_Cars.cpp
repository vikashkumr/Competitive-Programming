#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *p = new int[n];
        for(int i=0;i<n;i++) cin>>p[i];
        sort(p,p+n);
        reverse(p,p+n);
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += max(p[i]-i,0);
            ans%=1000000007;
        }
        cout<<ans%1000000007<<"\n";
    }


    return 0;
}