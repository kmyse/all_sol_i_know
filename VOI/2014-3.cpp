#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define getbit(x,i) (((x)>>(i))&1ULL)
#define biton(x,i) ((x)|(1ULL<<(i)))
#define bitoff(x,i) ((x)&(~(1ULL<<(i))))
#define flipbit(x,i) ((x)^(1ULL<<(i)))
#define umpll unordered_map<ll,ll>
#define umpstr unordered_map<string,ll>
#define mppii map<pii,ll>
#define f(i,n,st,k) for(ll i=(st);i<=(n);i+=(k))
#define rf(i,n,st,k) for(ll i=(st);i>=(n);i-=(k))
using namespace std;
struct edge
{
    ll t,fi,se;
};
vector<edge>vt;
ll a[1000001],p[1000001],b[1000005],n,m;
bool check[1000001];
void make_set(ll n)
{
    f(i,n,1,1)
        p[i]=-1;
}
ll find_set(ll x)
{
    if(p[x]<0)
        return x;
    p[x]=find_set(p[x]);
    return p[x];
}
bool union_set(ll a,ll b)
{
    ll a0=find_set(a),b0=find_set(b);
    if(a0!=b0)
    {
        if(p[a0]>p[b0])
            swap(a0,b0);
        p[a0]+=p[b0];
        p[b0]=a0;
        return true;
    }
    return false;
}
void initialize()
{
    vt.clear();
    cin>>n>>m;
    f(i,n-1,1,1)
        cin>>a[i];
    f(i,n-1,1,1)
        cin>>b[i];
    f(i,m,1,1)
    {
        ll t,x,y;
        cin>>x>>y>>t;
        vt.push_back({t,x,y});
    }
    fill(check,check+m+1,0);

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
    ll t;
    cin>>t;
    while(t--)
    {
        initialize();
        make_set(n);
        ll mx1=0,mx2=0,l=0;
        f(i,vt.size()-1,0,1)
            if(vt[i].t==1)
                mx1+=union_set(vt[i].fi,vt[i].se);
        make_set(n);
        f(i,vt.size()-1,0,1)
            if(vt[i].t==2)
                mx2+=union_set(vt[i].fi,vt[i].se);
        ll mi1=n-mx2-1,sum=INT_MAX,cnt=0;
        f(i,min(mx1,n-1),max(mi1,0LL),1)
            if(a[i]+b[n-i-1]<=sum)
            {
                sum=a[i]+b[n-i-1];
                cnt=i;
            }
        f(i,vt.size()-1,0,1)
            if(vt[i].t==1)
                check[i+1]=union_set(vt[i].fi,vt[i].se);
        make_set(n);
        f(i,vt.size()-1,0,1)
            if(check[i+1]&&vt[i].t==1)
                l+=union_set(vt[i].fi,vt[i].se);

        f(i,vt.size()-1,0,1)
            if(!check[i+1]&&l<cnt&&vt[i].t==1)
            {
                check[i+1]=union_set(vt[i].fi,vt[i].se);
                l+=check[i+1];
            }
        f(i,vt.size()-1,0,1)
            if(vt[i].t==2)
                check[i+1]=union_set(vt[i].fi,vt[i].se);
        f(i,m,1,1)
            if(check[i])
                cout<<i<<" ";
        cout<<'\n';
    }
}
