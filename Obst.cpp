/*Given Sequence k=k1< k2 < …….kn of n sorted keys, with a search probability pi for
each key ki . Build the Binary search tree that has the least search cost given the access
probability for each key?*/
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};



int find(int c[5][5], int i, int j)
{
	int min=999;
	int l,k,cost;

	for(k=i;k<=j;k++)
	{
		cost=c[i][k-1]+c[k+1][j];
		if(cost<min)
		{
			min=cost;
			l=k;
		}
	}
	return l;
}

node *optimal(int p[10],int q[10],int n)
{
	int w[5][5],c[5][5],r[5][5],i,j,k;
	node *root;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			c[i][j]=w[i][j]=r[i][j]=0;
	for(i=1;i<=n;i++)
	{
		w[i][i]=q[i-1]+q[i]+p[i];
		c[i][i]=w[i][i];
		r[i][i]=i;
	}
	
	for(int step=2;step<=n;step++)
	{
		for(i=1;i<=n-step+1;i++)
		{
			j=i+step-1;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			k=find(c,i,j);
			c[i][j]=w[i][j]+c[i][k-1]+c[k+1][j];
			r[i][j]=k;
		}
	}
	//root=construct(r,1,n);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			cout<<"\nValue for "<<i<<j<<" = "<<w[i][j];
			cout<<"\nValue for cost "<<i<<j<<" = "<<c[i][j];
			cout<<"\nValue for root "<<i<<j<<" = "<<r[i][j];
		}
	
	return root;
}




void display(int n,int w[5][5],int c[5][5], int r[5][5])
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			cout<<"Value for"<<w[i][j];
			cout<<"Value for cost: "<<c[i][j];
			cout<<"Value for root: "<<r[i][j];
		}
}

int main()
{
	int p[10],q[10],i,n;
	node *root=NULL;
	char wrd[5][10];
	cout<<"Enter the number of words: ";
	cin>>n;
	cout<<"Enter the words: ";
	for(i=1;i<=n;i++)
	{
		
		cin>>wrd[i];
	}
	cout<<"Enter the number of successfull probability p: ";
	for(i=1;i<=n;i++)
	{
		
		cin>>p[i];
	}
	cout<<"Enter the number of unsuccessfull probability q: ";
	for(i=0;i<=n;i++)
	{
		
		cin>>q[i];
	}
	
	root=optimal(p,q,n);
	
	//disp(root);
	
	
	return 0;
}
