#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    unordered_map<int, int> hm;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int pre = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++) {
	        pre+=a[i];
	        if(pre==0) ans++;
	        if(hm.count(pre) > 0) {
	            ans+=hm[pre];
	        } 
	        hm[pre]++;
	    }
	    cout<< ans<<endl;
	}
	return 0;
}

/*
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7
Output:
6
4
*/