#include<iostream> 
using namespace std;

int find(int d[],int table[],int l[],int x,int n)
{
for(int i=0;i<n;i++)
{
while((x-d[i])>=0 && l[i]>0)
{
x-=d[i];
table[i]+=1;
l[i]-=1;

}
if(x==0)
return 1;
}
return -1;
}
int main()
{
int x,n;
cout<<"Enter x:\n";
cin>>x;
cout<<"Enter no of denominations:\n";
cin>>n;
int *d=(int *)malloc(n*sizeof(int));
int *table=(int *)malloc(n*sizeof(int));
int *l=(int *)malloc(n*sizeof(int));
cout<<"Enter denominations in descending order.\n";
for(int i=0;i<n;i++)
{
cin>>d[i];
cin>>l[i];
table[i]=0;
}

int flag=find(d,table,l,x,n);

if(flag==1)
for(int i=0;i<n;i++)
{
cout<<table[i]<<" ";
}
else
cout<<"Not Possible:\n";

return 0;
}
