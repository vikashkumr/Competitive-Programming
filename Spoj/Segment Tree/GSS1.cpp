#include<bits/stdc++.h>
#define ll long long
#define MAX 100001
using namespace std;
class Node {
    public:
    int left,right;
    int totalSum,bestSum;
};
void buildTree(Node *tree, int *arr, int index, int s, int e){
    if(s==e){
        tree[index].left = arr[s];
        tree[index].right = arr[s];
        tree[index].totalSum = arr[s];
        tree[index].bestSum = arr[s];
        return;
    }
    //recursive case
    int mid = (s+e)/2;
    //build Left sub tree
    buildTree(tree,arr,2*index+1,s,mid);
    //build Right sub tree
    buildTree(tree,arr,2*index+2,mid+1,e);
    Node l = tree[2*index+1];
    Node r = tree[2*index+2];
    tree[index].totalSum = l.totalSum+r.totalSum;
    tree[index].left = max(l.left,l.totalSum+r.left);
    tree[index].right = max(r.right,r.totalSum+l.right);
    tree[index].bestSum = 
    max(tree[index].left,
        max(tree[index].right,
          max(l.bestSum,
            max(r.bestSum,l.right+r.left))));
}
 
 
Node query(Node *tree, int index, int s, int e, int l, int r){
    Node result;
    result.bestSum=result.left=INT_MIN;
    result.right=result.totalSum=INT_MIN;
    //No overlap
    if(r<s || l>e){                
        return result;        
    }
 
    //complete overlap
    if(s>=l && e<=r){
        return tree[index];
    }
 
    //partial overlap-call both side
    int mid = (s+e)/2;
    if(l>mid)
        return query(tree,2*index+2,mid+1,e,l,r);
   if(r<=mid)
        return query(tree,2*index+1, s, mid, l, r);
    Node leftAns = query(tree,2*index+1,s,mid,l,r);
    Node rightAns = query(tree,2*index+2,mid+1,e,l,r);
 
    result.totalSum = leftAns.totalSum + rightAns.totalSum;
   result.left = 
      max(leftAns.left, leftAns.totalSum + rightAns.left);
   result.right = 
      max(rightAns.right, rightAns.totalSum + leftAns.right);
   result.bestSum = 
      max(result.left, 
         max(result.right, 
            max(leftAns.bestSum, 
               max(rightAns.bestSum,
                  leftAns.right + rightAns.left))));
   return result;
 
}
 
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    Node *tree = new Node[4*n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(tree,arr,0,0,n-1);
    int n_of_q,l,r;
    cin>>n_of_q;
    while (n_of_q--){
        cin>>l>>r;
        cout<<query(tree,0,0,n-1,l-1,r-1).bestSum<<endl;
    }
    return 0;
} 