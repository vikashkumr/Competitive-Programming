//Deltion of node in a binary tree
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
struct node *findMax(struct node *p)
{
	while(p->right)
	p=p->right;
	return p;
}

struct node *Delete(struct node *p,int x)
{
	struct node *temp,*temp1;
	if(p==NULL)
	cout<<"No such element is present in the tree:\n";
	else if(x<p->data)
	p->left=Delete(p->left,x);
	else if(x>p->data)
	p->right=Delete(p->right,x);
	else
	{
		if(p->left && p->right)
		{
			temp=findMax(p->left);
			p->data=temp->data;
			p->left=Delete(p->left,p->data);
		}
		else
		{
			temp1=p;
			if(!p->left)
			p=p->right;
			if(!p->right)
			p=p->left;
			delete(temp1);
		}
		cout<<"item deleted:\n";
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


int main()
{
	int n,x,choice;
	cout<<"Enter no of elsements to be inserted:\n";
	cin>>n;
	while(n--)
	create();
	while(1)
	{
	cout<<"1.delete:\n2.traverse:\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
	cout<<"enter the element you want to delete:\n";
	cin>>x;
	Delete(root,x);
	break;
	case 2:
	{
	Inorder(root);
	cout<<"\n";
}
	break;
	default:
	cout<<"wrong input:\n";
	}
}
	return 0;
}
