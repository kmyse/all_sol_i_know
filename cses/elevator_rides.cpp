#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll a[1005];
pii dp[2000005];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(".inp","r"))
    {
        freopen(".inp","r",stdin);
        freopen(".out","w",stdout);
    }
    ll n,i,j,x;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<(1<<n);i++)
    {
        dp[i].fi=n+1;
        dp[i].se=x+1;
    }
    dp[0]={1,0};
    for(i=1;i<(1<<n);i++)
    {
        for(j=0;j<n;j++)
        {
            if (i&(1<<j))
            {
                ll w=dp[i^(1<<j)].se;
                ll cnt=dp[i^(1<<j)].fi;
                if(w+a[j]<=x)
                    w+=a[j];
                else
                {
                    cnt++;
                    w=a[j];
                }
                dp[i]=min(dp[i],{cnt,w});
            }
        }
    }
    cout<<dp[(1<<n)-1].fi;
}
