//Longest increasing Subsequence
//Time complexity O(n^2) another solution is possible in O(nlogn)


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    int L[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    L[i]=1;
    for(int i=1;i<n;i++){
        int mx=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                if(L[j]>mx)
                mx=L[j];
            }
        }
        L[i]=1+mx;
    }
    int mx = L[0];
    for(int i=1;i<n;i++)
    mx=max(L[i],mx);
    cout<<mx;
   return 0;
}

// Binary Search TC: O(nlogn)
// 2 5 3 4 Test Case
int lis(int n, int *arr) {
    vector<int>seq;
    seq.push_back(arr[0]);
    for(int i=1;i<n;i++) {
        if(seq.back() < arr[i]) seq.push_back(arr[i]);
        else {
            int idx = lower_bound(seq.begin(), seq.end(), arr[i])-seq.begin();
            seq[idx] = arr[i];
        }
    }
    //seq doesn't contain acctual ans // problem is to find length of LIS not actual LIS
    return seq.size();
}


int main() {
    int arr[] = {2,5,3,4,7,8,10,6};
    int n = 8;
    cout<<lis(n, arr)<<endl;
    return 0;
}