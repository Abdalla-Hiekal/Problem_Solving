/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int memo[1002][1002];
int solve(int i, int j)
{
    if(i>= j)
    {
        return 0;
    }
    int &ret = memo[i][j];
    if(ret != -1) return memo[i][j];
    ret = 1000000;
    if(s[i] != s[j])
    {
     ret  = min(ret, solve(i+1,j)+1);
     ret  = min(ret, solve(i,j-1)+1);
     ret  = min(ret,solve(i+1,j-1)+1);
     return ret;
    }
    return ret = solve(i+1,j-1);
    
}
int main()
{
    int t,i=1;;
    cin>>t;
    while(t--)
    {
        memset(memo,-1, sizeof(memo));
        cin>>s;
        int  minn = solve(0,(s.length()-1));
        cout<<"Case "<<i++<<": "<<minn<<endl;
    }
    return 0;
}
