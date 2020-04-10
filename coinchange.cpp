#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
 int flag=1;
  
int minCoins(int coins[], int m, int v,int change[]) 
{ 
    // table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result 
    int table[v+1]; 
  
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
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  {
                  	table[i] = sub_res + 1;
                  	change[i]=coins[j];
				  }
          } 
		 }
		  
    } 
    //cout<<table[V-9]<<" ";
    if(table[v]!=INT_MAX)
    	return table[v]; 
    else 
    {
    	flag=0;
    	return 0;
    }	
} 
  
// Driver program to test above function 
int main() 
{ 
    	int m,v;
    	cout<<"Enter the number of denominations: ";
    	cin>>m;
   		int coins[m];
    	cout<<"Enter the denominations : ";
    	for(int i=0;i<m;i++)
    	cin>>coins[i];
    	
		cout<<"Enter the number to get change :";
    	cin>>v;
    	int change[v+1];
    	change[0]=0;
    	cout << "Minimum coins required is : "<< minCoins(coins,m,v,change); 
		if(flag!=0)
		{		
			int count[m];
			for(int i=0;i<m;i++)
				count[i]=0;
			cout<<"\nThe change is :";  
			int x=v;		
			while(x>0)
			{
				//cout<<change[x]<<" ";
				for(int i=0;i<m;i++)
				{
					if(change[x]==coins[i])
					count[i]++;
				}
				x=x-change[x];
			}
		
			for(int i=0;i<m;i++)
				cout<<"\n"<<coins[i]<<" -> "<<count[i];
		}
		return 0; 
}
