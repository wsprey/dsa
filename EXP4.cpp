#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node*r;
	Node*l;
	Node(int val)
	{
		data=val;
		r=NULL;
		l=NULL;
	}
};

void insert(Node*&root,int n)
{
	char ans;
	int count;
	Node*t1=root;
	Node*temp=new Node(n);
	if(root==NULL)
	{
		root=temp;
	}
	else{
		while(true)
		{
			if(temp->data<root->data)
			{
				if(root->l==NULL)
				{
					root->l=temp;
					break;
				}
				else
				{
					root=root->l;
				}
			}
			else
			{
				if(root->r==NULL)
				{
					root->r=temp;
					break;
				}
				else
				{
					root=root->r;
				}
			}
		}
		root=t1;
    }

}

void search(Node*root,int n)
{
	int count=1;
	if(root==NULL)
	{
		cout<<"Element Not Found "<<endl;
	}
	else if(n>root->data)
	{
		root=root->r;
	}
	else if(n<root->data)
	{
		root=root->l;
	}
	else if(n==root->data)
	{
		cout<<"Element Found at "<<count<<endl;
	}
	count++;
}

int min(Node*root)
{ 
while(root->l)
{
	root=root->l;
}
	return root->data;
}

void mirror(Node*root)
{
	Node*temp=root;
	if(root!=NULL)
	{
		mirror(root->l);
		mirror(root->r);
		temp=root->l;
		root->l=root->r;
		root->r=temp;
	}
}

int height(Node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(height(root->r)>height(root->l))
		{
			return (1+height(root->r));
		}
		else
			return (1+height(root->l));
	}
}

void display(Node*root)
{
	stack<Node*>st;
	Node*curr=root;
	while(curr !=NULL || !st.empty()){
	while(curr !=NULL)
	{
		st.push(curr);
		curr=curr->l;
	}
	curr=st.top();
	st.pop();
	cout<<curr->data<<",";
	curr=curr->r;
}
	cout<<endl;
}

int main(){
    Node* root=NULL;
    while(true){
        cout<<"\n\n1. Insert Element"<<endl;
        cout<<"2. Search Element"<<endl;
        cout<<"3. Find Smallest Element"<<endl;
        cout<<"4. Print Height of the tree"<<endl;
        cout<<"5. Mirror tree"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        int n;
        cin>>n;
       if(n==1){
            cout<<"Enter the value to be added to the tree: "<<endl;
            int num;
            cin>>num;
            insert(root,num);
            cout<<" Values in the tree are: "<<endl;
            display(root);
        }
        else if(n==2){
            cout<<"Enter value to be searched: "<<endl;
            int num;
            cin>>num;
            search(root,num);
        }
        else if(n==3){
            cout<<"The smallest element in the tree is: "<<min(root)<<endl;
        }
       else if(n==4){
            cout<<"Height of the tree is: "<<height(root)<<endl;
        }
        else if(n==5){
            mirror(root);
            cout<<"Mirrored tree is: ";
            display(root);
        }
        else{
            break;
        }
    }

}
