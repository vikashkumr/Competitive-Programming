#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *head=NULL;
void insertAtEnd(int x)
{
	//creating node dynamically
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	//initiliasing value
	temp->data=x;
	temp->prev=NULL;
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
		temp->prev=t;
	}
}

void insertAtBegin(int x)
{
	//creating node dynamically
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	//initiliasing value
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		//inserting in the begining
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
}


void insertInBtw(int x)
{
	int value;
	cout<<"enter value after which you want to insert element:\n";
	cin>>value;
	//creating node dynamically
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	//initiliasing value
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		//inserting in between
		struct node *t=head;
		while(t->data!=value)
		  t=t->next;
		temp->next=t->next;
		temp->prev=t;
		t->next=temp;
		temp->next->prev=temp;
	}
}
void view()
{
	if(head==NULL)
	cout<<"No element is present in the linked list";
	else
	{
	struct node *t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
	    t=t->next;
    }
}
    cout<<"\n";
}
int main()
{
	struct node *head=NULL;
	cout<<"enter choice 1(Insert) : 2(View) ?\n";
	while(1)
	{
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1: 
			{
				int ch,x;
				cout<<"1.insert at begining \n2.insert at the end \n3.insert in between\n";
				cin>>ch;
				if(ch==1)
				{
				cout<<"enter element:\n";
				cin>>x;
				insertAtBegin(x);
			    }
			    if(ch==2)
				{
				cout<<"enter element:\n";
				cin>>x;
				insertAtEnd(x);
			    }
			    if(ch==3)
				{
				cout<<"enter element:\n";
				cin>>x;
				insertInBtw(x);
			    }
			}
			break;
			case 2:	view();
			break;
			default:cout<<"wrong input\n";
		}
	}
}
