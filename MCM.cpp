#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int M[100][100],S[100][100];

int MCM(int n,int p[])
{
	int j,q;
	for(int i=1;i<=n;i++)
		M[i][i]=0;
	for(int l=2;l<=n;l++)
		for(int i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			M[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				q=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<M[i][j])
				{
					M[i][j]=q;
					S[i][j]=k;
				}	
			}
		}
	return M[1][n];
}

int main()
{
e	int n;
	cout<<"\nEnter number of matrices: ";
	cin>>n;
	int p[n+1];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the indices of matrix "<<i+1<<" : ";
		cin>>p[i]>>p[i+1];
	}
	int x=MCM(n,p);
	cout<<"\nThe minimum number of calculations required are : "<<x;
	getchar();
}
