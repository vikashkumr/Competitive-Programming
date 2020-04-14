#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
int main() 
{ 
   ll n,k;
	cin>>n>>k;
   int cnt = 0;
	for(int i = 2;i*i<=n;i++) {
      while(n%i==0) {
         n=n/i;
         cnt++;
      }
   }
   if(cnt<k) cout<<0<<"\n";
   else cout<<1<<"\n"; 
	return 0; 
} 
