#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin>>s;
    int res = 0;
    int l = s.length();
    for(int i=0;i<=l-3;++i) {
       for(int j = i;j<=l-3;j++) {
           string tempstr = s.substr(j,4);
           if(tempstr == "bear") {
               res+=l-j-3;
               break;
           }
       }
    }
    cout<<res;
    return 0;
}