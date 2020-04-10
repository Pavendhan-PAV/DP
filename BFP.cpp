#include<iostream>
#include<stdlib.h>
#include<climits>

using namespace std;

#define inf INT_MAX


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

struct graph *create(int x,int y)
{
struct graph* g=new graph;
g->n1=x;
g->n2=y;
g->e=new edge[y];
return g;
} ;


void Bellman(struct graph *g,int source)
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



cout<<"Distance from source vertex :"<<source<<" to vertex:\n" ;
for(int i=0;i<N;i++)
{
cout<<i<<":"<<distance[i]<<" ";
}



}
int main()
{
int N = 5; //Vertices
    int E = 8; // Edged
    struct graph* g = create(N, E); 
  
 //enter in this format
    g->e[0].u = 0; 
    g->e[0].v = 1; 
    g->e[0].weight = -1; 
  
    
    g->e[1].u = 0; 
    g->e[1].v = 2;
    g->e[1].weight = 4; 
  
    
    g->e[2].u = 1; 
    g->e[2].v = 2; 
    g->e[2].weight = 3; 
  
 
    g->e[3].u = 1; 
    g->e[3].v = 3; 
    g->e[3].weight = 2; 
  
    
    g->e[4].u = 1; 
    g->e[4].v = 4; 
    g->e[4].weight = 2; 
  
    
    g->e[5].u = 3; 
    g->e[5].v = 2; 
    g->e[5].weight = 5; 
  
  
    g->e[6].u = 3; 
    g->e[6].v = 1; 
    g->e[6].weight = 1; 
  
 
    g->e[7].u = 4; 
    g->e[7].v = 3; 
    g->e[7].weight = -3; 
  

   
Bellman(g, 0); 
  
    return 0; 
}

