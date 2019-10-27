#include<iostream>
#include<cmath>
using namespace std;
#define test() int t;cin>>t;while(t--)
int main(){
	test(){
		int n,ans; cin>>n;

		ans = n;
		while(n%2==0){
			n=n>>1;
			ans=2;
		}

		for(int i=3;i<=sqrt(n);i+=2){
			while(n%i==0){
				n=n/i;
				ans=i;
			}
		}

		if(n>2)
		ans = n;

		cout<<n<<endl;
	}
}