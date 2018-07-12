///Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll rem[3]={0};
void clr()
{
    rem[0]=rem[1]=rem[2]=0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,k,n,m,t,sum=0,ans=0;
    string s;

    cin>>s;
    for(i=0;i<s.size();i++)
    {
        ans=(ans+(s[i]-'0'))%3;
        if(ans%3==0)
        {
            sum++;
            clr();
            ans=0;
        }
        else if(rem[ans])
        {
            sum++;
            clr();ans=0;
        }
        else
            rem[ans]=1;
    }
    cout<<sum<<endl;
    return 0;
}
