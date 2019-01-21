#include<bits/stdc++.h>
using namespace std;
bool poss(int mid,int space[],int size,int c){
	int cows=1;
	int cowplaced=1,lastpos=space[0];
	for(int i=1;i<size;i++){
		if(space[i]-lastpos>=mid){
			if(++cowplaced==c)
			return 1;
		lastpos=space[i];
		}
	}
	return 0;
}


int main(){
	int n,c,t;
	cin>>t;
	while(t--){
	cin>>n>>c;
	int space[n];
	for(int i=0;i<n;i++){
		cin>>space[i];
	}
	int ans;
	sort(space,space+n);
	int xi=space[0],xf=space[n-1],mid;
	while(xi<=xf){
		mid=(xi+xf)/2;
		if(poss(mid,space,n,c)){
			xi=mid+1;
			ans=mid;
		}
		else
		xf=mid-1;
	}
	cout<<ans<<endl;
}
return 0;
}
