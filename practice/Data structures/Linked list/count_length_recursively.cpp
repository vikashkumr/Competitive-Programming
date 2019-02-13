//Recursive program to count length of linked list
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert(int x)
{
	//creating node dynamically
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	//initiliasing value
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		//inserting at the end
		struct node *t=head;
		while(t->next!=NULL)
		  t=t->next;
		t->next=temp;
	}
}
//recursion to find length of linked list
int countLength(struct node* t,int cnt)
{
	if(t)
	{
	 return countLength(t->next,cnt+1);
    }
    return cnt;
}
//driver program
int main()
{
	for(int i=1;i<=7;i++)
	insert(i);
	cout<<"\nLength of the linked list is: ";
	cout<<countLength(head,0);
	return 0;
}