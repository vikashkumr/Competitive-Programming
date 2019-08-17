#include<bits/stdc++.h>
using namespace std;
void flip(string &s,int i){
    if(s[i]=='0'){
        s[i]='1';
        return;
    }
    if(s[i]=='1'){
        s[i]='0';
        return;
    }
    if(s[i]=='x'){
        s[i]='x';
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len = s.length();
        int curr=0;
        if(s[curr]=='1'){
            s[curr]='x';
            flip(s,curr+1);
            curr++;
        }
        for(int i=curr;i<len;i++){
            if(s[i]=='0' || s[i]=='x'){
                continue;
            }
            else {
                s[i]='x';
                if(s[i-1]=='0'){
                    s[i-1]='1';
                    if((i+1)<len)
                    flip(s,i+1);
                    i=i-2;
                }
                else {
                    if((i+1)<len)
                    flip(s,i+1);
                }
            }
          }
        // cout<<s;
        int flag=0;
        for(int i=0;i<len;i++){
            if(s[i]=='x')
            continue;
            else {
                flag=1;
                break;
            }
        }
        if(flag)
        cout<<"LOSE"<<"\n";
        else {
            cout<<"WIN\n";
        }
    }
    return 0;
}
