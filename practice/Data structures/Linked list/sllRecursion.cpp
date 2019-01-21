//print linked list in reverse order using reverse
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
void printReverse(struct node* t)
{
	if(t)
	{
	printReverse(t->next);
	cout<<t->data;
    }
}
int main()
{
	for(int i=1;i<=7;i++)
	insert(i);
	cout<<"\nPrinted Reverse: ";
	printReverse(head);
	return 0;
}
