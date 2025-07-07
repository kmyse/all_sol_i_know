#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll a[1000005],b[1000005],q,n,i,k,l,r;
struct nodes
{
    ll val;
    ll carry;
};
nodes tree[4000005];
void build(ll index,ll l,ll r)
{
    if(l==r)
    {
        tree[index].val=b[l];
        return;
    }
    ll mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    tree[index].val=max(tree[2*index].val,tree[2*index+1].val);

}
void lazy(ll index,ll l,ll r)
{
    if(tree[index].carry != 0)
    {
        tree[index].val+=tree[index].carry;
        if(l!=r)
        {
            tree[2*index].carry+=tree[index].carry;
            tree[2*index+1].carry+=tree[index].carry;
        }
        tree[index].carry=0;
    }


}
void update(ll index,ll l,ll r,ll u,ll v,ll valu)
{
    lazy(index,l,r);
    if(u>r||l>v)
        return;
    if(u<=l&&v>=r)
    {
        tree[index].carry+=valu;
        lazy(index,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update(2*index,l,mid,u,v,valu);
    update(2*index+1,mid+1,r,u,v,valu);
    tree[index].val=max(tree[2*index].val,tree[2*index+1].val);

}
ll summm(ll index, ll l, ll r, ll u, ll v)
{
    lazy(index,l,r);
    if(u>r||l>v)
        return LLONG_MIN;
    if(u<=l&&v>=r)
    return tree[index].val;
    ll mid=(l+r)/2;
    return max(summm(index*2,l,mid,u,v),summm(index*2+1,mid+1,r,u,v));
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
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    b[0]=0;
    build(1,0,n);
    for(ll j=1;j<=q;j++)
    {
        cin>>k>>l>>r;
        if(k==1)
        {
            update(1,0,n,l,n,r-a[l]);
            a[l]=r;
        }
        else
            cout<<summm(1,0,n,l-1,r)-summm(1,0,n,l-1,l-1)<<'\n';
    }
}
