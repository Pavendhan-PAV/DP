#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
 int flag=1;
  
int minCoins(int coins[], int m, int v,int change[][1000],int l[],int table[]) 
{ 
    // table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result  
  	change[0][0]=0;
    int k;
    table[0] = 0; 
  
    for (int i=1; i<=v; i++) 
        table[i] = INT_MAX; 
  
    for (int i=1; i<=v; i++) 
    { 
        // Go through all coins smaller than i 
        for (int j=0; j<m; j++) 
         {
         	if (coins[j] <= i) 	
            { 
            	int c=0;
            	if(table[i-coins[j]] != INT_MAX)
            		for(int k=0;k<table[i-coins[j]];k++)
            		{
            			if(change[i-coins[j]][k]==coins[j])
            				c++;
            		}
            		//cout<<"hhhh"<<i<<"---"<<coins[j]<<"...."<<c<<"\n";
            	if(c<l[j])
            	{	
              		int sub_res = table[i-coins[j]]; 
              		if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
             	    {
                		table[i] = sub_res + 1;
                		//cout<<"\n--"<<i<<"--"<<j<<"--"<<table[i];
                		for(k=0;k<table[i]-1;k++)
                			change[i][k]=change[i-coins[j]][k];
                	  	change[i][k]=coins[j];
                	  //	cout<<"\n--=="<<i<<"=--"<<change[i];
					}
            	}
            } 
		 }
		  
    } 
    if(table[v]!=INT_MAX)
    	return table[v]; 
    else 
    {
    	flag=0;
    	return 0;
    }	
} 
  
int main() 
{ 
    	int m,v;
    	cout<<"Enter the number of denominations: ";
    	cin>>m;
   		int l[m],coins[m],count[m];
    	cout<<"Enter the denominations and it's limit : ";
    	for(int i=0;i<m;i++)
    	{
    		cin>>coins[i];
    		cin>>l[i];
		}    	
		cout<<"Enter the number to get change :";
    	cin>>v;
		int change[v+1][1000];
		 int table[v+1];
    	cout << "Minimum coins required is : "<< minCoins(coins,m,v,change,l,table); 
		if(flag!=0)
		{		
			
			for(int i=0;i<m;i++)
				count[i]=0;
			cout<<"\nThe change is :";  
			
			for(int i=0;i<table[v];i++)
			{
				for(int k=0;k<m;k++)
				{
					if(change[v][i]==coins[k])
						count[k]++;
		  		} 
			}
		}
		for(int i=0;i<m;i++)
			cout<<"\n"<<coins[i]<<" -> "<<count[i];
		return 0; 
}
