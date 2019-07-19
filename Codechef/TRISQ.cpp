#include<bits/stdc++.h>
using namespace std;
int countSquare(int base){
//base case
    if(base<2)
    return 0;
//recursive case
    return (base/2)+countSquare(base-2)-1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int base;
        cin>>base;
        int ans = countSquare(base);
        cout<<ans<<endl;
    }
    return 0;
}