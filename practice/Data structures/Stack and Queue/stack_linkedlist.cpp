//linked list implementatio of stack
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
//function to push the element to the stack
void push(int x)
{
	//creating node dynamically
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	//initiliasing value
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
        head=temp;
    }
	else
	{
		//inserting at the begining
		temp->next=head;
        head=temp;
	}
}
//function to display top element
int peek()
{
	return head->data;
}

//function to popout the last element of stack //first element of linked list
void pop()
{
	struct node *t=head;
    head=head->next;
    delete(t);
}
//driver program
int main(){
    int choice;
    cout<<"choose a option:\n";
    while(1){
    cout<<"1.push\t2.pop\t3.peek\n";
    cin>>choice;
    switch(choice){
        int x;
        case 1: {
            cout<<"enter element to be pushed:\n";
            cin>>x;
            push(x);
        }
        break;
        case 2: pop();
        break;
        case 3: cout<<peek()<<endl;
        break;
        default : {cout<<"wrong input... try again\n";
        exit(0);}
    }
}
    return 0;
}