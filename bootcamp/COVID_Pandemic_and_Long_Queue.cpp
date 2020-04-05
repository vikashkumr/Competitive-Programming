#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        bool arr[n];
        bool flag = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++) {
            if(arr[i]){
            for(int j=i+1;j<min(i+6,n);j++) {
                if(arr[j]) {
                    flag=1;
                    break;
                }
            }
        }   
        if(flag) break;
        }

        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}