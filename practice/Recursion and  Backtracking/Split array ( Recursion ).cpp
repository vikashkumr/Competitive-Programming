//count number of subset of elements that are selected from 
//a given set whose sum adds up to a given number K.

#include<bits/stdc++.h>
using namespace std;
int cnt=0;
vector<int>v;
map<int,int>mp;
int n;
void countSubset(int sumTillNow,int sum,int k,int *arr,int i){
    
    //base case
    if(sumTillNow==k){
        cnt++;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        for(int ele : v) {
            cout<<ele<<" ";
            mp[ele]--;
        }
        cout<<"and ";
        for(auto it : mp) {
            // if(it.second>0) cout<<it.first<<" ";
            if(it.second>0) {
                int tmp = it.second;
                while(tmp--)
                cout<<it.first<<" ";
            }
            
        }
        mp.clear();
        cout<<"\n";
        return;
    }

    ///Backtracking conditions
    if((sumTillNow+sum)<k)
    return;

    if(sumTillNow>k)
    return;

    //recursive case
    v.push_back(arr[i]);
    countSubset(sumTillNow+arr[i],sum-arr[i],k,arr,i+1);
    if(v.size()) v.pop_back();
    countSubset(sumTillNow,sum-arr[i],k,arr,i+1);
}

int main(){
    int sum=0;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    countSubset(0,sum,sum/2,arr,0);
    cout<<cnt<<"\n";
   return 0;
}