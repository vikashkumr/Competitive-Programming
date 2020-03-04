//Fenwick Tree Inversion Count
//Implementation
//update ===> O(logn)
//overal TC (Build) ===> O(nlogn)

#include<bits/stdc++.h>
using namespace std;

long query(long *Bit,long i){
    long ans = 0;
    while(i>0){
        ans += Bit[i];
        i-=i&(-i);
    }
    return ans;
}

void update(long *Bit, long i, long inc, long n){
    while (i<=n)
    {
        Bit[i] += inc;
        i += i&(-i);   
    }
}

int main(){
    long t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        long arr[n+1];
        long mx = -1;
        for(long i=1;i<=n;i++) {
            cin>>arr[i];
            mx = max(mx,arr[i]);
        }
        long Bit[mx+1];
        for(int i=0;i<=mx;i++) Bit[i]=0;
        long ans = 0;
        for(long i=n;i>0;i--){
            ans += query(Bit,arr[i]-1);
            update(Bit,arr[i],1,mx);
        }
        cout<<ans<<endl;
    }
    return 0;
}

