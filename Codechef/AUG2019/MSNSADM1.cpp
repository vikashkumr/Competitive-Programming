#include<iostream>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      int A[n],B[n],ans[n]={0};
      for(int i=0;i<n;i++)
      cin>>A[i];
      for(int i=0;i<n;i++)
      cin>>B[i];
      for(int i=0;i<n;i++)
      ans[i]=max(20*A[i]-10*B[i],0);
      int max=0;
      for(int i=0;i<n;i++){
         if(ans[i]>max)
         max=ans[i];
      }
      cout<<max<<"\n";
   }
}
