#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    cout<<"\n";
    ll N,sum=0,temp;
    cin>>N;
    for(ll i=1;i<=N;i++)
    {
      cin>>temp;
      if(temp<N)
      sum+=temp;
      else
      sum+=(temp%N);
    }
    if(sum%N==0)
    cout<<"YES"<<"\n";
    else
    cout<<"NO"<<"\n";
    cout<<"\n";
    }
    return 0;
}

