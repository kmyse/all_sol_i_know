#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define getbit(x,i) (((x)>>(i))&1ULL)
#define biton(x,i) ((x)(1ULL<<(i)))
#define bitoff(x,i) ((x)&(~(1ULL<<(i))))
#define flipbit(x,i) ((x)^(1ULL<<(i)))
#define umpll unordered_map<ll,ll>
#define umpstr unordered_map<string,ll>
#define mppii map<pii,ll>
#define f(n,st,k) for(ll i=(st);i<=(n);i+=(k))
#define rf(n,st,k) for(ll i=(st);i>=(n);i-=(k))
using namespace std;
struct edge
{
    ll v,w;
};
struct ver
{
    ll u,d;
};
struct cmp
{
    bool operator()(ver a,ver b)
    {
        return a.d>b.d;
    }
};
ll d[1000005],trace[1000005];
bool check[1000005];
vector<edge>vt[1000005];
vector<ll>empt(0);
ll dijkstra(ll s,ll n)
{
    fill(d,d+n+1,1e15);
    fill(trace,trace+n+1,-1);
    fill(check,check+n+1,0);
    bool b=0;
    d[s]=0;
    priority_queue<ver,vector<ver>,cmp>pq;
    pq.push({s,d[s]});
    while(!pq.empty())
    {
        ver k=pq.top();
        pq.pop();
        ll u=k.u;
        if(u==s&&b)
            return d[s];
        if(k.d>d[u])
            continue;
        for(auto e:vt[u])
        {
            ll v=e.v,w=e.w;
            if(d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({v,d[v]});
                trace[v]=u;
            }
        }
        if(u==s&&!b)
        {
            d[s]=1e18;
            b=1;
        }
    }
    return -1;
}
vector<ll>trace_path(ll s, ll u)
{
    vector<ll>path;
    if (d[u]==1e15)
    {
        return path;
    }
    while(u!=s)
    {
        path.push_back(u);
        u=trace[u];
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(".inp","r"))
    {
        freopen(".inp","r",stdin);
        freopen(".out","w",stdout);
    }
    ll n,m,k;
    cin>>k;
    while(k--)
    {
        cin>>n>>m;
        for(ll i=1;i<=n;i++)
             vt[i].clear();
        for(ll i=1;i<=m;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            vt[u].push_back({v,w});
        }
        for(ll i=1;i<=n;i++)
            cout<<dijkstra(i,n)<<'\n';
    }

}
