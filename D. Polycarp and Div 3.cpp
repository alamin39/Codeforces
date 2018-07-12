#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[200002][4],len=0;
string s;

ll calc(ll i,ll rem)
{
    if(i==len)
        return 0;

    if(dp[i][rem]!=-1)
        return dp[i][rem];

    ll x=0,y=0,ans= (rem+(s[i]-'0'))%3;
    if(ans==0)
        x=1+calc(i+1,0);
    else
        x=calc(i+1,ans);

    y = calc(i+1,0);

    return dp[i][rem]=max(x,y);
}

int main()
{
    cin>>s;
    len=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<calc(0,0)<<endl;
    return 0;
}
