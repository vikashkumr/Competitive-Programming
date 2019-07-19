//implementation of segment tree data structure 
//finding minimum in a range given
//updating Node and range
//1.Build Tree //2.Query //3.Update

#include<bits/stdc++.h>
using namespace std;

//building segment tree
void buildTree(int *tree, int *arr, int index, int s, int e){
    //base case
    if(s>e)
    return;
    if(s==e){
        tree[index] = arr[s];
        return;
    }
    //recursive case
    int mid = (s+e)/2;
    //build Left sub tree
    buildTree(tree,arr,2*index+1,s,mid);
    //build Right sub tree
    buildTree(tree,arr,2*index+2,mid+1,e);
    int left = tree[2*index+1];
    int right = tree[2*index+2];
    tree[index] = min(left,right);
}


//query
int query(int *tree, int index, int s, int e, int l, int r){
    //No overlap
    if(r<s || l>e){                
        return INT_MAX;        
    }

    //complete overlap
    if(s>=l && e<=r){
        return tree[index];
    }

    //partial overlap-call both side
    int mid = (s+e)/2;
    int leftAns = query(tree,2*index+1,s,mid,l,r);
    int rightAns = query(tree,2*index+2,mid+1,e,l,r);
    return min(leftAns,rightAns);
}

//Node Update
void updateNode(int *tree,int index,int s,int e,int i, int value){
    //No overlap
    if(i<s || i>e){
        return;
    }

    //reach at leaf node
    if(s==e){
        tree[index]=value;
    }

    //partially lying in range
    int mid = (s+e)/2;
    updateNode(tree,2*index+1,s,mid,i,value);
    updateNode(tree,2*index+2,mid+1,e,i,value);
    tree[index]=min(tree[2*index+1],tree[2*index+2]);
    return;
}

//Range Update
void updateRange(int *tree,int index,int s,int e,int l,int r,int inc){
    //No overlap
    if(r<s || l>e){
        return;
    }

    //reached leaf node
    if(s==e){
        tree[index] += inc;
        return;
    }

    mid = (s+e)/2;
    updateRange(tree,2*index+1,s,mid,l,r,inc);
    updateRange(tree,2*index+2,mid+1,e,l,r,inc);
    tree[index] = min(tree[2*index+1],tree[2*index+2]);
    return;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    int *tree = new int[4*n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(tree,arr,0,0,n-1);
    int n_of_q,l,r;
    cin>>n_of_q;
    while (n_of_q--){
        cin>>l>>r;
        cout<<query(tree,0,0,n-1,l,r)<<endl;
    }
    return 0;
}