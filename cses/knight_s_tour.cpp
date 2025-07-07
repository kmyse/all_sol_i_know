#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll check[100005],d[100005],b[100005],sum,lsum=LLONG_MIN,m,i,loop_break,dem;
queue<ll>stk;
const ll MOD=1e9+7;
vector<ll> v[1000005];
vector<ll>res;
ll a[9][9];
ll k1[]={-2,-2,-1,-1,1,1,2,2};
ll k2[]={1,-1,2,-2,2,-2,1,-1};
struct spot
{
    ll idx;
    ll idy;
    ll c;
};
bool cmp(spot x,spot y)
{
    return x.c<y.c;
}
bool checkmove(ll x,ll y)
{
    return((x<=8&&x>=1)&&(y<=8&&y>=1));
}
ll cntmove(ll x,ll y)
{
    ll cnt=0;
    for(ll i=0;i<8;i++)
    {
        ll x0=x+k1[i];
        ll y0=y+k2[i];
        if((checkmove(x0,y0))&&a[x0][y0]==0)
            cnt++;
    }
    return cnt;
}
bool findtour(ll x,ll y,ll m)
{
    a[x][y]=m;
    if(m==64)
        return true;
    vector<spot>v;
    for(ll i=0;i<8;i++)
    {
        ll x0=x+k1[i];
        ll y0=y+k2[i];
        if(checkmove(x0,y0)&&a[x0][y0]==0)
            v.push_back({x0,y0,cntmove(x0,y0)});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto k:v)
    {
        if(findtour(k.idx,k.idy,m+1))
            return true;
    }
    a[x][y]=0;
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen("bfs.inp","r"))
    {
        freopen("bfs.inp","r",stdin);
        freopen("bfs.out","w",stdout);
    }
    ll x,y;
    cin>>y>>x;
    bool z=findtour(x,y,1);
    for(ll i=1;i<=8;i++)
    {
        for(ll j=1;j<=8;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }




}
