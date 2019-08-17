//program to find median of two sorted arrays
//Time complexity O(n)
//Divide and conquer

#include<bits/stdc++.h>
using namespace std;
float getMedian(int *arr,int s,int e){
    // cout<<"s="<<s<<"e="<<e<<"\n";
    if((e-s+1)&1){
        return (float) arr[(e+s)/2];
    }
    int temp1 = (e+s)/2;
    int temp2 = temp1+1;
    return (float) (arr[temp1]+arr[temp2])/2;
}
float findMedian(int *arr1,int *arr2,int s1, int e1, int s2, int e2){
    //base cases

    if((e1-s1)==1 && (e2-s2)==1)
    return (float) (max(arr1[s1],arr2[s2])+min(arr1[e1],arr2[e2]))/2;
    if(e1==s1 && e2==s2)
    return (float) (arr1[e1]+arr2[e2])/2;
    if((e1-s1)<1 || (e2-s2)<1){
        cout<<"wrong Input"<<"\n";
        return 0;
    }

    //recursive case

    int m1 = getMedian(arr1,s1,e1);
    int m2 = getMedian(arr2,s2,e2);
    if(m1==m2) return m1;
    if(m1<m2){
        s1 = (e1+s1)/2;
        e2 =(e2+s2+1)/2; 
         findMedian(arr1,arr2,s1,e1,s2,e2);
    }
    else if(m1>m2){
        e1 = (e1+s1+1)/2;
        s2 =(e2+s2)/2; 
         findMedian(arr1,arr2,s1,e1,s2,e2);
    }
}
int main(){
    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6,8};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int s1=0,e1=size-1,s2=0,e2=size-1;
    cout<<findMedian(arr1,arr2,s1,e1,s2,e2)<<"\n";
    return 0;
}