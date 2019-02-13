//Recursive program to reverse a singly linked  list
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
//recursion to reverse the linked list
void reverse(struct node* prev,struct node* curr)
{
    if(curr){
        reverse(curr,curr->next);
        curr->next=prev;
    }
    else{
        head=prev;
    }
    
}
//print function
void print(struct node *t){
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
}
//driver program
int main()
{
	for(int i=1;i<=5;i++)
	insert(i);
	reverse(NULL,head);
    //prints linked list because above head has updates and linked list has been reversed
    print(head);
	return 0;
}