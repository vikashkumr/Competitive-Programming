#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,d,count=0;
    cin>>n>>d;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n, greater<ll>());
    for(int i=0;i<n-1;i++){
        if(arr[i]-arr[i+1]<=d){
            count++;
            i++;
        }
    }
    cout<<count<<"\n";
    return 0;
}