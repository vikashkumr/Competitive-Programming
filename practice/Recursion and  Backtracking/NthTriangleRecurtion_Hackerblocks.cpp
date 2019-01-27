#include<bits/stdc++.h>
using namespace std;
int triangle(int n){
	if(n==1) return 1;
	return n+triangle(n-1);
}
int main(){
	int n;
	cin>>n;
	cout<<triangle(n);
	return 0;
}
