//count number of subset of elements that are selected from 
//a given set whose sum adds up to a given number K.

#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void countSubset(int sumTillNow,int sum,int k,int *arr,int i){
    
    //base case
    if(sumTillNow==k){
        cnt++;
        //  cout<<cnt;
        return;
    }

    ///Backtracking conditions
    if((sumTillNow+sum)<k)
    return;

    if(sumTillNow>k)
    return;

    //recursive case
    countSubset(sumTillNow+arr[i],sum-arr[i],k,arr,i+1);
    countSubset(sumTillNow,sum-arr[i],k,arr,i+1);
}

int main(){
    int n,sum=0,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    countSubset(0,sum,k,arr,0);
    cout<<cnt<<"\n";
   return 0;
}