/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,k,n;
int arr [10005];
int memo[10005][21][21];
int solve(int i , int j, int k1, int k2)
{
    if(i>= j)
    {
        return 0;
    }
    if(k1 +k2 > k) return 50;
    int &ret = memo[i][k1][k2];
    if(ret != -1) return memo[i][k1][k2];
    ret = 10000000;
    if(arr[i] != arr[j])
    {
       ret = min(ret, (solve(i+1, j,k1,k2+1)+1));
       ret = min(ret, (solve(i, j-1,k1+1 ,k2)+1));
    }else
    {
        ret = min(ret, solve(i+1, j-1,k1,k2));
    }
    return ret;
}
int main()
{
    //cin>>t;
    scanf("%d",&t);
    int dod =1;
    while(t--)
    {
        memset(memo,-1,sizeof(memo));
      //cin>>n>>k;
      scanf("%d %d", &n,&k);
      for(int i =0; i<n; i++)
      {
        //cin>>arr[i];
        scanf("%d",&arr[i]);
      }
      int  res  = solve(0,n-1,0,0);
      if(res == 0)
      {
          cout<<"Case "<<dod++ <<": "<<"Too easy"<<endl; 
      }else if(res > k)
      {
          cout<<"Case "<<dod++ <<": "<<"Too difficult"<<endl; 
      }else
      {
        cout<<"Case "<<dod++ <<": "<<res<<endl;  
      }
    }
    return 0;
}
