#include<iostream> 
using namespace std;

int max(int a, int b) { return (a > b)? a : b; } 

int knapSack(int W, int wt[], int v[], int n) 
{ 
 int i, w; 
 int K[n+1][W+1]; 

 for (i=0;i<=n;i++) 
 { 
	for (w=0;w<=W;w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if(wt[i-1] <= w) 
			K[i][w] = max(v[i-1]+K[i-1][w-wt[i-1]] , K[i-1][w]); 
		else
			K[i][w] = K[i-1][w]; 
	} 
 } 
return K[n][W]; 
} 

int main() 
{ 
	int n;
	cout<<"\nEnter the no. of objects: ";
	cin>>n;
	int v[n],wt[n];
	cout<<"\nEnter the profit and weight correspondingly: ";
	for(int i =0;i<n;i++)
		cin>>v[i]>>wt[i];
	int W;
	cout<<"\nEnter the capacity: ";
	cin>>W;
	cout<<"Max profit: "<<knapSack(W, wt, v, n); 
	return 0; 
} 

