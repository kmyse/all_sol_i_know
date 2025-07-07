#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll num[100005],low[100005],n,p[100005],root[100005],a[100005],sz[1000005];
ll cnt=0;
vector<ll>v[1000005];
void dfs(ll k)
{
    cnt++;
    num[k]=cnt;
    low[k]=cnt;
    sz[k]=1;
    for(auto t:v[k])
    {
        if(t==p[k])
            continue;
        else if(num[t])
            low[k]=min(low[k],num[t]);
        else
        {
            p[t]=k;
            dfs(t);
            low[k]=min(low[k],low[t]);
            sz[k]+=sz[t];
        }
    }
}
ll cntbridge()
{
    ll cntb=0;
    for(ll i=1;i<=n;i++)
        cntb+=(p[i]>0&&low[i]>=num[i]);
    return cntb;
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
    ll m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll dem=0;
    for(ll i=1;i<=n;i++)
        if(num[i]==0)
        {
            dfs(i);
            dem++;
            root[dem]=i;
        }
    if(dem>2)
        cout<<0;
    else if(dem==2)
    {
        ll k0=cntbridge();
        cout<<(sz[root[1]]*sz[root[2]])*(m-k0);
    }
    else
    {
        ll res=0;
        for(ll i=1;i<=n;i++)
            if(low[i]>=num[i]&&p[i]>0)
            res+=sz[i]*(n-sz[i])-1;
        cout<<res+((n*(n-1)>>1)-m)*(m-cntbridge());
    }

}
