/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,i=1;
    cin>>t;
    vector<pair<ll,ll> > vec;
    while(t--)
    {
        cin>>n;
        vec.push_back({1,n});
        for(ll i =2; i*i<n; i++)
        {
            if(n%i == 0)
            vec.push_back({n/i,i});
        }
        int sz = vec.size();
        printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n",i,n,vec[sz-1].first,vec[sz-1].second,vec[sz-2].first,vec[sz-2].second);
        i++;
        vec.clear();
    }

    return 0;
}
