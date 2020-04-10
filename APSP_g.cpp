#include<iostream>
#include<stdlib.h>
#include<climits>

using namespace std;

#define inf INT_MAX

int N; //Vertices
int E; // Edges

struct edge
{
int u;
int v;
int weight;
};

struct graph
{
int n1;
int n2;

struct edge* e;
};

struct graph *create(int x,int y);
void Bellman(struct graph *g,int source,int dist[20][20]);

int main()
{
     cout<<"Enter number of vertices and edges: ";
	cin>>N>>E;
    char c;
    cout<<"Is the graph directed?(y/n): ";
    cin>>c;
    
    if(c=='n' || c=='N')
    	E=2*E;
    	 
    struct graph* g = create(N, E); 
    int dist[20][20];
			
	cout<<"Enter the edges present and their weights(for an edge between 0 and 1 with weight 2 enter 0 1 2):\n";
	for(int i=0;i<E;i++)
	{
	        cin>>g->e[i].u>>g->e[i].v>>g->e[i].weight;
	        if(c=='n' || c=='N')
	        {
	        	i++;
	        	g->e[i].u=g->e[i-1].v;
	        	g->e[i].v=g->e[i-1].u;
	        	g->e[i].weight=g->e[i-1].weight;
	        } 
	 }
  
    for(int i=0;i<N;i++)
    	for(int j=0;j<N;j++)
    		dist[i][j]=inf;
    		   
    for(int i=0;i<N;i++)
    	Bellman(g,i,dist);
    
    cout<<" 	";
    for(int i=0;i<N;i++)
    	cout<<i<<" 	";
    cout<<endl;
    
    for(int i=0;i<N;i++)
    {
    	cout<<i<<" 	";
    	for(int j=0;j<N;j++)
    	{	
    		if(dist[i][j]==inf)
    			cout<<"-	";
    		else
    			cout<<dist[i][j]<<"	";
    	}
    	cout<<endl;
    }
  
    return 0; 
}

struct graph *create(int x,int y)
{
struct graph* g=new graph;
g->n1=x;
g->n2=y;
g->e=new edge[y];
return g;
} 

void Bellman(struct graph *g,int source,int dist[20][20])
{

int N=g->n1;
int E=g->n2;

int distance[N];

for(int i=0;i<N;i++)
{
distance[i]=inf;

}
distance[source]=0;


for(int i=0;i<N-1;i++)
{
for(int j=0;j<E;j++)
{
int from =g->e[j].u;
int to=g->e[j].v;
int w=g->e[j].weight;

if(distance[from]!=inf && distance[to]>distance[from]+w)
distance[to]=distance[from]+w;

}
}


for(int i=0;i<N-1;i++)
{
for(int j=0;j<E;j++)
{
int from =g->e[j].u;
int to=g->e[j].v;
int w=g->e[j].weight;

if(distance[from]!=inf && distance[to]>distance[from]+w)
{
cout<<"\n Negative cycle found:";
return ;
}
}
}

for(int i=0;i<N;i++)
	dist[source][i]=distance[i];
}


