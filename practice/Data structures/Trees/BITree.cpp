#include<bits/stdc++.h>
#define ll long long
#define MAX 100001
using namespace std;

//Binary Indexed Tree or Fanwick Tree

int getSum(int BITree[],int index){
    int sum = 0;
    index+=1;
    while(index>0){
        sum+=BITree[index];
        index-=index&(-index);
    }
    return sum;
}

void updateBITree(int BITree[],int n,int index,int val){
    index+=1;
    while(index<=n){
        BITree[index]+=val;
        index+=index&(-index);
    }
}

int *constructBITree(int arr[],int n){
    int *BITree = new int[n+1];
    for(int i=1;i<=n;i++)
    BITree[i]=0;
    for(int i=0;i<n;i++)
      updateBITree(BITree,n,i,arr[i]);
    return BITree;
}

int main(){
    int A[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(A)/sizeof(int);
    int *BITree = constructBITree(A,n);
    cout<<"sum of element in range [0,5] "<<getSum(BITree,5)<<"\n";
    A[3]+=5;
    updateBITree(BITree,n,3,6);
    cout<<"sum of element in range [0,5] "<<getSum(BITree,5)<<"\n";
    return 0;
}