#include<iostream>

using namespace std;
struct matrix
{
int row;
int column;
char name;
};

int findmin(struct matrix m[],int n)
{
int min,index;
min=m[0].row*m[0].column*m[1].column;

index=0;
for(int i=1;i<n-1;i++)
{
int x=m[i].row*m[i].column*m[i+1].column;

if(x<min)
{
min=x;
index=i;
}


}
return index;
}
int dandi(int index,struct matrix m[],int n)
{
int calc=m[index].row*m[index].column*m[index+1].column;
m[index].column=m[index+1].column;
for(int i=index+1;i<n;i++)
{
m[i].row=m[i+1].row;
m[i].column=m[i+1].column;

}
return calc;
}
void mf(struct matrix m[],int &n)
{int calc=0;
int count=1;
int size=n;

while(count<size)
{

int index=findmin(m,n);
calc+=dandi(index,m,n);
cout<<calc<<"\n";
count++;
n--;






}
cout<<"Total minimum calculations required:"<<calc;;
}
int main()
{
int n;
cout<<"Enter no of matrices:"<<"\n";
cin>>n;
struct matrix m[n];
cout<<"Enter matrix row and column:"<<"\n";
for(int i=0;i<n;i++)
{
cout<<"Enter matrix "<<i+1<<"row:"<<"\n";
cin>>m[i].row;
cout<<"Enter matrix"<<i+1<<" column:"<<"\n";
cin>>m[i].column;
}
mf(m,n);
//cout<<"Element row:"<<m[0].row<<"Element column:"<<m[0].column;
return 0;
}
