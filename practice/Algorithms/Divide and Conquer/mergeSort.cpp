#include<bits/stdc++.h>
using namespace std;
void merge(int A[],int p,int q,int r)
{
	int i,j,n1,n2;
	n1=q-p+1;
	n2=r-q;
	int L[n1+1],R[n2+1];
	for(i=1;i<=n1;i++)
	L[i]=A[p+i-1];
	for(j=1;j<=n2;j++)
	R[j]=A[q+j];
	L[n1+1]=100000000;
	R[n2+1]=100000000;
	i=1;j=1;
	for(int k=p;k<=r;k++)
	{
	    if(L[i]<=R[j])
		{
		A[k]=L[i];
		i=i+1;
	    }
	    else
	    {
	    	A[k]=R[j];
	    	j=j+1;
		}
	}
}
void merge_sort(int A[],int p,int r)
{
	int q=(p+r)/2;
	if(p<r)
	{
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}
int main()
{
	int n;
	printf("enter size of array:\n");
	cin>>n;
	int A[n];
	for(int i=1;i<=n;i++)
	cin>>A[i];
	merge_sort(A,1,n);
	for(int j=1;j<=n;j++)
	cout<<A[j]<<" ";
	return 0;
}
