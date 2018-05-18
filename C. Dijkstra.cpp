#include<bits/stdc++.h>
#define ll long long int
#define max 100002
#define INF 1e18
using namespace std;

vector<ll>G[max];
vector<ll>cost[max];
ll d[max],par[max];

struct data
{
    ll city,dist;
    data(ll a,ll b)
    {
        city = a;
        dist = b;
    }
    bool operator < (const data& p) const
    {
        return dist>p.dist;
    }
};

ll Dijkstra(ll start,ll dest,ll node)
{
    ll i,j,u,v;
    for(i=0; i<=node; i++)
        d[i]=INF;
    priority_queue<data>Q;

    Q.push(data(start,0));
    d[start] =0;

    while(!Q.empty())
    {
        data top = Q.top();
        Q.pop();
        u = top.city;
        if(u==dest)
            return d[dest];
        for(i=0; i<G[u].size(); i++)
        {
            v = G[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v] = d[u]+cost[u][i];
                par[v]=u;
                Q.push(data(v,d[v]));
            }
        }
    }
    return -1;
}

void Path_print(ll src,ll dest)
{
    vector<ll>vv;
    vv.push_back(dest);
    while(src!=dest)
    {
        vv.push_back(par[dest]);
        dest=par[dest];
    }
    for(ll i=vv.size()-1; i>=0; i--)
        cout<<vv[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll node,edge,i,ans=0,x,y,z,start=1,end,cas;
    cin>>node>>edge;
    for(i=0; i<edge; i++)
    {
        cin>>x>>y>>z;
        G[x].push_back(y);
        G[y].push_back(x);

        cost[x].push_back(z);
        cost[y].push_back(z);
    }
    end=node;
    ans= Dijkstra(start,end,node);
    if(ans==-1)
        cout<<-1<<endl;
    else
    {
        // cout<<ans<<endl;
        Path_print(start,end);
    }
    return 0;
}
