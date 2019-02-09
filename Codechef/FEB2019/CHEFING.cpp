#include<bits/stdc++.h>
using namespace std;
string removeDupli(string s,int size){
	if(size==0)
	return s;
	if(s[size]==s[size-1]){
		s.erase(size,1);
		return removeDupli(s,size-1);
	}
	else
	return removeDupli(s,size-1);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0,temp;
		cin>>n;
		temp=n;
		string s;
		map<char,int>m;
		while(temp--){
			cin>>s;
			sort(s.begin(),s.end());
			s=removeDupli(s,s.length()-1);
			//cout<<s<<"\n";
			for(int i=0;i<s.length();i++){
				m[s[i]]++;
			}
		}
		for(map<char,int>::iterator it=m.begin();it!=m.end();it++){
			if((it->second)==n)
			cnt++;
			//cout<<it->first<<" "<<it->second<<"\n";
		}
		cout<<cnt<<endl;
	}
	return 0;
}
