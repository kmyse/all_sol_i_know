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
const pair<pii,ll> INVALID={{-1,-1},0};
ll a[100005],dp[100005];
__int128 xp,yp;
ll ex_euclidean(ll a,ll b,__int128 &x,__int128 &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    __int128 q=a/b,r=a%b,x1=0,y1=0,d=ex_euclidean(b,r,x1,y1);
    x=y1;
    y=x1-q*y1;
    return d;
}
__int128 cdiv(__int128 x,__int128 y)
{
    if(y<0)
    {
        x=-x;
        y=-y;
    }
    if(x>=0)
        return (x+y-1)/y;
    return x/y;
}
__int128 fdiv(__int128 x,__int128 y)
{
    if(y<0)
    {
        x=-x;
        y=-y;
    }
    if(x>=0)
        return x/y;
    return (x-y+1)/y;
}
__int128 minimize(ll a,ll b,ll c,ll g)
{
    if(c%g!=0)
        return -1;
    __int128 x=xp,y=yp;
    x*=(__int128)(c/g);
    y*=(__int128)(c/g);
    __int128 asol=a/g,bsol=b/g;
    //x+k*bsol>=0
    //y-k*asol>=0
    //-x<=k*bsol, k*asol<=y
    //-x/bsol<=k<=y/asol
    __int128 tmin=cdiv(-x,bsol);
    __int128 tmax=fdiv(y,asol);
    if(tmin>tmax)
        return -1;
    return x+bsol*tmin+y-asol*tmin;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen("wpro.inp","r"))
    {
        freopen("wpro.inp","r",stdin);
        freopen("wpro.out","w",stdout);
    }
    ll n,l1,l2,c,d;
    cin>>n>>l1>>l2>>c>>d;
    if(l1>=l2)
        swap(l1,l2);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    ll g=ex_euclidean(l1,l2,xp,yp);
    fill(dp,dp+10005,1000000000000000005);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ll p1=(i-j)*d*1LL;
            ll p2=(ll)minimize(l1,l2,a[i]-a[j-1],g);
            if(p2==-1)
                continue;
            dp[i]=min(dp[i],dp[j-1]+p1+(p2-1)*c);
        }
    }
    cout<<dp[n];

}

