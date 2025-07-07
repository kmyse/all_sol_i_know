#pragma GCC optimize ("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll a[1000005],tree1[4000005],tree2[4000005],q,n,i,k,l,r,res=LLONG_MIN;
void update(ll index,ll l,ll r,ll i,ll val)
{
    if(i<l||i>r)
        return;
    if(l==r)
    {
        tree1[index]=val;
        return;
    }
    ll mid=(l+r)/2;
    update(2*index,l,mid,i,val);
    update(2*index+1,mid+1,r,i,val);
    tree1[index]=min(tree1[2*index],tree1[2*index+1]);
}
ll summm1(ll index, ll l, ll r, ll u, ll v)
{
    if(u>r||l>v)
        return LLONG_MAX;
    if(u<=l&&v>=r)
    return tree1[index];
    ll mid=(l+r)/2;
    return min(summm1(index*2,l,mid,u,v),summm1(index*2+1,mid+1,r,u,v));
}
signed main()
{
    if(fopen(".inp","r"))
    {
        freopen(".inp","r",stdin);
        freopen(".out","w",stdout);
    }
    ll u,v;
    cin>>n>>u>>v;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(i=u;i<=n;i++)
    {
        ll k;
        update(1,0,n,i-u,a[i-u]);
        k=summm1(1,0,n,max(0*1LL,i-v),i-u);
        res=max(res,a[i]-k);
    }
    cout<<res;


}
