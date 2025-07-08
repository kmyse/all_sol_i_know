#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll v[1000005];
deque<ll>dq;
ll check[1000005],res[1000005],cnt;
void dfs(ll k)
{
    dq.push_back(k);
    if(check[k]==1)
    {
        cnt+=res[k];
        return;
    }
    check[k]=1;
    cnt++;
    dfs(v[k]);
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
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    for(ll i=1;i<=n;i++)
    {
        if(check[i]==0)
        {
            cnt=0;
            dfs(i);
            ll j=1;
            while(!dq.empty())
            {
                if(dq.front()==dq.back())
                    j=0;
                res[dq.front()]=cnt;
                cnt-=j;
                dq.pop_front();
            }
        }
    }
    for(ll i=1;i<=n;i++)
        cout<<res[i]<<" ";


}
