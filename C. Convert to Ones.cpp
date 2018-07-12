///Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,k,n,m,t,sum=0,ans=0;
    bool f=0,flag=0;
    string s,a=""; ll x,y;

    cin>>n>>x>>y;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0' || s[i]=='1')
        {
            a+=s[i];i++;
            while(s[i-1]==s[i])
            {
                i++;
            }
            i--;
        }
    }
   // cout<<a<<endl;

    if(a.size()==1 && a[0]=='1')
        cout<<0<<endl;
    else
    {
        ans=1e18;ll cnt=0,c=0;
        for(i=0;i<a.size();i++)
        {
            if(a[i]=='0')
                cnt++;
//            if(i<a.size()-1&&a[i]=='0'&&a[i+1]=='1')
//            {
//                c++;
//            }
        }
        ans=min(ans,cnt*y);
        ans=min(ans,((cnt-1)*x)+y);
        cout<<ans<<endl;
    }

    return 0;
}
