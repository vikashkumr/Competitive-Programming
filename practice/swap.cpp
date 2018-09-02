#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
  cout<<" after swap: x= "<<*x<<" y= "<<*y;
}
int main()
{
  int x,y;
  cin>>x>>y;
  cout<<"before swap: x= "<<x<<" y= "<<y;
  swap(&x,&y);
  return 0;
}
