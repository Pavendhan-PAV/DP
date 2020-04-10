#include<iostream>
#include<stdlib.h> 
#include<climits>
using namespace std; 

#define INF INT_MAX 

void All_Pair_SPath(int graph[][20],int n);

int main() 
{ 
	int n,i,u,v,w,e,g[20][20];
	char c;
	cout<<"Is the graph directed?(y/n): ";
	cin>>c;
	
	cout<<"Enter number of vertices and edges: ";
	cin>>n>>e; 
	
	for(u=0;u<n;u++)
		for(v=0;v<n;v++)
			if(u!=v)
				g[u][v]=INF;
			else
				g[u][v]=0;
			
	cout<<"Enter the edges present and their weights(for an edge between 0 and 1 with weight 2 enter 0 1 2):\n";
	for(i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		if(c=='y' || c=='Y')
			g[u][v]=w;
		else
			g[u][v]=g[v][u]=w;
	}

	All_Pair_SPath(g,n); 
	return 0; 
} 

void All_Pair_SPath(int graph[][20],int n) 
{ 
	int dist[20][20], i, j, k; 
	
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			dist[i][j] = graph[i][j]; 

	for (k = 0; k < n; k++) 
	{  
		for (i = 0; i < n; i++) 
		{  
			for (j = 0; j < n; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n";
	cout<<" 	 ";
	for (int i = 0; i < n; i++) 
		cout<<i<<"	 ";
	cout<<endl;
		 
	for (int i = 0; i < n; i++) 
	{ 
		cout<<i<<"	 ";
		for (int j = 0; j < n; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"-"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	}  
} 

