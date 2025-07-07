#include <bits/stdc++.h>
#define ll int64_t
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll n,k,i;
ll a[1000005],m,x,y,j;
ll c[1000005],b[1000005],res;
unordered_map<ll,ll>mp;
stack<ll>st;
multiset<ll>se;
vector<ll>v;
bool check(ll k)
{
    b[1]=k;
    se.clear();
    for(ll i=1;i<=n*(n-1)/2;i++)
        se.insert(a[i]);
    for(ll i=2;i<=n;i++)
    {
        b[i]=*se.begin()-b[1];
        for(ll j=1;j<i;j++)
        {
            if(se.find(b[i]+b[j])==se.end())
                return false;
            se.erase(se.lower_bound(b[i]+b[j]));
        }
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen("KARATE.inp","r"))
    {
        freopen("KARATE.inp","r",stdin);
        freopen("KARATE.out","w",stdout);
    }
    cin>>n;
    m=n*(n-1)/2;
    for(i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1);
    for(i=2;i<=m;i++)
    {
        if((a[1]+a[2]-a[i])%2==0)
        {
            ll k=(a[1]+a[2]-a[i])/2;
            if(k>0&&k<=a[1]/2&&check(k)==true)
            {
                for(j=1;j<=n;j++)
                    cout<<b[j]<<" ";
                return 0;
            }
        }
    }


}
