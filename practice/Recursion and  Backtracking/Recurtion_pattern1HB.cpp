#include<bits/stdc++.h>
using namespace std;
void pattern1(int n){
	if(n==1)
	cout<<"*"<<endl;
	else {
		pattern1(n-1);
		for(int i=1;i<=n;i++)
		cout<<"*"<<"\t";
		cout<<"\n";
	}
}
int main(){
	int n;
	cin>>n;
	pattern1(n);
	return 0;
}
