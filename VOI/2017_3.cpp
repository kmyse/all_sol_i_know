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
ll p[200005],h[200005],pr[200005],check[200005],res=0;
vector<pii>vt[200005];
struct dpar
{
    ll minv=1000000000,maxv=-1000000000,par;
};
struct edge
{
    ll u,v,w,idx;
};
vector<edge>e;
void make_set(ll n)
{
    for(ll i=1;i<=n;i++)
        pr[i]=-1;
}
ll find_set(ll x)
{
    if(pr[x]<0)
        return x;
    pr[x]=find_set(pr[x]);
    return pr[x];
}
bool union_set(ll a,ll b)
{
    ll a0=find_set(a),b0=find_set(b);
    if(a0!=b0)
    {
        if(pr[a0]>pr[b0])
            swap(a0,b0);
        pr[a0]+=pr[b0];
        pr[b0]=a0;
        return true;
    }
    return false;
}
bool cmp(edge a,edge b)
{
    return a.w>b.w;
}
dpar bin_anc[200005][18];
void dfs(ll u)
{
    for(auto v:vt[u])
    {
        if(v.fi==p[u])
            continue;
        p[v.fi]=u;
        bin_anc[v.fi][0].minv=bin_anc[v.fi][0].maxv=v.se;
        h[v.fi]=h[u]+1;
        dfs(v.fi);
    }
}
void pre_lift(ll n)
{
    for(ll i=1;i<=n;i++)
        bin_anc[i][0].par=p[i];
    for(ll j=1;j<=17;j++)
    {
        for(ll i=1;i<=n;i++)
        {
            bin_anc[i][j].par=bin_anc[bin_anc[i][j-1].par][j-1].par;
            bin_anc[i][j].minv=min(bin_anc[i][j-1].minv,bin_anc[bin_anc[i][j-1].par][j-1].minv);
            bin_anc[i][j].maxv=max(bin_anc[i][j-1].maxv,bin_anc[bin_anc[i][j-1].par][j-1].maxv);
        }
    }
}
ll base2(ll n)
{
    ll k=1,dem=0;
    while(k*2<=n)
    {
        k*=2;
        dem++;
    }
    return dem;
}
dpar ancestor(ll u,ll k)
{
    dpar res;
    for(ll i=17;i>=0;i--)
    {
        if(k>=(1<<i))
        {
            res.maxv=max(res.maxv,bin_anc[u][i].maxv);
            res.minv=min(res.minv,bin_anc[u][i].minv);
            u=bin_anc[u][i].par;
            k-=(1<<i);
        }
    }
    res.par=u;
    return res;
}
dpar lca(ll u,ll v)
{
    dpar res;
    if(h[u]<h[v])
        swap(u,v);
    ll height=h[u]-h[v];
    dpar curr=ancestor(u,height);
    if(curr.par==v)
        return curr;
    u=curr.par;
    res.minv=curr.minv;
    res.maxv=curr.maxv;
    ll maxh_2=base2(h[u]);
    for(ll i=maxh_2;i>=0;i--)
    {
        if(bin_anc[u][i].par!=bin_anc[v][i].par)
        {
            res.minv=min({res.minv,bin_anc[u][i].minv,bin_anc[v][i].minv});
            res.maxv=max({res.maxv,bin_anc[u][i].maxv,bin_anc[v][i].maxv});
            u=bin_anc[u][i].par;
            v=bin_anc[v][i].par;
        }
    }
    res.minv=min({res.minv,bin_anc[u][0].minv,bin_anc[v][0].minv});
    res.maxv=max({res.maxv,bin_anc[u][0].maxv,bin_anc[v][0].maxv});
    res.par=bin_anc[u][0].par;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen("lca.inp","r"))
    {
        freopen("lca.inp","r",stdin);
        freopen("lca.out","w",stdout);
    }
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        e.push_back({x,y,w,i});
    }
    make_set(n);
    sort(e.begin(),e.end(),cmp);
    for(auto ed:e)
    {
        if(union_set(ed.u,ed.v))
        {

            vt[ed.u].push_back({ed.v,ed.w});
            vt[ed.v].push_back({ed.u,ed.w});
            check[ed.idx]=1;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(h[i]==0)
        {
            p[i]=i;
            h[i]=1;
            bin_anc[i][0].par=i;
            dfs(i);
        }
    }
    pre_lift(n);
    for(auto ed:e)
    {
        if(check[ed.idx])
            continue;
        dpar curr=lca(ed.v,ed.u);
        res=max(curr.maxv+ed.w,res);
    }
    cout<<res;

}
