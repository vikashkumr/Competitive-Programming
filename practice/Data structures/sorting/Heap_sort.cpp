//c++ programme to sort elements of array using heap data structure
#include<bits/stdc++.h>
using namespace std;
void max_Heapyfy(int A[],int size,int i)
{
	int l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if(A[l]>A[i] && l<=size)
	largest=l;
	else
	largest=i;
	if(A[r]>A[largest] && r<=size)
	largest=r;
	if(largest!=i)
	{
	swap(A[largest],A[i]);
	max_Heapyfy(A,size,largest);
}
}

//Heap sort
void Heap_Sort(int A[],int n)
{
	//building max heap
	for(int i=floor(n/2)-1;i>=0;i--)
	max_Heapyfy(A,n,i);
	//--------------------------
	for(int i=n-1;i>=0;i--)
	{
		swap(A[0],A[i]);
		max_Heapyfy(A,i-1,0);
	}
}

int main()
{
	int n;
	cout<<"enter no of element of heap:\n";
	cin>>n;
	int A[n];
	cout<<"enter "<<n<<" elements:\n";
	for(int i=0;i<n;i++)
	cin>>A[i];
	Heap_Sort(A,n);
	cout<<"sorted elsements:"
	for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
	return 0;
}
