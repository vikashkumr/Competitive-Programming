//Print all permutation of a given string
//Time Complexity = O(n!*n)

#include<bits/stdc++.h>
using namespace std;
void permute(int s, int e,string str){
    if(s==e){
        cout<<str<<"\n";
        return;
    }
    
    for(int i=s;i<=e;i++){
        swap(str[s],str[i]);
        permute(s+1,e,str);
        swap(str[s],str[i]);
    }

}

int main(){
    string str="abc";
    permute(0,str.length()-1,str);
    return 0;
}