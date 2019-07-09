#include<iostream>
#include<cmath>
using namespace std;

//Max heapify
void MaxHeapify(int *arr,int i,int n){
    int l,r,largest;
    l=2*i+1;
    r=2*i+2;
    if(l<=n-1 && *(arr+l) > *(arr+i)){
        largest=l;
    }
    else largest=i;
    if(r<=n-1 && *(arr+r) > *(arr+largest)){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        MaxHeapify(arr,largest,n);
    }
}

//Build max heap
void BuildMaxHeap(int *arr,int n){
    for(int index=floor(n/2);index>=0;index--){
        MaxHeapify(arr,index,n);
    }
}

//Heap extract max
void HeapExtractMax(int *arr,int n){
    int max=arr[0];
    arr[0]=arr[n-1];
    MaxHeapify(arr,0,n-1);
    cout<<"max = "<<max<<" ";
}

//Heap sort
void HeapSort(int *arr, int n){
    BuildMaxHeap(arr,n);
    int temp=n;
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        temp--;
        MaxHeapify(arr,0,temp);
    }
}
int main(){
    int arr[]={1, 14, 10, 8, 7, 9, 3, 2, 4, 6};
    int n=sizeof(arr)/sizeof(int);
    HeapSort(arr,n);
    for(x : arr)
    cout<<x<<" ";
    return 0;
}
