//* C++ Program to Implement a Binary Search Tree using Linked Lists
//Inserting element in tree
//Inorder
//Preorder
//Postorder
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
}*root=NULL;
void create()
{
	int value;
	if(root==NULL)
	{
		cout<<"Enter value:\n";
		cin>>value;
		struct node *temp=new node;
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
	}
	else
	{
	    //cout<<"enter next value:\n";
		cin>>value;
		struct node *temp=new node;
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		struct node *p=root;
	while(true)
	{
		if(value<p->data)
		{
			if(p->left==NULL)
			{
				p->left=temp;
				//cout<<"value stored in left of "<<p->data<<"\n";
				break;
			}
			else
			while(p->left!=NULL)
			p=p->left;
		}
		else
		{
			if(p->right==NULL)
			{
				p->right=temp;
				//cout<<"value stored in right of "<<p->data<<"\n";
				break;
			}
			else
			while(p->right!=NULL)
			p=p->right;
		}
	}
  }
}

void Preorder(struct node *t)
{
	if(t)
	{
		cout<<t->data<<" ";
		Preorder(t->left);
		Preorder(t->right);
	}
}

void Inorder(struct node *t)
{
	if(t)
	{
		Inorder(t->left);
		cout<<t->data<<" ";
		Inorder(t->right);
	}
}

void Postorder(struct node *t)
{
	if(t)
	{
		Postorder(t->left);
		Postorder(t->right);
		cout<<t->data<<" ";
	}
}

int main()
{
	int n;
	cout<<"Enter no of elements to be inserted:\n";
	cin>>n;
	while(n--)
	{
		create();
	}
	int choice;
	while(true)
	{
		cout<<"enter choice:\n1.preorder:\n2.inorder\n3.postorder\n";
		cin>>choice;
		switch(choice)
		{
			case 1:Preorder(root);
			    cout<<"\n";
			break;
			case 2:Inorder(root);
			    cout<<"\n";
			break;
			case 3:Postorder(root);
			    cout<<"\n";
			break;
			default:
				cout<<"wrong input\n";
		}
	}
	return 0;
}
