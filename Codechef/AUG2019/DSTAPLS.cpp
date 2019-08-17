#include<iostream>
using namespace std;
#define ll long long
int main(){
   ll t;
   cin>>t;
   while(t--){
      ll n,k;
      cin>>n>>k;
      ll ans = n/k;
      if(ans%k==0)
      cout<<"NO\n";
      else
      cout<<"YES\n";
   }
   return 0;
}
