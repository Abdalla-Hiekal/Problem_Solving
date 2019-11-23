/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll memo[1001][1001];
vector<ll> vec;
ll mid;
ll solve(ll i, ll j)
{
    if(i>=j) return 0;
    ll &ret = memo[i][j];
    if(ret != -1)
    {
        return ret;
    }
    if(s[i] != s[j])
    {
        ret = min((solve(i,j-1)+1),(solve(i+1,j)+1));
    }else
    {
        ret = solve(i+1,j-1);
    }
    return ret;
}
void output(ll i, ll j)
{
    if(i == j){ mid =1; vec.push_back(i);}
    if(i>= j) return;
    if(s[i] == s[j])
    {
        vec.push_back(i);
        output(i+1, j-1);
    }
    else
    {
        if(solve(i+1,j)+1 == solve(i,j))
        {
            vec.push_back(i);
            output(i+1,j);
        }else
        {
            vec.push_back(j);
            output(i,j-1);
        }
    }
}
int main()
{
    while(cin>>s)
    {
        mid= 0;
        vec.clear();
        memset(memo,-1,sizeof(memo));
        ll res  = solve(0,s.length()-1);
        
        output(0,s.length()-1);
        
        // output
        cout<<res<<" ";
        for(int i =0; i<vec.size(); i++) cout<<s[vec[i]];
        for(int i =vec.size()-1-mid; i>= 0; i--) cout<<s[vec[i]];
        cout<<endl;
    }
    return 0;
}
